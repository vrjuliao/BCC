#include "udp_server.hpp"
#include "utils.hpp"

#include <arpa/inet.h>
#include <cstring>
#include <sys/socket.h>

#include <iostream>

UDPServer::UDPServer(const char *sck_port){
    memset(&this->sck_addr, 0, sizeof(sockaddr_storage));
    memset(&this->cli_sockaddr, 0, sizeof(sockaddr_storage));
    this->init_server_socket(sck_port);
}

void UDPServer::init_server_socket(const char *sck_port){
    uint16_t port = (uint16_t)std::stoi(sck_port);
    if (port == 0) {
        throw InitSocketException("Invalid port");
    }
    port = htons(port);

    /* - bind an socket with the IP Version based on 
         Utils::IPVERSION static attribute
       - Throws an exception case the IPVersion is not correct
    */
    if (Utils::IPVERSION ==  Utils::IPV4) {
        sockaddr_in *addr4 = (sockaddr_in *)(&this->sck_addr);
        addr4->sin_family = AF_INET;
        addr4->sin_addr.s_addr = INADDR_ANY;
        addr4->sin_port = port;
    } else if (Utils::IPVERSION == Utils::IPV6) {
        sockaddr_in6 *addr6 = (sockaddr_in6 *)(&this->sck_addr);
        addr6->sin6_family = AF_INET6;
        addr6->sin6_addr = in6addr_any;
        addr6->sin6_port = port;
    } else {
        throw InitSocketException("Invalid IP binding");
    }

    this->server_sck_id = socket(this->sck_addr.ss_family, SOCK_DGRAM, 0);
    if(this->server_sck_id < -1) throw InitSocketException("Init UDP socket error");
    
    
    // set option to reuse the same socket port and ip address
    int i=1;
    if(0 != setsockopt(server_sck_id, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(int))){
        throw InitSocketException("Setting up socket options error");
    }

    sockaddr *addr = (sockaddr *)(&sck_addr);
    if (0 != bind(this->server_sck_id, addr, sizeof(sck_addr))) {
        throw InitSocketException("Socket binding error");
    }
}

// receive the hostname from a client
std::string UDPServer::recv_hostname(){
    char buffer[Utils::MAX_BUFFER_SIZE];

    buffer[0] = 0;
    socklen_t len = sizeof(this->cli_sockaddr);
    int n_bytes;
    
    // wait for the correct message code
    while(buffer[0] != 1){
        n_bytes = recvfrom(this->server_sck_id, buffer, Utils::MAX_BUFFER_SIZE, 0,
          (sockaddr *) &this->cli_sockaddr, &len);
    }
    buffer[n_bytes] = '\0';
    return std::string(buffer+1);
}


// send to the client the hostaddress
void UDPServer::send_hostaddress(const std::string &msg){
    char msg_code = 2;
    std::string new_message = msg_code + msg;

    socklen_t len = sizeof(this->cli_sockaddr);
    sendto(this->server_sck_id, new_message.c_str(), new_message.size(), MSG_CONFIRM,
      (sockaddr *) &this->cli_sockaddr, len); 
    memset(&this->cli_sockaddr, 0, sizeof(sockaddr_storage));
}

UDPServer::~UDPServer(){}