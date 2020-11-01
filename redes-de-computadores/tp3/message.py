import json
import ipaddress

class Message:
  def __init__(self, src, dest, msg_type):
    self.__source  = str(ipaddress.ip_address(src))
    self.__destination = str(ipaddress.ip_address(dest))
    self.__type = msg_type

  def to_dict(self):
    d = dict()
    d['type'] = self.__type
    d['source'] = self.__source
    d['destination'] = self.__destination
    return d

  @staticmethod
  def new_message(message_string):
    msg = json.loads(message_string)
    msg_type = msg['type']
    if msg_type == 'data':
      return Data(msg['source'], msg['destination'], msg_type, msg['payload'])
    elif msg_type == 'update':
      return Update(msg['source'], msg['destination'], msg_type, msg['distances'])
    elif msg_type == 'trace':
      return Trace(msg['source'], msg['destination'], msg_type, msg['hops'])
    else:
      raise json.decoder.JSONDecodeError

  def __str__(self):
    return json.dumps(self.to_dict())

  @property
  def destination(self):
    return self.__destination

  @property
  def source(self):
    return self.__source

  @property
  def type_(self):
    return self.__type

class Data(Message):

  def __init__(self, src, dest, payload):
    Message.__init__(self, src, dest, 'data')
    self.__payload = payload

  def to_dict(self):
    d = super().to_dict()
    d['payload'] = self.__payload
    return d

  @property
  def payload(self):
    return self.__payload

class Update(Message):

  def __init__(self, src, dest, distances):
    Message.__init__(self, src, dest, 'update')
    self.__distances = distances

  def to_dict(self):
    d = super().to_dict()
    d['distances'] = self.__distances
    return d

  @property
  def distances(self):
    return self.__distances

class Trace(Message):

  def __init__(self, src, dest, hops):
    Message.__init__(self, src, dest, 'trace')
    self.__hops = hops

  def to_dict(self):
    d = super().to_dict()
    d['hops'] = self.__hops
    return d

  def new_hops(self, hop):
    return self.__hops.append(hop)

  @property
  def hops(self):
    return self.__hops