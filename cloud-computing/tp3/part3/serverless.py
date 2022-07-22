import datetime
import json
import redis
import os
import time

from usermodule import handler

REDIS_HOST = os.getenv('REDIS_HOST', "localhost")
REDIS_PORT = int(os.getenv('REDIS_PORT', 6379))
REDIS_INPUT_KEY = os.getenv('REDIS_INPUT_KEY', None)
REDIS_OUTPUT_KEY = os.getenv('REDIS_OUTPUT_KEY', None)

INTERVAL_TIME = int(os.getenv('INTERVAL', 5))

r = redis.Redis(host=REDIS_HOST, port=REDIS_PORT, 
                charset="utf-8", decode_responses=True)


class Context(object):
    host = None
    port = None
    input_key = None
    output_key = None
    function_getmtime = None
    last_execution = None
    env = None

    def __init__(self):
        self.last_execution = None
        self.env = {}
    
    def restore_defaults(self):
        self.host = REDIS_HOST
        self.port = REDIS_PORT
        self.input_key = REDIS_INPUT_KEY
        self.output_key = REDIS_OUTPUT_KEY
        tmp = os.path.getmtime("/opt/usermodule.py")
        self.function_getmtime = datetime.datetime.fromtimestamp(tmp).strftime('%Y-%m-%d %H:%M:%S')


    def after(self):
        self.last_execution = datetime.datetime.now()


ctx = Context()

while True:
    data = None
    output = None
    data = r.get(REDIS_INPUT_KEY)
        
    if data:
        data = json.loads(data)
        ctx.restore_defaults()
        output = handler(data, ctx)
           
        if output and REDIS_OUTPUT_KEY:
            r.set(REDIS_OUTPUT_KEY, json.dumps(output))
        ctx.after()
    
    time.sleep(INTERVAL_TIME)