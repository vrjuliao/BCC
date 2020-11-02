class Router(Thread):
  {...}
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