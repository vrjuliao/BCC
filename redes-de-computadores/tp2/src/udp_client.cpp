#include "udp_client.hpp"
#include "utils.hpp"

#include <arpa/inet.h>
#include <cstring>

UDPClient::UDPClient(const char *ipaddr, const char *sck_port){
    this->init_client_socket(ipaddr, sck_port);
}

void UDPClient::init_client_socket(const char *ipaddr, const char *sck_port){
    uint16_t port = (uint16_t)atoi(sck_port);
    if (port == 0) {
        throw InitSocketException("Invalid port");
    }
    port = htons(port);

    in_addr inaddr4; // IPV4
    if (inet_pton(AF_INET, ipaddr, &inaddr4)) {
        sockaddr_in *addr4 = (sockaddr_in *)this->sck_addr;
        addr4->sin_family = AF_INET;
        addr4->sin_port = port;
        addr4->sin_addr = inaddr4;
        return;
    }

    in6_addr inaddr6; // IPv6
    if (inet_pton(AF_INET6, ipaddr, &inaddr6)) {
        sockaddr_in6 *addr6 = (sockaddr_in6 *)this->sck_addr;
        addr6->sin6_family = AF_INET6;
        addr6->sin6_port = port;
        // a bit array must be copied
        memcpy(&(addr6->sin6_addr), &inaddr6, sizeof(inaddr6));
        return;
    }

    throw InitSocketException("Client socket bind failed");
}

UDPClient::~UDPClient(){}