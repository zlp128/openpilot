#!/usr/bin/env python2.7

import os
import time
from selfdrive.dragonpilot.dragonconf.dragonconf import dragonconf
dragonconf = dragonconf()

def main(gctx=None):

  shutdown_count = 0

  while 1:
    with open("/sys/class/power_supply/usb/present") as f:
      usb_online = bool(int(f.read()))

    if not usb_online:
      shutdown_count += 1
    else:
      shutdown_count = 0

    if shutdown_count >= dragonconf.conf["autoShutdownAt"] > 0:
      os.system('LD_LIBRARY_PATH="" svc power shutdown')

    time.sleep(1)

if __name__ == "__main__":
  main()