from datetime import datetime
from ipaddress import ip_address

class Route:
  def __init__(self, address):
    self.__last_update = datetime.now()
    self.__ipaddress = address
    self.__hops = dict()

  def can_be_removed(self):
    return len(self.__hops) == 0

  def update_hop(self, hop_address, weight):
    self.refresh_date()
    self.__hops[hop_address] = weight

  def refresh_date(self):
    self.__last_update = datetime.now()

  @property
  def route(self):
    return min(self.__hops.items(), key=lambda x: x[1])

  def remove_hop(self, hop_address):
    if hop_address in self.__hops:
      del self.__hops[hop_address]

  @property
  def updated_since(self):
    return (datetime.now() - self.__last_update).seconds

class Link:  
  def __init__(self, ipaddr, weight):
    self.__ipaddr = ipaddr
    self.__weight = weight
  
  @property
  def weight(self):
    return self.__weight

  @weight.setter
  def weight(self, weight):
    self.__weight = weight

class RouterList:

  def __init__(self, local_address, max_life_time):
    self.__local_ip = local_address
    self.__max_life = max_life_time
    self.__links = dict()
    self.__routes = dict()

  def add(self, ipaddress_, weight, next):
    str_ip = str(ip_address(ipaddress_))
    self.__links[str_ip] = Link(str_ip, weight)
    self.__routes[str_ip] = Route(str_ip)
    self.__routes[str_ip].update_hop(str_ip, weight)

  def remove(self, ipaddress_):
    str_ip = str(ip_address(ipaddress_))
    del self.__links[str_ip]
    deletion_list = [str_ip]

    for ipaddr, route in self.__routes.items():
      route.remove_hop(str_ip)
      if route.can_be_removed:
        deletion_list.append(ipaddr)

    for ipaddr in deletion_list:
      del self.__routes[ipaddr]

  @property
  def links(self):
    return self.__links.keys()

  def next_hop(self, ipaddress_):
    if ipaddress_ in self.__routes:
      return self.__routes[ipaddress_].route[0]
    return None

  def refresh_routes(self):
    deletion_list = []
    for ipaddr, route in self.__routes.items():
      if ipaddr not in self.__links:
        if route.updated_since > self.__max_life:
          deletion_list.append(ipaddr)

    for ipaddr in deletion_list:
      del self.__routes[ipaddr]

  def update_routes(self, link_addr, distances):
    if link_addr not in self.__links:
      return
    
    deletion_list = []
    for ipaddr, r in self.__routes.items():
      if ipaddr != link_addr:
        r.remove_hop(link_addr)
        if r.can_be_removed():
          deletion_list.append(ipaddr)
        else:
          r.refresh_date()

    for ipaddr in deletion_list:
      del self.__routes[ipaddr]
    
    link_weight = self.__links[link_addr].weight
    for ipaddr, weight in distances.items():
      if ipaddr not in self.__routes:
        self.__routes[ipaddr] = Route(ipaddr)
      self.__routes[ipaddr].update_hop(link_addr, weight+link_weight)

  '''
    generate a dictionary for each router link unsing split horizon optimization
  '''
  def distances_dictionary(self):
    all_distances = dict()
    for ipaddr, r in self.__routes.items():
      all_distances[ipaddr] = r.route

    distances = dict()
    for link, linkv in self.__links.items():
      distance = dict()
      for ipaddr, route in all_distances.items():
        if ipaddr != link and route[0] != link:
          distance[ipaddr] = route[1]
      distance[self.__local_ip] = linkv.weight
      distances[link] = distance

    return distances