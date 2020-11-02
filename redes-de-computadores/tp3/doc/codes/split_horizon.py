class RouterList:
  {...}
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