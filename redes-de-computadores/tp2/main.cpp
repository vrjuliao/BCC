#include <iostream>
#include <map>
#include <vector>
#include <string>

#include <pthread.h>

#include "udp_client.hpp"
#include "udp_server.hpp"
#include "utils.hpp"

#define hostname first
#define ipaddr second

struct Link {
    std::string ipaddress;
    std::string port;
};

struct data{
    const std::map<std::string, std::string> *hosts_map;
    const std::vector<Link> *links;
    const char *port;
    UDPServer *server;
};

void *dns_handling_server(void *params);
std::string search_in_link(const Link &link);

int main(int argc, const char *argv[]){
    const char *port;
    if(argc <= 3 && argc > 1){
        port = argv[1];
        if(argc == 3){
            // read from file
            // put the input stream as the file 
        } else {
            // input stream is the stdin
        }
    } else {
        std::cout << "Initialization error" << std::endl;
        exit(EXIT_FAILURE);
    }

    UDPServer *server;
    try{
        server = new UDPServer(port);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    // hosts_map -> <hostname, ipaddress>
    std::map<std::string, std::string> hosts_map = std::map<std::string, std::string>();
    std::vector<Link> links = std::vector<Link>();

    data *dns_server_data = new data();
    dns_server_data->hosts_map = &hosts_map;
    dns_server_data->links = &links;
    dns_server_data->port = port;
    dns_server_data->server = server;
    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, dns_handling_server, (void*) dns_server_data) < 0) {
        std::cout << "Could not create thread" << std::endl;
        exit(EXIT_FAILURE);
    }

    // read input proccess


    return 0;
}


void *dns_handling_server(void *params){
    data *dd = static_cast<data *>(params);
    
    //create a new UDPClient for search a host in link

    //bind the server
    // UDPServer server = UDPServer(dd->port);
    UDPServer *server = dd->server;
    std::string hostname;
    while(true){
        hostname = server->recv_hostname();

        auto it = dd->hosts_map->find(hostname);
        if(it != dd->hosts_map->end()){
            server->send_hostaddress(it->ipaddr);
        } else {
            // search client in the links
            Link l;
            std::string hostaddr = "";
            for(int i=0; i<dd->links->size(); i++){
                l = dd->links->at(i);
                hostaddr = search_in_link(l);
                if(!hostaddr.empty()){
                    break;
                }

            }
            if(hostaddr.empty()){
                char empty_response[1];
                empty_response[0] = static_cast<int8_t>(-1);
                hostaddr = std::string(empty_response);
            }
            server->send_hostaddress(hostaddr);
        }
    }
}