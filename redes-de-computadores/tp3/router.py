import json
import socket
import threading
from datetime import datetime
from message import *
from router_list import Link, RouterList
import ipaddress


BUFFERSIZE = 4096
DEFAULT_PORT = 55151

class Router(threading.Thread):

  def __init__(self, ipaddr, update_period):
    threading.Thread.__init__(self)
    self.__port = DEFAULT_PORT
    self.__ipaddr = str(ipaddress.ip_address(ipaddr))
    self.__router_list = RouterList(self.__ipaddr, 4*update_period)
    self.__period = update_period
    self.__running = True
    self.__socket_binding()

  def __recv_message_as_json(self):
    data, addr = self.__sock.recvfrom(BUFFERSIZE)
    json_str = data.decode('utf-8')
    message = Message.new_message(json_str)
    return message, addr

  def __send_message_as_json(self, message):
    ipaddr = self.__router_list.next_hop(message.destination)
    if ipaddr is not None:
      self.__sock.sendto(str(message).encode(), (ipaddr, DEFAULT_PORT))
    

  def __share_router_list(self, past):
    now = datetime.now()

    if (now - past).seconds > self.__period:
      self.__router_list.refresh_routes()
      all_links_distances = self.__router_list.distances_dictionary()
      
      for link, distances in all_links_distances.items():
        msg = Update(self.__ipaddr, link, distances)
        self.__send_message_as_json(msg)

      return True
    return False

  def __handle_update(self, message):
    if message.destination != self.__ipaddr:
      self.__send_message_as_json(message)
    else:
      self.__router_list.update_routes(message.source, message.distances)

  def __handle_trace(self, message):
    message.new_hops(self.__ipaddr)
    if message.destination == self.__ipaddr:
      new_dest = message.source
      new_message = Data(self.__ipaddr, new_dest, str(message))
      self.__send_message_as_json(new_message)
    else:
      self.__send_message_as_json(message)
    
  def __handle_data(self, message):
    print('payload:', message.payload)
    if message.destination != self.__ipaddr:
      self.__send_message_as_json(message)

  def __handle_message(self, message):
    if message.type_ == 'update':
      self.__handle_update(message)
    elif message.type_ == 'trace':
      self.__handle_trace(message)
    elif message.type_ == 'data':
      self.__handle_data(message)

  def run(self):
    old_time = datetime.now()
    while self.__running:
      try:
        if self.__share_router_list(old_time):
          old_time = datetime.now()

        data, _ = self.__recv_message_as_json()
        self.__handle_message(data)
        
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
    self.__sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    self.__sock.bind((self.__ipaddr, self.__port))

  def start_trace(self, destination_addr):
    trace_msg = Trace(self.__ipaddr, destination_addr, [])
    self.__handle_trace(trace_msg)

  def new_address(self, ipaddress_, weight):
    self.__router_list.add(ipaddress_, weight, ipaddress_)

  def del_address(self, ipaddress_):
    self.__router_list.remove(ipaddress_)