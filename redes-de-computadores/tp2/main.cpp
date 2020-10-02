#include <iostream>
#include <map>
#include <string>

#include <pthread.h>

#include "udp_client.hpp"
#include "udp_server.hpp"

#define hostname first
#define ipaddr second

void dns_handling_server(void *params);

int main(int argc, const char *argv[]){
    // hosts_map -> <hostname, ipaddress>
    std::map<std::string, std::string> hosts_map = std::map<std::string, std::string>();

    return 0;
}

struct data{
    std::map<std::string, std::string> *hosts_map;
    const char *port;
};

void dns_handling_server(void *params){
    data *dd = static_cast<data *>(params);

    //create a new UDPClient for search a host in link



    //bind the server
    UDPServer server = UDPServer(dd->port);
    std::string hostname;
    while(true){
        hostname = server.recv_hostname();

        auto it = dd->hosts_map->find(hostname);
        if(it != dd->hosts_map->end()){
            server.send_hostaddress(it->ipaddr);
        } else {
        }
    }
}