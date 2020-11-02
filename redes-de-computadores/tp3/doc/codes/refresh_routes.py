class RouterList:
  {...}
  def refresh_routes(self):
    deletion_list = []
    for ipaddr, route in self.__routes.items():
      if ipaddr not in self.__links:
        if route.updated_since > self.__max_life:
          deletion_list.append(ipaddr)

    for ipaddr in deletion_list:
      del self.__routes[ipaddr]