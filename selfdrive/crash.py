"""Install exception handler for process crash."""
import os
import sys
import json
#from subprocess import check_output
import threading
from selfdrive.version import version, dirty

from selfdrive.swaglog import cloudlog

if os.getenv("NOLOG") or os.getenv("NOCRASH"):
  def capture_exception(*exc_info):
    pass
  def bind_user(**kwargs):
    pass
  def bind_extra(**kwargs):
    pass
  def install():
    pass
else:
  from raven import Client
  from raven.transport.http import HTTPTransport

  error_tags = {'dirty': dirty, 'username': 'char_error'}

  try:
    with open("/data/data/ai.comma.plus.offroad/files/persistStore/persist-auth", "r") as f:
      auth = json.loads(f.read())
    auth = json.loads(auth['commaUser'])
    tags = ['username', 'email']
    for tag in tags:
      try:
        error_tags[tag] = ''.join(char for char in auth[tag].decode('utf-8', 'ignore') if char.isalnum())
      except:
        pass
  except:
    pass

  logging_data = {"branch": "/data/params/d/GitBranch", "commit": "/data/params/d/GitCommit", "remote": "/data/params/d/GitRemote"}

  for key in logging_data:
    try:
      with open(logging_data[key], "r") as f:
        error_tags[key] = str(f.read())
    except:
      error_tags[key] = "unknown"

  client = Client('https://980a0cba712a4c3593c33c78a12446e1:fecab286bcaf4dba8b04f7cff0188e2d@sentry.io/1488600',
                  install_sys_hook=False, transport=HTTPTransport, release=version, tags=error_tags)

  def capture_warning(warning_string):
    client.captureMessage(warning_string, level='warning')

  def capture_info(info_string):
    client.captureMessage(info_string, level='info')

  def capture_exception(*args, **kwargs):
    client.captureException(*args, **kwargs)
    cloudlog.error("crash", exc_info=kwargs.get('exc_info', 1))

  def bind_user(**kwargs):
    client.user_context(kwargs)

  def bind_extra(**kwargs):
    client.extra_context(kwargs)

  def install():
    # installs a sys.excepthook
    __excepthook__ = sys.excepthook
    def handle_exception(*exc_info):
      if exc_info[0] not in (KeyboardInterrupt, SystemExit):
        capture_exception(exc_info=exc_info)
      __excepthook__(*exc_info)
    sys.excepthook = handle_exception

    """
    Workaround for `sys.excepthook` thread bug from:
    http://bugs.python.org/issue1230540
    Call once from the main thread before creating any threads.
    Source: https://stackoverflow.com/a/31622038
    """
    init_original = threading.Thread.__init__

    def init(self, *args, **kwargs):
      init_original(self, *args, **kwargs)
      run_original = self.run

      def run_with_except_hook(*args2, **kwargs2):
        try:
          run_original(*args2, **kwargs2)
        except Exception:
          sys.excepthook(*sys.exc_info())

      self.run = run_with_except_hook

    threading.Thread.__init__ = init
