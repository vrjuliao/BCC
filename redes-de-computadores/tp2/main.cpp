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

// IP version used by the server
int Utils::IPVERSION = Utils::IPV4;

struct Link {
    std::string ipaddress;
    std::string port;
};

// requested data for the thread function
struct data{
    const std::map<std::string, std::string> *hosts_map;
    const std::vector<Link> *links;
    const char *port;
    UDPServer *server;
};

// thread prccess that responds for requested hostnames
void *dns_handling_server(void *params);

// ask hostname for the links
std::string search_in_link(const std::vector<Link> &links, std::string hostname);

// execute input commands reading a file
void execute_from_file(const std::string &filename, std::vector<Link> &links,
  std::map<std::string, std::string> &hosts_map);

// execute input commands reading standard input
void execute_commands(std::vector<Link> &links,
  std::map<std::string, std::string> &hosts_map);

int main(int argc, const char *argv[]){
    const char *port;
    if(argc <= 3 && argc > 1){
        port = argv[1];
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

    std::string filename;
    if(argc == 3){
        filename = std::string(argv[2]);
        // execute all commands in the <filename>
        execute_from_file(filename, links, hosts_map);
    }

    execute_commands(links, hosts_map);

    return 0;
}

void execute_from_file(const std::string &filename, std::vector<Link> &links,
  std::map<std::string, std::string> &hosts_map){

    // redirecting the input stream to read a file
    std::ifstream in(filename);
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());

    /* read and execute commands using std::cin
       in a file  */
    execute_commands(links, hosts_map);

    // rolling back the stdin for cin buffer
    std::cin.rdbuf(cinbuf);
}

void execute_commands(std::vector<Link> &links,
  std::map<std::string, std::string> &hosts_map){
    // read input commands
    std::string command, s1, s2;
    while(std::cin >> command){
        if (command == "add") {
            std::cin >> s1 >> s2;
            
            // if the hostname is in hosts map, this one should be updated
            auto it = hosts_map.find(s1);
            if(it == hosts_map.end()){
                hosts_map[s1] = s2;
            } else {
                it->ipaddr = s2;
                std::cout << "Endereco atualizado" << std::endl;
            }
        } else if (command == "search"){
            std::cin >> s1;
            
            //search hostname in map
            auto it = hosts_map.find(s1);
            if(it != hosts_map.end()){
                std::cout << it->ipaddr << std::endl;
                continue;
            } 

            // ask hostname for the links
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
}


std::string search_in_link(const std::vector<Link> &links, const std::string hostname){
    
    std::string hostaddr = "-1";
    //for each link, create a Client and ask about the hostname
    for(int i=0; i<links.size(); i++){
        UDPClient cli = UDPClient(links[i].ipaddress.c_str(), links[i].port.c_str());
        hostaddr = cli.ask_by_hostname(hostname);
        if(hostaddr != "-1") break;
    }
    return hostaddr;
}


void *dns_handling_server(void *params){
    data *dd = static_cast<data *>(params);

    UDPServer *server = dd->server;
    std::string hostname;
    while(true){
        hostname = server->recv_hostname();

        //search the hostname in the local map
        auto it = dd->hosts_map->find(hostname);
        if(it != dd->hosts_map->end()){
            server->send_hostaddress(it->ipaddr);
        } else {

            // ask hostname to the links
            std::string hostaddr = search_in_link(*(dd->links), hostname);
            server->send_hostaddress(hostaddr);
        }
    }
}