#!/usr/bin/env python3

import time
import cereal.messaging as messaging
import subprocess
import cereal
ThermalStatus = cereal.log.ThermalData.ThermalStatus
from selfdrive.swaglog import cloudlog
from common.params import Params, put_nonblocking
params = Params()

# v1.16.2
tomtom = "com.tomtom.speedcams.android.map"
tomtom_main = "com.tomtom.speedcams.android.activities.SpeedCamActivity"

# v4.3.0.600310 R2098NSLAE
autonavi = "com.autonavi.amapauto"
autonavi_main = "com.autonavi.amapauto.MainMapActivity"

# v6.40.3
mixplorer = "com.mixplorer"
mixplorer_main = "com.mixplorer.activities.BrowseActivity"

gpsservice = "cn.dragonpilot.gpsservice"
gpsservice_main = "cn.dragonpilot.gpsservice.MainService"

# v2.9.5 build 74
aegis = "tw.com.ainvest.outpack"
aegis_main = "tw.com.ainvest.outpack.ui.MainActivity"

# v4.57.2.0
waze = "com.waze"
waze_main = "com.waze.MainActivity"

frame = "ai.comma.plus.frame"
frame_main = ".MainActivity"

offroad = "ai.comma.plus.offroad"
offroad_main = ".MainActivity"

