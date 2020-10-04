#include "udp_client.hpp"
#include "utils.hpp"

#include <arpa/inet.h>
#include <cstring>
#include <errno.h>

#include <iostream>

UDPClient::UDPClient(const char *ipaddr, const char *sck_port){
    memset(&this->sck_addr, 0, sizeof(sockaddr_storage));
    this->init_client_socket(ipaddr, sck_port);
}

void UDPClient::init_client_socket(const char *ipaddr, const char *sck_port){
    uint16_t port = (uint16_t)std::stoi(sck_port);
    if (port == 0) {
        throw InitSocketException("Invalid port");
    }
    port = htons(port);

    in_addr inaddr4; // IPV4
    in6_addr inaddr6; // IPv6
    if (inet_pton(AF_INET, ipaddr, &inaddr4)) {
        sockaddr_in *addr4 = (sockaddr_in *)(&this->sck_addr);
        addr4->sin_family = AF_INET;
        addr4->sin_port = port;
        addr4->sin_addr = inaddr4;
    } else if (inet_pton(AF_INET6, ipaddr, &inaddr6)) {
        sockaddr_in6 *addr6 = (sockaddr_in6 *)(&this->sck_addr);
        addr6->sin6_family = AF_INET6;
        addr6->sin6_port = port;
        // a bit array must be copied
        memcpy(&(addr6->sin6_addr), &inaddr6, sizeof(inaddr6));
    } else {
        throw InitSocketException("Client socket bind failed");
    }

    this->sck_id = socket(this->sck_addr.ss_family, SOCK_DGRAM, 0);
    if(this->sck_id < -1) throw InitSocketException("Init UDP socket error");

}

std::string UDPClient::ask_by_hostname(const std::string &hostname){
    char msg_code = 1;
    std::string message = msg_code + hostname;

    socklen_t len = sizeof(this->sck_addr);
    sendto(this->sck_id, message.c_str(), message.size(), MSG_CONFIRM,
      (sockaddr *) &this->sck_addr, sizeof(this->sck_addr));

    char buffer[Utils::MAX_BUFFER_SIZE];
    buffer[0] = 0;
    int n_bytes;

    timeval tv;
	tv.tv_sec = 2;
	setsockopt(this->sck_id, SOL_SOCKET, SO_RCVTIMEO, (timeval *)&tv, sizeof(timeval));
    setsockopt(this->sck_id, SOL_SOCKET, SO_SNDTIMEO,(timeval *)&tv, sizeof(timeval));
    
    // could result in a problem because sockaddr_storage != sockaddr
    n_bytes = recvfrom(this->sck_id, buffer, Utils::MAX_BUFFER_SIZE, 0,
      (sockaddr *) &this->sck_addr, &len);

    if(static_cast<int>(buffer[0]) != 2){
        return "-1";
    }
    buffer[n_bytes] = '\0';
    return std::string(buffer+1); 
}

UDPClient::~UDPClient(){}