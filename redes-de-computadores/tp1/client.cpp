#include <cstdlib>
#include <cstring>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <vector>
#include <iostream>


int init_socket(const char *ipaddr, const char *sck_port,
              struct sockaddr_storage *sck_addr) {
    if (ipaddr == NULL || sck_port == NULL) {
        return -1;
    }

    uint16_t port = (uint16_t)atoi(sck_port);
    if (port == 0) {
        return -1;
    }
    port = htons(port);

    struct in_addr inaddr4; // IPV4
    if (inet_pton(AF_INET, ipaddr, &inaddr4)) {
        struct sockaddr_in *addr4 = (struct sockaddr_in *)sck_addr;
        addr4->sin_family = AF_INET;
        addr4->sin_port = port;
        addr4->sin_addr = inaddr4;
        return 0;
    }

    struct in6_addr inaddr6; // IPv6
    if (inet_pton(AF_INET6, ipaddr, &inaddr6)) {
        struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)sck_addr;
        addr6->sin6_family = AF_INET6;
        addr6->sin6_port = port;
        // a bit array must be copied
        memcpy(&(addr6->sin6_addr), &inaddr6, sizeof(inaddr6));
        return 0;
    }

    return -1;
}

int main(int argc, char *argv[]){
    char buffer[256];

    if(argc != 3){
        exit(EXIT_FAILURE);
    }

    struct sockaddr_storage sck_addr;
    if (0 != init_socket(argv[1], argv[2], &sck_addr)) {
        exit(EXIT_FAILURE);
    }

    int server_sck_id;
    server_sck_id = socket(sck_addr.ss_family, SOCK_STREAM, 0);
    if (server_sck_id == -1) {
        exit(EXIT_FAILURE);
    }
    struct sockaddr *addr = (struct sockaddr *)(&sck_addr);
    if (0 != connect(server_sck_id, addr, sizeof(sck_addr))) {
        exit(EXIT_FAILURE);
    }
    
    uint8_t msg_type = 0;
    std::vector<uint8_t> pack = std::vector<uint8_t>(2);
    while(msg_type != 1){
        if (0 > recv(server_sck_id, buffer, 2, MSG_WAITALL)){
            exit(EXIT_FAILURE);
        }
        msg_type = static_cast<uint8_t>(buffer[0]);
    }
    std::cout << static_cast<int>(buffer[1]) << std::endl;


    char ch;
    while(true){
        ch = '\n';
        while(ch == '\n'){
            ch = getchar();
        }
        pack[0] = 2;
        pack[1] = static_cast<uint8_t>(ch);

        // send the message
        if(0 > send(server_sck_id, reinterpret_cast<const char*>(pack.data()), 
            pack.size(), 0)){
            exit(EXIT_FAILURE);
        }

        std::cout << "send: " << pack[1] << std::endl;

        //receiving message
        msg_type = 0;
        int received_bytes;
        while(msg_type != 3 && msg_type != 4){
            received_bytes = recv(server_sck_id, buffer, 2, 0);
            std::cout << static_cast<int>(buffer[1]) << std::endl;
            
            if (0 > received_bytes){
                exit(EXIT_FAILURE);
            }
            msg_type = static_cast<uint8_t>(buffer[0]);
        }
        if(msg_type == 4) break;
        

        size_t msg_len;
        if(received_bytes==1){
            recv(server_sck_id, buffer, 1, MSG_WAITALL);
            msg_len = static_cast<size_t>(buffer[0]);
        } else {
            msg_len = static_cast<size_t>(buffer[1]);
        }
        if(msg_len > 0){
            if (0 > recv(server_sck_id, buffer, msg_len, MSG_WAITALL)){
                exit(EXIT_FAILURE);
            }
            std::cout << static_cast<int>(buffer[0]);
            for(int i=1; i<msg_len; i++){
                std::cout << " " << static_cast<int>(buffer[i]);
            }
            std::cout << std::endl;
        }

    }
}