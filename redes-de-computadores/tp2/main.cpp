#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

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
std::string search_in_link(const std::vector<Link> &links, std::string hostname);

int main(int argc, const char *argv[]){
    const char *port;
    if(argc <= 3 && argc > 1){
        port = argv[1];
        if(argc == 3){
            // redirecting the input stream to read a file
            std::ifstream in(argv[2]);
            std::streambuf *cinbuf = std::cin.rdbuf();
            std::cin.rdbuf(in.rdbuf());
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

    // read input commands
    std::string command, s1, s2;
    while(std::cin >> command){
        if (command == "add") {
            std::cin >> s1 >> s2;
            auto it = hosts_map.find(s1);
            if(it == hosts_map.end()){
                hosts_map[s1] = s2;
            } else {
                it->ipaddr = s2;
                std::cout << "Endereco atualizado" << std::endl;
            }
        } else if (command == "search"){
            std::cin >> s1;
            auto it = hosts_map.find(s1);
            if(it != hosts_map.end()){
                std::cout << it->ipaddr << std::endl;
                continue;
            } 

            // search client in the links
            std::string hostaddr = search_in_link(links, s1);
            if(hostaddr == "-1"){
                std::cout << "Endereco nao encontrado" << std::endl;
            } else {
                std::cout << hostaddr << std::endl;
            }
        } else if(command == "link"){
            std::cin >> s1 >> s2;
            Link l = {s1, s2};
            links.push_back(Link{s1, s2});
        }
    }

    return 0;
}

std::string search_in_link(const std::vector<Link> &links, const std::string hostname){
    std::string hostaddr = "-1";
    for(int i=0; i<links.size(); i++){
        UDPClient cli = UDPClient(links[i].ipaddress.c_str(), links[i].port.c_str());
        hostaddr = cli.ask_by_hostname(hostname);
        if(hostaddr != "-1") break;
    }
    return hostaddr;
}


void *dns_handling_server(void *params){
    data *dd = static_cast<data *>(params);
    
    //create a new UDPClient for search a host in link

    // bind the server
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
            std::string hostaddr = "-1";
            hostaddr = search_in_link(*(dd->links), hostname);
            server->send_hostaddress(hostaddr);
        }
    }
}