#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <vector>

static const int _IPV4 = 4;
static const int _IPV6 = 6;
static const int _IP_VERSION = _IPV4;


int init_socket(const char *sck_port, sockaddr_storage *sck_addr){
    uint16_t port = (uint16_t)atoi(sck_port); // unsigned short
    if (port == 0) {
        return -1;
    }
    port = htons(port); // host to network short

    memset(sck_addr, 0, sizeof(sockaddr_storage));
    if (_IP_VERSION == _IPV4) {
        sockaddr_in *addr4 = (sockaddr_in *)sck_addr;
        addr4->sin_family = AF_INET;
        addr4->sin_addr.s_addr = INADDR_ANY;
        addr4->sin_port = port;
        return 0;
    } else if (_IP_VERSION == _IPV6) {
        sockaddr_in6 *addr6 = (sockaddr_in6 *)sck_addr;
        addr6->sin6_family = AF_INET6;
        addr6->sin6_addr = in6addr_any;
        addr6->sin6_port = port;
        return 0;
    } else {
        return -1;
    }
}

int main(int argc, char *argv[]){
    

    if(argc != 2){
        exit(EXIT_FAILURE);
    }

    sockaddr_storage sck_addr;
    if(0 != init_socket(argv[1], &sck_addr)){
        exit(EXIT_FAILURE);
    }

    // bind passive socket
    int server_sck_id;
    server_sck_id = socket(sck_addr.ss_family, SOCK_STREAM, 0);
    if(server_sck_id == -1) exit(EXIT_FAILURE);

    if(0 != setsockopt(server_sck_id, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int))){
        exit(EXIT_FAILURE);
    }

    sockaddr *addr = (sockaddr *)(&sck_addr);
    if (0 != bind(server_sck_id, addr, sizeof(sck_addr))) {
        exit(EXIT_FAILURE);
    }

    if (0 != listen(server_sck_id, 10)) {
        exit(EXIT_FAILURE);
    }

    sockaddr_storage cli_storage;
    sockaddr *cli_addr = (sockaddr *)(&cli_storage);
    socklen_t len = sizeof(cli_storage);
    std::vector<uint8_t> pack = std::vector<uint8_t>(2);
    uint8_t *msg_tpe;

    char buffer[256];

    bool match_word = false;
    char guessed;
    while(true){

        int cliente_sck_id = accept(server_sck_id, cli_addr, &len);

        // initial message
        pack[0] = 1;
        pack[1] = 10;
        if(0 > send(cliente_sck_id, reinterpret_cast<const char*>(pack.data()), 
                pack.size(), 0)){
            exit(EXIT_FAILURE);
        }

        while(!match_word){
            if (0 > recv(cliente_sck_id, buffer, 2, MSG_WAITALL)){
                exit(EXIT_FAILURE);
            }
            
            guessed = buffer[1];

            // find the guessed char in the word
            // get the indexes of the char occurrences
            // -- Create a vector<uint8_t> to get each index of the char in the word

        }
        

        close(cliente_sck_id);
    }


}