#include <unistd.h>
#include <cstring>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iostream>

//Constants
static const int _IPV4 = 4;
static const int _IPV6 = 6;

// Definitions
static const int _IP_VERSION = _IPV4;
static const std::string WORD = "beterraba";


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

std::vector<uint8_t> get_repetitions(const std::string &word, char guessed){
    std::vector<uint8_t> result = std::vector<uint8_t>();
    for(int i=0; i<word.size(); i++){
        if(guessed == word[i]){
            result.push_back(i);
        }
    }
    return result;
}

bool word_is_complete(const std::map<char, bool> &word_map){
    for(auto i: word_map){
        if (!i.second) return false;
    }
    return true;
}

int main(int argc, char *argv[]){
    
    if(argc != 2){
        exit(EXIT_FAILURE);
    }


    std::string word = WORD;
    std::map<char, bool> word_map = std::map<char, bool>();
    for(char c: word){
        word_map.insert(std::make_pair(c, false));
    }

    sockaddr_storage sck_addr;
    if(0 != init_socket(argv[1], &sck_addr)){
        exit(EXIT_FAILURE);
    }

    // bind passive socket
    int server_sck_id;
    server_sck_id = socket(sck_addr.ss_family, SOCK_STREAM, 0);
    if(server_sck_id == -1) exit(EXIT_FAILURE);
    int i=1;
    if(0 != setsockopt(server_sck_id, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(int))){
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

    char buffer[2];

    // bool match_word = false;
    uint8_t msg_type;
    char guessed;

    int cliente_sck_id = accept(server_sck_id, cli_addr, &len);

    // initial message
    pack[0] = 1;
    pack[1] = static_cast<uint8_t>(word.size());
    if(0 > send(cliente_sck_id, reinterpret_cast<const char*>(pack.data()), 
            pack.size(), 0)){
        exit(EXIT_FAILURE);
    }

    // while(!match_word){
    while(true){
        if (0 > recv(cliente_sck_id, buffer, 2, MSG_WAITALL)){
            exit(EXIT_FAILURE);
        }
        msg_type = buffer[0]; 
        guessed = buffer[1];
        std::cout << "Received: " << buffer[1] << std::endl;

        if(msg_type != 2) continue;

        // find the guessed char in the word
        // get the indexes of the char occurrences
        // -- Create a vector<uint8_t> to get each index of the char in the word
        
        pack[0] = 3;
        pack[1] = 0;
        auto it = word_map.find(guessed);
        bool match_char = it != word_map.end();

        std::vector<uint8_t> char_repetitions;
        if(match_char){
            it->second = true;
            if(word_is_complete(word_map)) break;

            char_repetitions = get_repetitions(word, guessed);
            pack[1] = static_cast<uint8_t>(char_repetitions.size());
        }
        if(0 > send(cliente_sck_id, reinterpret_cast<const char*>(pack.data()), 
            pack.size(), 0)){
            exit(EXIT_FAILURE);
        }
        if(match_char){
            if(0 > send(cliente_sck_id, reinterpret_cast<const char*>(char_repetitions.data()), 
                char_repetitions.size(), 0)){
                exit(EXIT_FAILURE);
            }
        }
        // match_word = word_is_complete(word_map);

    }
    pack[0] = 4;
    if(0 > send(cliente_sck_id, reinterpret_cast<const char*>(pack.data()), 
        1, 0)){
        exit(EXIT_FAILURE);
    }
    

    close(cliente_sck_id);


}