def main(gctx=None):

  dragon_enable_tomtom = True if params.get('DragonEnableTomTom', encoding='utf8') == "1" else False
  dragon_enable_autonavi = True if params.get('DragonEnableAutonavi', encoding='utf8') == "1" else False
  dragon_enable_aegis = True if params.get('DragonEnableAegis', encoding='utf8') == "1" else False
  dragon_enable_mixplorer = True if params.get('DragonEnableMixplorer', encoding='utf8') == "1" else False
  dragon_boot_tomtom = True if params.get("DragonBootTomTom", encoding='utf8') == "1" else False
  dragon_boot_autonavi = True if params.get("DragonBootAutonavi", encoding='utf8') == "1" else False
  dragon_boot_aegis = True if params.get("DragonBootAegis", encoding='utf8') == "1" else False
  dragon_greypanda_mode = True if params.get("DragonGreyPandaMode", encoding='utf8') == "1" else False
  dragon_waze_mode = True if params.get("DragonWazeMode", encoding='utf8') == "1" else False
  if dragon_waze_mode:
    dragon_enable_tomtom = False
    dragon_enable_autonavi = False
    dragon_enable_aegis = False

  dragon_grepanda_mode_started = False
  tomtom_is_running = False
  autonavi_is_running = False
  aegis_is_running = False
  mixplorer_is_running = False
  waze_is_running = False
  allow_auto_boot = True
  manual_tomtom = False
  manual_autonavi = False
  manual_aegis = False
  manual_waze = False
  last_started = False
  frame = 0
  start_delay = None
  stop_delay = None

  put_nonblocking('DragonRunTomTom', '0')
  put_nonblocking('DragonRunAutonavi', '0')
  put_nonblocking('DragonRunMixplorer', '0')
  put_nonblocking('DragonRunAegis', '0')
  put_nonblocking('DragonRunWaze', '0')

  # we want to disable all app when boot
  system("pm disable %s" % tomtom)
  system("pm disable %s" % autonavi)
  system("pm disable %s" % mixplorer)
  system("pm disable %s" % gpsservice)
  system("pm disable %s" % aegis)
  system("pm disable %s" % waze)

  thermal_sock = messaging.sub_sock('thermal')

  while dragon_enable_tomtom or dragon_enable_autonavi or dragon_enable_aegis or dragon_enable_mixplorer or dragon_greypanda_mode or dragon_waze_mode:

    # allow user to manually start/stop app
    if dragon_enable_tomtom:
      status = params.get('DragonRunTomTom', encoding='utf8')
      if not status == "0":
        tomtom_is_running = exec_app(status, tomtom, tomtom_main)
        put_nonblocking('DragonRunTomTom', '0')
        manual_tomtom = status != "0"

    if dragon_enable_autonavi:
      status = params.get('DragonRunAutonavi', encoding='utf8')
      if not status == "0":
        autonavi_is_running = exec_app(status, autonavi, autonavi_main)
        put_nonblocking('DragonRunAutonavi', '0')
        manual_autonavi = status != "0"

    if dragon_enable_aegis:
      status = params.get('DragonRunAegis', encoding='utf8')
      if not status == "0":
        aegis_is_running = exec_app(status, aegis, aegis_main)
        put_nonblocking('DragonRunAegis', '0')
        manual_aegis = status != "0"

    if dragon_enable_mixplorer:
      status = params.get('DragonRunMixplorer', encoding='utf8')
      if not status == "0":
        mixplorer_is_running = exec_app(status, mixplorer, mixplorer_main)
        put_nonblocking('DragonRunMixplorer', '0')

    if dragon_waze_mode:
      status = params.get('DragonRunWaze', encoding='utf8')
      if not status == "0":
        if status == "1":
          start_waze_prep()
        elif status == "-1":
          stop_waze_prep()
        waze_is_running = exec_app(status, waze, waze_main)
        put_nonblocking('DragonRunWaze', '0')
        manual_waze = status != "0"

    # if manual control is set, we do not allow any of the auto actions
    auto_tomtom = not manual_tomtom and dragon_enable_tomtom and dragon_boot_tomtom
    auto_autonavi = not manual_autonavi and dragon_enable_autonavi and dragon_boot_autonavi
    auto_aegis = not manual_aegis and dragon_enable_aegis and dragon_boot_aegis

    msg = messaging.recv_sock(thermal_sock, wait=True)
    started = msg.thermal.started
    # car on
    if started:
      stop_delay = None
      if start_delay is None:
        start_delay = frame + 3

      if dragon_greypanda_mode and not dragon_grepanda_mode_started:
        dragon_grepanda_mode_started = True
        system("pm enable %s" % gpsservice)
        system("am startservice %s/%s" % (gpsservice, gpsservice_main))

      if dragon_waze_mode:
        if not manual_waze and not waze_is_running:
          start_waze_prep()
          waze_is_running = exec_app('1', waze, waze_main)
      else:

        #
        # Logic:
        # if temp reach red, we disable all 3rd party apps.
        # once the temp drop below yellow, we then re-enable them
        #
        # set allow_auto_boot back to True once the thermal status is < yellow
        thermal_status = msg.thermal.thermalStatus
        if not allow_auto_boot and thermal_status < ThermalStatus.yellow:
          allow_auto_boot = True
        if allow_auto_boot:
          # only allow auto boot when thermal status is < red
          if thermal_status < ThermalStatus.red:
            if auto_tomtom and not tomtom_is_running and frame > start_delay:
              tomtom_is_running = exec_app('1', tomtom, tomtom_main)
            if auto_autonavi and not autonavi_is_running and frame > start_delay:
              autonavi_is_running = exec_app('1', autonavi, autonavi_main)
            if auto_aegis and not aegis_is_running and frame > start_delay:
              aegis_is_running = exec_app('1', aegis, aegis_main)
          else:
            if auto_tomtom and tomtom_is_running:
              tomtom_is_running = exec_app('-1', tomtom, tomtom_main)
            if auto_autonavi and autonavi_is_running:
              autonavi_is_running = exec_app('-1', autonavi, autonavi_main)
            if auto_aegis and aegis_is_running:
              aegis_is_running = exec_app('-1', aegis, aegis_main)
            # set allow_auto_boot to False once the thermal status is >= red
            allow_auto_boot = False

      # kill mixplorer when car started
      if mixplorer_is_running:
        mixplorer_is_running = exec_app('-1', mixplorer, mixplorer_main)

    # car off
    else:
      start_delay = None
      if stop_delay is None:
        stop_delay = frame + 30

      if dragon_greypanda_mode and dragon_grepanda_mode_started:
        dragon_grepanda_mode_started = False
        system("pm disable %s" % gpsservice)

      if dragon_waze_mode:
        if not manual_waze and waze_is_running:
          stop_waze_prep()
          waze_is_running = exec_app('-1', waze, waze_main)
      else:
        if auto_tomtom and tomtom_is_running and frame > stop_delay:
          tomtom_is_running = exec_app('-1', tomtom, tomtom_main)
        if auto_autonavi and autonavi_is_running and frame > stop_delay:
          autonavi_is_running = exec_app('-1', autonavi, autonavi_main)
        if auto_aegis and aegis_is_running and frame > stop_delay:
          aegis_is_running = exec_app('-1', aegis, aegis_main)

    # if car state changed, we remove manual control state
    if not last_started == started:
      manual_tomtom = False
      manual_autonavi = False
      manual_aegis = False
      manual_waze = False

    last_started = started
    frame += 3
    # every 3 seconds, we re-check status
    time.sleep(3)

# when starting waze, we want to disable frame
def start_waze_prep():
  system("pm disable %s" % frame)
  system("am start -n %s/%s" % (offroad, offroad_main))

# when stopping waze
# we want to disable offroad first and enable offroad (this way the offroad sits in the background waiting for launch.)
# then we re-enable frame and start frame app (the offroad app will start shortly after)
def stop_waze_prep():
  system("pm disable %s" % offroad)
  system("pm enable %s" % offroad)
  system("pm enable %s" % frame)
  system("am start -n %s/%s" % (frame, frame_main))

def exec_app(status, app, app_main):
  if status == "1":
    system("pm enable %s" % app)
    system("am start -n %s/%s" % (app, app_main))
    return True
  if status == "-1":
    system("pm disable %s" % app)
    return False


def system(cmd):
  try:
    # cloudlog.info("running %s" % cmd)
    subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
  except subprocess.CalledProcessError as e:
    cloudlog.event("running failed",
                   cmd=e.cmd,
                   output=e.output[-1024:],
                   returncode=e.returncode)

if __name__ == "__main__":
  main()
