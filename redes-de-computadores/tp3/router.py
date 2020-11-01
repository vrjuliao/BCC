import json

class Router:
  def __init__(self, ipaddr, update_period):
    self.__links = dict()
    self.__port = 55151
    self.__ipaddr = ipaddr
    self.__period = update_period

  def new_address(self, ipaddress, weight):
    self.__links[ipaddress] = weight

  def del_address(self, ipaddress):
    del self.__links[ipaddress]

  def print_address(self):
    for link in self.__links.items():
      print(link)