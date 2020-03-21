#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <sys/socket.h>

#define PORT 51511
#define STUDENT 1
#define PROFESSOR 2
#define KEY_LENGTH 8
#define MAX_STUDENTS 256

#define MAX_CHAR_ON_INT 10
#define READY_LENGTH 5
#define INTEGER_MAX_LENGTH 8
#define OK_LENGTH 2

int recv_(int sockfd, char buff[], int size, int flag, const char* expected_data){
	int i;
	//check timeout occurrence
	if( (i = recv(sockfd, buff, size, flag)) < 0 ||
		errno == EAGAIN || errno == EWOULDBLOCK
		|| errno == ETIMEDOUT){
		printf("TIMEOUT\n");
		return 0;
	}

	//check difference between received data and expected data
	if(expected_data != NULL && 
	strncmp(buff, expected_data, i)) {	
		printf("TIMEOUT\n");
		return 0;
	}
	return 1;
}

int send_(int sockfd, const char buff[], int size, int flag){
	int i;
	//check timeout occurrence
	if( (i = send(sockfd, buff, size, flag)) < 0||
		errno == EAGAIN || errno == EWOULDBLOCK
		|| errno == ETIMEDOUT){
		printf("TIMEOUT\n");
		return 0;
	}
	return 1;
}
//return the server ID active
int begin_active_socket(int argc, const char *argv[]){
	//initializing socket
	struct sockaddr_in serv_addr;
	int server_sck;

	//create socket
	if ((server_sck = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("Socket creation error \n");
		return 0;
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if (connect(server_sck, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
		printf("TIMEOUT\n");
		return 0;
	}

	// set default timeout
	struct timeval tv;
	tv.tv_sec = 2;
	setsockopt(server_sck, SOL_SOCKET, SO_RCVTIMEO,(struct timeval *)&tv,sizeof(struct timeval));
	setsockopt(server_sck, SOL_SOCKET, SO_SNDTIMEO,(struct timeval *)&tv,sizeof(struct timeval));

	return server_sck;
}

//return server ID passive
int begin_passive_socket(int argc, const char *argv[]){
	int server_sck;
	struct sockaddr_in address;
	
	//initializing passive socket
	if ((server_sck = socket(AF_INET,  SOCK_STREAM, 0)) == 0) { 
		perror("socket failed"); 
		exit(EXIT_FAILURE);
	}
	setsockopt(server_sck, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(atoi(argv[1]));

	if (bind(server_sck, (struct sockaddr *)&address,
		sizeof(address))){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
	// set default timeout
	struct timeval tv;
	// set up timeout by 1 second
	tv.tv_sec = 1;
	tv.tv_usec = 0;

	if (listen(server_sck, 10)){
		perror("listen");
		exit(EXIT_FAILURE);
	}
	return server_sck;
}