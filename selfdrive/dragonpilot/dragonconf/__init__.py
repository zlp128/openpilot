#!/usr/bin/env python2.7
import os
import json

file = '/data/dragonpilot.json'


default_conf = {
  'DragonEnableDashcam': '1',
  'DragonDisableDriverSafetyCheck': '1',
  'DragonAutoShutdownAt': '30', # in minute
  'DragonTempDisableSteerOnSignal': '0',
}

def write_json_config(config):
  with open(file, 'w') as f:
    json.dump(config, f, indent=2, sort_keys=True)
  os.chmod(file, 0644)

def dragonpilot_set_params(params):
  # create new json file
  if not os.path.isfile(file):
    write_json_config(default_conf)
    config = default_conf
  else:
    # load from json
    with open(file, 'r') as f:
      config = json.load(f)

    json_update_needed = False
    # add new keys
    for key, val in default_conf.items():
      if key not in config:
        json_update_needed = True
        config[key] = val

    # remove invalid keys
    for key, val in config.items():
      if key not in default_conf:
        json_update_needed = True
        config.pop(key, None)

    # write to json if update needed
    if json_update_needed:
      write_json_config(config)

  # set params
  for key, val in config.items():
    if params.get(key) is None:
      params.put(key, str(val))
