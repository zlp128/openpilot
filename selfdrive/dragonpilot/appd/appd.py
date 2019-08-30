#!/usr/bin/env python2.7

import time
import selfdrive.messaging as messaging
from selfdrive.services import service_list
import subprocess
import cereal
ThermalStatus = cereal.log.ThermalData.ThermalStatus
from selfdrive.swaglog import cloudlog
from common.params import Params
params = Params()

# v1.16.2
tomtom = "com.tomtom.speedcams.android.map"
tomtom_main = "com.tomtom.speedcams.android.activities.SpeedCamActivity"

# v4.1.0.20047
autonavi = "com.autonavi.amapauto"
autonavi_main = "com.autonavi.amapauto.MainMapActivity"

# v6.39.2
mixplorer = "com.mixplorer"
mixplorer_main = "com.mixplorer.activities.BrowseActivity"

def main(gctx=None):

  dragon_enable_tomtom = False if params.get('DragonEnableTomTom') == "0" else True
  dragon_enable_autonavi = False if params.get('DragonEnableAutonavi') == "0" else True
  dragon_enable_mixplorer = False if params.get('DragonEnableMixplorer') == "0" else True
  dragon_boot_tomtom = False if params.get("DragonBootTomTom") == "0" else True
  dragon_boot_autonavi = False if params.get("DragonBootAutonavi") == "0" else True
  tomtom_is_running = False
  autonavi_is_running = False
  mixplorer_is_running = False
  allow_auto_boot = True
  manual_tomtom = False
  manual_autonavi = False
  last_started = False

  params.put('DragonRunTomTom', '0')
  params.put('DragonRunAutonavi', '0')
  params.put('DragonRunMixplorer', '0')

  # we want to disable all app when boot
  system("pm disable %s ; pm disable %s ; pm disable %s" % (tomtom, autonavi, mixplorer))

  thermal_sock = messaging.sub_sock(service_list['thermal'].port)

  while dragon_enable_tomtom or dragon_enable_autonavi or dragon_enable_mixplorer:

    # allow user to manually start/stop app
    if dragon_enable_tomtom:
      status = params.get('DragonRunTomTom')
      if not status == "0":
        tomtom_is_running = execApp(status, tomtom, tomtom_main)
        params.put('DragonRunTomTom', '0')
        manual_tomtom = status != "0"

    if dragon_enable_autonavi:
      status = params.get('DragonRunAutonavi')
      if not status == "0":
        autonavi_is_running = execApp(status, autonavi, autonavi_main)
        params.put('DragonRunAutonavi', '0')
        manual_autonavi = status != "0"

    if dragon_enable_mixplorer:
      status = params.get('DragonRunMixplorer')
      if not status == "0":
        mixplorer_is_running = execApp(status, mixplorer, mixplorer_main)
        params.put('DragonRunMixplorer', '0')

    # if manual control is set, we do not allow any of the auto actions
    auto_tomtom = not manual_tomtom and dragon_enable_tomtom and dragon_boot_tomtom
    auto_autonavi = not manual_autonavi and dragon_enable_autonavi and dragon_boot_autonavi

    msg = messaging.recv_sock(thermal_sock, wait=True)
    started = msg.thermal.started
    # car on
    if started:
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
          if auto_tomtom and not tomtom_is_running:
            tomtom_is_running = execApp('1', tomtom, tomtom_main)
          if auto_autonavi and not autonavi_is_running:
            autonavi_is_running = execApp('1', autonavi, autonavi_main)
        else:
          if auto_tomtom and tomtom_is_running:
            tomtom_is_running = execApp('-1', tomtom, tomtom_main)
          if auto_autonavi and autonavi_is_running:
            autonavi_is_running = execApp('-1', autonavi, autonavi_main)
          # set allow_auto_boot to False once the thermal status is >= red
          allow_auto_boot = False

      # kill mixplorer when car started
      if mixplorer_is_running:
        mixplorer_is_running = execApp('-1', mixplorer, mixplorer_main)

    # car off
    else:
      if auto_tomtom and tomtom_is_running:
        tomtom_is_running = execApp('-1', tomtom, tomtom_main)
      if auto_autonavi and autonavi_is_running:
        autonavi_is_running = execApp('-1', autonavi, autonavi_main)

    # if car state changed, we remove manual control state
    if not last_started == started:
      manual_tomtom = False
      manual_autonavi = False

    last_started = started
    # every 3 seconds, we re-check status
    time.sleep(3)

def execApp(status, app, app_main):
  if status == "1":
    system("pm enable %s && am start -n %s/%s" % (app, app, app_main))
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