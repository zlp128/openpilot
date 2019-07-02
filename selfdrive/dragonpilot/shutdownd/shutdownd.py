#!/usr/bin/env python2.7

import os
import time
from common.params import Params
params = Params()

def main(gctx=None):

  shutdown_count = 0
  autoShutdownAt = get_shutdown_val()

  while 1:
    with open("/sys/class/power_supply/usb/present") as f:
      usb_online = bool(int(f.read()))

    if not usb_online:
      shutdown_count += 1
    else:
      shutdown_count = 0

    if autoShutdownAt is None:
      autoShutdownAt = get_shutdown_val()
    else:
      if shutdown_count >= autoShutdownAt > 0:
        os.system('LD_LIBRARY_PATH="" svc power shutdown')

    time.sleep(1)

def get_shutdown_val():
  val = params.get("DragonAutoShutdownAt")
  if val is None:
    return None
  else:
    return int(val)*60 # convert to seconds


if __name__ == "__main__":
  main()