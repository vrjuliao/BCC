#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define PORT 51511

int int main(int argc, char const *argv[]){
	/* code */
	int server_sck;
	struct sockaddr_in address;


	if ((server_sck = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(PORT);

	if (bind(server_sck, (struct sockaddr *)&address,
		sizeof(address))){ 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }

	if (listen(server_sck, 3)){ 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 


	return 0;
}