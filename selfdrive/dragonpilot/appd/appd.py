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
  tomtom_enabled = False
  autonavi_enabled = False
  mixplorer_enabled = False

  params.put('DragonRunTomTom', '0')
  params.put('DragonRunAutonavi', '0')
  params.put('DragonRunMixplorer', '0')

  # make sure packages are enabled/disabled
  if dragon_enable_tomtom == "1":
    system("pm enable %s" % tomtom)
  else:
    system("pm disable %s" % tomtom)

  if dragon_enable_autonavi == "1":
    system("pm enable %s" % autonavi)
  else:
    system("pm disable %s" % autonavi)

  if dragon_enable_mixplorer == "1":
    system("pm enable %s" % mixplorer)
  else:
    system("pm disable %s" % mixplorer)

  thermal_sock = messaging.sub_sock(service_list['thermal'].port)

  while 1:
    msg = messaging.recv_sock(thermal_sock, wait=True)
    dragon_run_tomtom = params.get('DragonRunTomTom')
    dragon_run_autonavi = params.get('DragonRunAutonavi')
    dragon_run_mixplorer = params.get('DragonRunMixplorer')

    if dragon_enable_tomtom:
      if dragon_run_tomtom == "1":
        system("pm enable %s" % tomtom)
        system("am start -n %s/%s" % (tomtom, tomtom_main))
        params.put('DragonRunTomTom', '0')
        tomtom_enabled = True
      elif dragon_run_tomtom == "-1":
        system("pm disable %s" % tomtom)
        system("pm enable %s" % tomtom)
        params.put('DragonRunTomTom', '0')
        tomtom_enabled = False

    if dragon_enable_autonavi:
      if dragon_run_autonavi == "1":
        system("pm enable %s" % autonavi)
        system("am start -n %s/%s" % (autonavi, autonavi_main))
        params.put('DragonRunAutonavi', '0')
        autonavi_enabled = True
      elif dragon_run_autonavi == "-1":
        system("pm disable %s" % autonavi)
        params.put('DragonRunAutonavi', '0')
        autonavi_enabled = False

    if dragon_enable_mixplorer:
      if dragon_run_mixplorer == "1":
        system("pm enable %s" % mixplorer)
        system("am start -n %s/%s" % (mixplorer, mixplorer_main))
        params.put('DragonRunMixplorer', '0')
        mixplorer_enabled = True
      elif dragon_run_mixplorer == "-1":
        system("pm disable %s" % mixplorer)
        params.put('DragonRunMixplorer', '0')
        mixplorer_enabled = False

    # car on
    if msg.thermal.started:
      # dragonpilot, handle tomtom/autonavi
      # do not allow tomtom / autonavi when it's hot
      if msg.thermal.thermalStatus < ThermalStatus.red:
        if dragon_boot_tomtom and not tomtom_enabled:
          system("pm enable %s" % tomtom)
          system("am start -n %s/%s" % (tomtom, tomtom_main))
          tomtom_enabled = True
        if dragon_boot_autonavi and not autonavi_enabled:
          system("pm enable %s" % autonavi)
          system("am start -n %s/%s" % (autonavi, autonavi_main))
          autonavi_enabled = True

      # kill mixplorer when car started
      if mixplorer_enabled:
        system("pm disable %s" % mixplorer)
        mixplorer_enabled = False

    # car off
    else:
      if dragon_boot_tomtom and tomtom_enabled:
        system("pm disable %s" % tomtom)
        tomtom_enabled = False
      if dragon_boot_autonavi and autonavi_enabled:
        system("pm disable %s" % autonavi)
        autonavi_enabled = False

    # every 3 seconds, we re-check status
    time.sleep(3)

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