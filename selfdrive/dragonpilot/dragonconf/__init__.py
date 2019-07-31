#!/usr/bin/env python2.7
import os
from common.params import Params
# import json

# file = '/data/dragonpilot.json'


default_conf = {
  'DragonEnableDashcam': '1',
  'DragonDisableDriverSafetyCheck': '0', # deprecated
  'DragonEnableDriverSafetyCheck': '1',
  'DragonAutoShutdownAt': '30', # in minute
  'DragonTempDisableSteerOnSignal': '0', # deprecated
  'DragonEnableSteeringOnSignal': '0',
  'DragonDisableLogger': '0', # deprecated
  'DragonEnableLogger': '1',
  'DragonDisableUploader': '0', # deprecated
  'DragonEnableUploader': '1',
  'DragonNoctuaMode': '0',
  'DragonCacheCar': '1', # deprecated
  'DragonCachedModel': '', # for cache car # deprecated
  'DragonCachedFP': '', # for cache car # deprecated
  'DragonCachedVIN': '', # for cache car # deprecated
  'DragonAllowGas': '0',
  'DragonBBUI': '0',
  'DragonToyotaStockDSU': '0',
}

deprecated_conf = {
  'DragonDisableDriverSafetyCheck': 'DragonEnableDriverSafetyCheck',
  'DragonTempDisableSteerOnSignal': 'DragonEnableSteeringOnSignal',
  'DragonDisableLogger': 'DragonEnableLogger',
  'DragonDisableUploader': 'DragonEnableUploader',
  'DragonCacheCar': None,
  'DragonCachedModel': None,
  'DragonCachedFP': None,
  'DragonCachedVIN': None,
}

deprecated_conf_invert = {
  'DragonDisableDriverSafetyCheck': True,
  'DragonTempDisableSteerOnSignal': False,
  'DragonDisableLogger': True,
  'DragonDisableUploader': True,
}

def dragonpilot_set_params(params):
  # remove deprecated params
  for old, new in deprecated_conf.items():
    if params.get(old) is not None:
      if new is not None:
        old_val = str(params.get(old))
        new_val = old_val
        # invert the value if true
        if old in deprecated_conf_invert and deprecated_conf_invert[old] is True:
          new_val = "1" if old_val == "0" else "0"
        params.put(new, new_val)
      params.delete(old)

  # set params
  for key, val in default_conf.items():
    if params.get(key) is None and key not in deprecated_conf:
      params.put(key, str(val))

if __name__ == "__main__":
  params = Params()
  params.manager_start()

  dragonpilot_set_params(params)