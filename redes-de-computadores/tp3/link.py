from datetime import datetime
from ipaddress import ip_address


class Link:  
  def __init__(self, ipaddr, weight, thru):
    self.__ipaddr = ipaddr
    self.__weight = weight
    self.__thru = thru
    self.__distances = {}
    self.__last_update = datetime.now()
  
  @property
  def weight(self):
    return self.__weight

  @weight.setter
  def weight(self, weight):
    self.__weight = weight

  @property
  def distances(self):
    return self.__distances

  @distances.setter
  def distances(self, distances):
    self.__distances = distances

  @property
  def thru(self):
    return self.__thru

  @thru.setter
  def thru(self, thru):
    self.__thru = thru

  @property
  def updated_since(self):
    return (datetime.now() - self.__last_update).seconds

class RouterList:

  def __init__(self, max_life_time):
    self.__max_life = max_life_time
    self.__links = dict()

  def add(self, ipaddress_, weight, thru):
    str_ip = str(ip_address(ipaddress_))
    self.__links[str_ip] = Link(str_ip, weight, str_ip)

  def remove(self, ipaddress_):
    str_ip = str(ip_address(ipaddress_))
    del self.__links[str_ip]

  @property
  def links(self):
    return self.__links.keys()

  #implement next_hop function:
  #  point the `thru` attr from Link