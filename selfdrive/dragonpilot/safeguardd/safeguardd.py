#!/usr/bin/env python2.7
#
# I had a few incidents where OP suddenly stopped while cruising.
# This script is used to detect such event
#

import os
import subprocess

import zmq
from selfdrive.services import service_list
import selfdrive.messaging as messaging

mediaplayer = '/data/openpilot/selfdrive/dragonpilot/mediaplayer/'

def main(gctx=None):

  context = zmq.Context()
  poller = zmq.Poller()
  controls_state_sock = messaging.sub_sock(context, service_list['controlsState'].port, conflate=True, poller=poller)

  last_v_ego = 0.
  last_active = False

  env = dict(os.environ)
  env['LD_LIBRARY_PATH'] = mediaplayer

  while 1:

    controls_state = None
    v_ego = 0
    active = False

    for socket, event in poller.poll(100):
      if socket is controls_state_sock:
        controls_state = messaging.recv_one(socket)

    if controls_state is not None:
      v_ego = controls_state.controlsState.vEgo
      active = controls_state.controlsState.active

    # we are driving and all of sudden we dont have any speed at all
    # we better warn the driver before it's too late
    if last_active and last_v_ego >= 5 and v_ego == 0:
      subprocess.Popen([mediaplayer + 'mediaplayer', '/data/openpilot/selfdrive/dragonpilot/safeguardd/error.wav'], shell = False, stdin=None, stdout=None, stderr=None, env = env, close_fds=True)

    last_active = active
    last_v_ego = v_ego

if __name__ == "__main__":
  main()