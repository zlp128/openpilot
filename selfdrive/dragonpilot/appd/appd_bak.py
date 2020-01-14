#!/usr/bin/env python3
import time
import subprocess
import cereal
import cereal.messaging as messaging
ThermalStatus = cereal.log.ThermalData.ThermalStatus
from selfdrive.swaglog import cloudlog
from common.params import Params, put_nonblocking
params = Params()

class App():

  # app type
  TYPE_GPS = 0
  TYPE_SERVICE = 1
  TYPE_FULLSCREEN = 2
  TYPE_UTIL = 3

  # frame app
  FRAME = "ai.comma.plus.frame"
  FRAME_MAIN = ".MainActivity"

  # offroad app
  OFFROAD = "ai.comma.plus.offroad"
  OFFROAD_MAIN = ".MainActivity"

  # manual switch stats
  MANUAL_OFF = "-1"
  MANUAL_IDLE = "0"
  MANUAL_ON = "1"

  def appops_set(self, package, op, mode):
    self.system(f"LD_LIBRARY_PATH= appops set {package} {op} {mode}")

  def pm_grant(self, package, permission):
    self.system(f"pm grant {package} {permission}")

  def set_package_permissions(self):
    if self.permissions is not None:
      for permission in self.permissions:
        self.pm_grant(self.app, permission)
    if self.opts is not None:
      for opt in self.opts:
        self.appops_set(self.app, opt, "allow")

  def __init__(self, app, activity, enable_param, auto_run_param, manual_ctrl_param, app_type, permissions, opts):
    self.app = app
    # main activity
    self.activity = activity
    # read enable param
    self.enable_param = enable_param
    # read auto run param
    self.auto_run_param = auto_run_param
    # read manual run param
    self.manual_ctrl_param = manual_ctrl_param
    # if it's a service app, we do not kill if device is too hot
    # if it's a full screen app, we need to do extra process on frame/offroad
    self.app_type = app_type

    self.permissions = permissions
    self.opts = opts

    self.is_enabled = False
    self.last_is_enabled = False
    self.is_auto_runnable = False
    self.is_running = False
    self.manual_ctrl_status = self.MANUAL_IDLE
    self.manually_ctrled = False

    self.set_package_permissions()
    self.system(f"pm disable %s" % self.app)

  def read_params(self):
    self.last_is_enabled = self.is_enabled
    if self.enable_param is None:
      self.is_enabled = False
    else:
      self.is_enabled = True if params.get(self.enable_param, encoding='utf8') == "1" else False

    if self.is_enabled:
      # a service app should run automatically and not manual controllable.
      if self.app_type == App.TYPE_SERVICE:
        self.is_auto_runnable = True
        self.manual_ctrl_status = self.MANUAL_IDLE
      else:
        if self.manual_ctrl_param is None:
          self.manual_ctrl_status = self.MANUAL_IDLE
        else:
          self.manual_ctrl_status = params.get(self.manual_ctrl_param, encoding='utf8')

        if self.auto_run_param is None:
          self.is_auto_runnable = False
        else:
          self.is_auto_runnable = True if params.get(self.auto_run_param, encoding='utf8') == "1" else False
    else:
      self.is_auto_runnable = False
      self.manual_ctrl_status = self.MANUAL_IDLE
      self.manually_ctrled = False

  def run(self):
    if self.is_enabled:
      # app is manually ctrl, we record that
      if self.manual_ctrl_param is not None and self.manual_ctrl_status == self.MANUAL_ON:
        put_nonblocking(self.manual_ctrl_param, '0')
        self.manually_ctrled = True
        self.is_running = False

      # only run app if it's not running
      if not self.is_running:
        # if it's a full screen app, we need to stop frame and offroad to get keyboard access
        if self.app_type == self.TYPE_FULLSCREEN:
          self.system(f"pm disable %s" % self.FRAME)
          self.system(f"am start -n %s/%s" % (self.OFFROAD, self.OFFROAD_MAIN))

        self.system(f"pm enable %s" % self.app)

        if self.app_type == self.TYPE_SERVICE:
          self.system(f"am startservice %s/%s" % (self.app, self.activity))
        else:
          self.system(f"am start -n %s/%s" % (self.app, self.activity))

        self.is_running = True

  def kill(self):
    if self.is_enabled:
      # app is manually ctrl, we record that
      if self.manual_ctrl_param is not None and self.manual_ctrl_status == self.MANUAL_OFF:
        put_nonblocking(self.manual_ctrl_param, '0')
        self.manually_ctrled = True
        self.is_running = True

      # only kill app if it's running
      if self.is_running:
        # if it's a full screen app, we need to restart offroad and frame
        if self.app_type == self.TYPE_FULLSCREEN:
          self.system(f"pm disable %s" % self.OFFROAD)
          self.system(f"pm enable %s" % self.OFFROAD)
          self.system(f"pm enable %s" % self.FRAME)
          self.system(f"am start -n %s/%s" % (self.FRAME, self.FRAME_MAIN))

        self.system(f"pm disable %s" % self.app)
        self.is_running = False

  def system(self, cmd):
    try:
      # cloudlog.info("running %s" % cmd)
      print(cmd)
      subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
    except subprocess.CalledProcessError as e:
      cloudlog.event("running failed",
                     cmd=e.cmd,
                     output=e.output[-1024:],
                     returncode=e.returncode)

