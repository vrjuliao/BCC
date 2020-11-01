import json
import socket
import threading
from datetime import datetime

class Link:
  def __init__(self, weight, thru):
    self.__weight = weight
    self.__thru = thru
  
  @property
  def weight(self):
    return self.__weight

  @weight.setter
  def weight(self, weight):
    self.__weight = weight

  @property
  def thru(self):
    return self.__thru

  @thru.setter
  def thru(self, thru):
    self.__thru = thru

class Router(threading.Thread):
  BUFFERSIZE = 4096

  def __init__(self, ipaddr, update_period):
    threading.Thread.__init__(self)
    self.__links = dict()
    self.__router_table = dict()
    self.__port = 55151
    self.__ipaddr = ipaddr
    self.__period = update_period
    self.__running = True
    self.__socket_binding()

  def __recv_json(self):
    data, addr = self.__sock.recvfrom(self.BUFFERSIZE) # buffer size is 4096 bytes
    json_str = data.decode('utf-8')
    message = json.loads(json_str)
    return message, addr

  def __share_router_list(self, past):
    now = datetime.now()

    if (now - past).seconds > self.__period:
      return True
      # sent router list to all links
    return False
  
  def run(self):
    old_time = datetime.now()
    while self.__running:
      try:
        if self.__share_router_list(old_time):
          old_time = datetime.now()


        data, addr = self.__recv_json()
        
      except socket.timeout:
        continue
      except json.decoder.JSONDecodeError:
        continue
    self.__sock.close()

  def terminate(self):
    self.__running = False

  def __socket_binding(self):
    self.__sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    self.__sock.settimeout(0.5)
    self.__sock.bind((self.__ipaddr, self.__port))

  def new_address(self, ipaddress, weight):
    self.__links[ipaddress] = weight
    self.__router_table[ipaddress] = Link(weight, ipaddress)

  def del_address(self, ipaddress):
    del self.__links[ipaddress]

  def print_address(self):
    for link in self.__links.items():
      print(link)