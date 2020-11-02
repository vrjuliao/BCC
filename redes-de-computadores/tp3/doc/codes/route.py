class Route:
  {...}
  def route(self):
    return min(self.__hops.items(), key=lambda x: x[1])

class RouteList:
  {...}
  def next_hop(self, ipaddress_):
    if ipaddress_ in self.__routes:
      return self.__routes[ipaddress_].route[0]
    return None

class Router(Thread):
  {...}
  def __send_message_as_json(self, message):
    ipaddr = self.__router_list.next_hop(message.destination)
    if ipaddr is not None:
      self.__sock.sendto(str(message).encode(), (ipaddr, DEFAULT_PORT))
    