def init_apps(apps):
  apps.append(App(
    # v1.16.2
    "com.tomtom.speedcams.android.map",
    "com.tomtom.speedcams.android.activities.SpeedCamActivity",
    "DragonEnableTomTom",
    "DragonBootTomTom",
    "DragonRunTomTom",
    App.TYPE_GPS,
    [
      "android.permission.ACCESS_FINE_LOCATION",
      "android.permission.ACCESS_COARSE_LOCATION",
      "android.permission.READ_EXTERNAL_STORAGE",
      "android.permission.WRITE_EXTERNAL_STORAGE",
    ],
    [
      "SYSTEM_ALERT_WINDOW",
    ]
  ))
  apps.append(App(
    # v4.3.0.600310 R2098NSLAE
    "com.autonavi.amapauto",
    "com.autonavi.amapauto.MainMapActivity",
    "DragonEnableAutonavi",
    "DragonBootAutonavi",
    "DragonRunAutonavi",
    App.TYPE_GPS,
    [
      "android.permission.ACCESS_FINE_LOCATION",
      "android.permission.ACCESS_COARSE_LOCATION",
      "android.permission.READ_EXTERNAL_STORAGE",
      "android.permission.WRITE_EXTERNAL_STORAGE",
    ],
    [
      "SYSTEM_ALERT_WINDOW",
    ]
  ))
  apps.append(App(
    # v6.40.3
    "com.mixplorer",
    "com.mixplorer.activities.BrowseActivity",
    "DragonEnableMixplorer",
    None,
    "DragonRunMixplorer",
    App.TYPE_UTIL,
    [
      "android.permission.READ_EXTERNAL_STORAGE",
      "android.permission.WRITE_EXTERNAL_STORAGE",
    ],
    [],
  ))
  apps.append(App(
    # v2.9.5 build 74
    "tw.com.ainvest.outpack",
    "tw.com.ainvest.outpack.ui.MainActivity",
    "DragonEnableAegis",
    "DragonBootAegis",
    "DragonRunAegis",
    App.TYPE_GPS,
    [
      "android.permission.ACCESS_FINE_LOCATION",
      "android.permission.READ_EXTERNAL_STORAGE",
      "android.permission.WRITE_EXTERNAL_STORAGE",
    ],
    [
      "SYSTEM_ALERT_WINDOW",
    ]
  ))
  apps.append(App(
    "cn.dragonpilot.gpsservice",
    "cn.dragonpilot.gpsservice.MainService",
    "DragonGreyPandaMode",
    None,
    None,
    App.TYPE_SERVICE,
    [],
    [],
  ))
  apps.append(App(
    # v4.57.2.0
    "com.waze",
    "com.waze.MainActivity",
    "DragonWazeMode",
    None,
    "DragonRunWaze",
    App.TYPE_FULLSCREEN,
    [
      "android.permission.ACCESS_FINE_LOCATION",
      "android.permission.ACCESS_COARSE_LOCATION",
      "android.permission.READ_EXTERNAL_STORAGE",
      "android.permission.WRITE_EXTERNAL_STORAGE",
      "android.permission.RECORD_AUDIO",
    ],
    [],
  ))

def main():
  # has_enabled_apps = False
  has_fullscreen_apps = False
  has_auto_run_apps = False
  apps = []

  init_apps(apps)

  last_started = False
  thermal_sock = messaging.sub_sock('thermal')
  allow_auto_run = True

  frame = 0
  start_delay = None
  stop_delay = None


  while 1: #has_enabled_apps:
    msg = messaging.recv_sock(thermal_sock, wait=True)
    started = msg.thermal.started

    for app in apps:
      # read params loop
      app.read_params()
      if app.is_enabled:
        if app.app_type == App.TYPE_FULLSCREEN:
          has_fullscreen_apps = True
        if app.is_auto_runnable:
          has_auto_run_apps = True
        if app.manual_ctrl_status != App.MANUAL_IDLE:
          if app.manual_ctrl_status == App.MANUAL_ON:
            app.run()
          else:
            app.kill()

    # when car is running
    if started:
      stop_delay = None
      if start_delay is None:
        start_delay = frame + 5

      # start service and fullscreen apps and kill the reset
      if has_fullscreen_apps:
        for app in apps:
          if not app.manually_ctrled and app.app_type in [App.TYPE_SERVICE, App.TYPE_FULLSCREEN]:
            app.run()
          else:
            app.kill()
      else:
        # kill any util apps
        for app in apps:
          if app.app_type == App.TYPE_UTIL:
            app.kill()

        # auto run ctrl for normal apps
        if has_auto_run_apps:
          thermal_status = msg.thermal.thermalStatus
          if not allow_auto_run and thermal_status <= ThermalStatus.yellow:
            allow_auto_run = True

          if allow_auto_run and thermal_status >= ThermalStatus.red:
            allow_auto_run = False

          if frame > start_delay:
            for app in apps:
              if app.is_auto_runnable and not app.manually_ctrled:
                if allow_auto_run:
                  if not app.is_running and app.app_type not in [App.TYPE_FULLSCREEN, App.TYPE_UTIL]:
                    app.run()
                else:
                  if app.is_running and app.app_type not in [App.TYPE_SERVICE]:
                    app.kill()

    # when car is stopped
    else:
      start_delay = None
      # set delay to 30 seconds
      if stop_delay is None:
        stop_delay = frame + 30

      # when car is off, we want to kill full screen app first
      if has_fullscreen_apps:
        for app in apps:
          if not app.manually_ctrled and app.is_running:
            app.kill()
      else:
        # kill rest of the apps after delay
        if frame > stop_delay:
          for app in apps:
            if not app.manually_ctrled and app.is_running:
              app.kill()

    if last_started != started:
      for app in apps:
        app.manually_ctrled = False

    last_started = started
    frame += 3
    time.sleep(3)

if __name__ == "__main__":
  main()

