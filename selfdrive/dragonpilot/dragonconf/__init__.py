#!/usr/bin/env python2.7
# import os
# import json

# file = '/data/dragonpilot.json'


default_conf = {
  'DragonEnableDashcam': '1',
  'DragonDisableDriverSafetyCheck': '0',
  'DragonAutoShutdownAt': '30', # in minute
  'DragonTempDisableSteerOnSignal': '0',
  'DragonDisableLogger': '0',
  'DragonNoctuaMode': '0',
  'DragonCacheCar': '1',
  'DragonCachedModel': '', # for cache car
  'DragonCachedFP': '', # for cache car
  'DragonCachedVIN': '', # for cache car
  'DragonBBUI': '0',
}

def dragonpilot_set_params(params):
  # set params
  for key, val in default_conf.items():
    if params.get(key) is None:
      params.put(key, str(val))
