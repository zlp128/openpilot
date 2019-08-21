#!/usr/bin/env python2.7

import os
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

  params.put('DragonRunTomTom', '0')
  params.put('DragonRunAutonavi', '0')
  params.put('DragonRunMixplorer', '0')

  # we want to disable all app when boot
  system("pm disable %s" % tomtom)
  system("pm disable %s" % autonavi)
  system("pm disable %s" % mixplorer)

  thermal_sock = messaging.sub_sock(service_list['thermal'].port)

  while 1:
    msg = messaging.recv_sock(thermal_sock, wait=True)

    # allow user to manually start/stop app
    if dragon_enable_tomtom:
      tomtom_is_running = execApp(params.get('DragonRunTomTom'), tomtom, tomtom_main, 'DragonRunTomTom')

    if dragon_enable_autonavi:
      autonavi_is_running = execApp(params.get('DragonRunAutonavi'), autonavi, autonavi_main, 'DragonRunAutonavi')

    if dragon_enable_mixplorer:
      mixplorer_is_running = execApp(params.get('DragonRunMixplorer'), mixplorer, mixplorer_main, 'DragonRunMixplorer')

    auto_tomtom = dragon_enable_tomtom and dragon_boot_tomtom
    auto_autonavi = dragon_enable_autonavi and dragon_boot_autonavi
    # car on
    if msg.thermal.started:
      if msg.thermal.thermalStatus < ThermalStatus.yellow and not allow_auto_boot:
        allow_auto_boot = True
      # do not allow tomtom / autonavi when it's hot
      if allow_auto_boot:
        if msg.thermal.thermalStatus < ThermalStatus.red:
          if auto_tomtom and not tomtom_is_running:
            tomtom_is_running = execApp('1', tomtom, tomtom_main, 'DragonRunTomTom')
          if auto_autonavi and not autonavi_is_running:
            autonavi_is_running = execApp('1', autonavi, autonavi_main, 'DragonRunAutonavi')
        else:
          allow_auto_boot = False

      # kill mixplorer when car started
      if mixplorer_is_running:
        mixplorer_is_running = execApp('-1', mixplorer, mixplorer_main, 'DragonRunMixplorer')

    # car off
    else:
      if auto_tomtom and tomtom_is_running:
        tomtom_is_running = execApp('-1', tomtom, tomtom_main, 'DragonRunTomTom')
      if auto_autonavi and autonavi_is_running:
        autonavi_is_running = execApp('-1', autonavi, autonavi_main, 'DragonRunAutonavi')

    # every 3 seconds, we re-check status
    time.sleep(3)

def execApp(status, app, app_main, param):
  if status == "1":
    system("pm enable %s" % app)
    system("am start -n %s/%s" % (app, app_main))
    params.put(param, '0')
    return True
  if status == "-1":
    system("pm disable %s" % app)
    params.put(param, '0')
    return False


def system(cmd):
  try:
    cloudlog.info("running %s" % cmd)
    subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
  except subprocess.CalledProcessError as e:
    cloudlog.event("running failed",
                   cmd=e.cmd,
                   output=e.output[-1024:],
                   returncode=e.returncode)

if __name__ == "__main__":
  main()