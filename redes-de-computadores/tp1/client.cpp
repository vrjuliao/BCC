#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <vector>
#include <iostream>
#include <utility>


// init active socket
int init_socket(const char *ipaddr, const char *sck_port,
                sockaddr_storage *sck_addr);

// check if the all characters in the word are be received
bool word_is_complete(const std::vector<std::pair<char, bool>> &word);

// read from stdin ignoring '\n' values
char read_input();  

// print response message and mark the sent character with a match flag
void response_treatment(std::vector<std::pair<char, bool>> &word,
    char *message, size_t length, char sent_char);

int main(int argc, char *argv[]){
    char buffer[256];

    std::vector<std::pair<char, bool>> word;

    if(argc != 3){
        exit(EXIT_FAILURE);
    }

    sockaddr_storage sck_addr;
    if (0 != init_socket(argv[1], argv[2], &sck_addr)) {
        exit(EXIT_FAILURE);
    }

    int server_sck_id;
    server_sck_id = socket(sck_addr.ss_family, SOCK_STREAM, 0);
    if (server_sck_id == -1) {
        exit(EXIT_FAILURE);
    }
    sockaddr *addr = (sockaddr *)(&sck_addr);
    if (0 != connect(server_sck_id, addr, sizeof(sck_addr))) {
        exit(EXIT_FAILURE);
    }
    
    // auxiliary attributes
    uint8_t msg_type = 0;
    std::vector<uint8_t> pack = std::vector<uint8_t>(2);
    int received_bytes;

    // waiting for init message or game overs
    while(msg_type != 1 && msg_type != 4){
        received_bytes = recv(server_sck_id, buffer, 1, 0);
        
        if (0 > received_bytes){
            exit(EXIT_FAILURE);
        }
        msg_type = static_cast<uint8_t>(buffer[0]);
    }
    if(msg_type == 4) {
        close(server_sck_id);
        return 0;
    }
    
    // The last recv() call does not use MSG_WAITALL
    // Then it is possible that the message containins just 1 byte.
    if(received_bytes==1){
        recv(server_sck_id, (buffer+1), 1, MSG_WAITALL);
    }

    uint8_t word_length = static_cast<uint8_t>(buffer[1]);
    int converted_length = static_cast<int>(word_length);
    std::cout << converted_length << std::endl;

    // creating data structure to compute the word
    word = std::vector<std::pair<char, bool>>(converted_length);
    for(int i=0; i<converted_length; i++){
        word[i] = std::make_pair('?', false);
    }
    bool match_word = false;

    char ch;
    while(!match_word){
        ch = read_input();

        pack[0] = 2;
        pack[1] = static_cast<uint8_t>(ch);

        // send the message
        if(0 > send(server_sck_id, reinterpret_cast<const char*>(pack.data()),
            pack.size(), 0)){
            exit(EXIT_FAILURE);
        }

        // receiving message
        // either letter response or game over
        msg_type = 0;
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
            // force the received data to be equals the msg_length received lastly
            if (msg_len != recv(server_sck_id, buffer, msg_len, MSG_WAITALL)){
                exit(EXIT_FAILURE);
            }
            // compute word according server response
            response_treatment(word, buffer, msg_len, ch);

            // when the word is completely received, then
            //   the loop will be stoped
            match_word = word_is_complete(word);
        }
        std::cout << std::endl;
    }
    // if the word is complete, then client will wait for
    //  game over message
    if(match_word){
        while(msg_type != 4){
            received_bytes = recv(server_sck_id, buffer, 1, 0);
            msg_type = static_cast<uint8_t>(buffer[0]);
        }
    } else {
        std::cout << std::endl;
    }

    std::cout << "Word: ";
    for(auto it: word)
        std::cout << it.first;
    std::cout << std::endl;
    close(server_sck_id);
}

int init_socket(const char *ipaddr, const char *sck_port,
                sockaddr_storage *sck_addr) {
    if (ipaddr == NULL || sck_port == NULL) {
        return -1;
    }

    uint16_t port = (uint16_t)atoi(sck_port);
    if (port == 0) {
        return -1;
    }
    port = htons(port);

    in_addr inaddr4; // IPV4
    if (inet_pton(AF_INET, ipaddr, &inaddr4)) {
        sockaddr_in *addr4 = (sockaddr_in *)sck_addr;
        addr4->sin_family = AF_INET;
        addr4->sin_port = port;
        addr4->sin_addr = inaddr4;
        return 0;
    }

    in6_addr inaddr6; // IPv6
    if (inet_pton(AF_INET6, ipaddr, &inaddr6)) {
        sockaddr_in6 *addr6 = (sockaddr_in6 *)sck_addr;
        addr6->sin6_family = AF_INET6;
        addr6->sin6_port = port;
        // a bit array must be copied
        memcpy(&(addr6->sin6_addr), &inaddr6, sizeof(inaddr6));
        return 0;
    }

    return -1;
}

// check if the all characters in the word are be received
bool word_is_complete(const std::vector<std::pair<char, bool>> &word){
    for(auto i: word){
        if (!i.second) return false;
    }
    return true;
}

// read from stdin ignoring '\n' values
char read_input(){
    char ch;
    ch = '\n';
    while(ch == '\n'){
        ch = getchar();
    }
    return ch;
}  

void response_treatment(std::vector<std::pair<char, bool>> &word,
    char *message, size_t length, char sent_char){
    int index = static_cast<int>(message[0]);
    word[index].first = sent_char;
    word[index].second = true;
    std::cout << index;
    for(int i=1; i<length; i++){
        index = static_cast<int>(message[i]);
        word[index].first = sent_char;
        word[index].second = true;
        std::cout << " " << index;
    }
    std::cout << std::endl;
}