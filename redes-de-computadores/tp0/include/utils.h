#include <stdlib.h>

#include <sys/socket.h>

#define PORT 51511
#define STUDENT 1
#define PROFESSOR 2
#define KEY_LENGTH 8
#define MAX_STUDENTS 256

#define MAX_CHAR_ON_INT 10
#define READY_LENGTH sizeof("READY")
#define INTEGER_MAX_LENGTH 8
#define OK_LENGTH sizeof("OK")

void recv_(int sockfd, char buff[], int size, int flag){
	if(recv(sockfd, buff, size, flag) < 0){
		perror("TIMEOUT");
		exit(EXIT_FAILURE);
	}
}

void send_(int sockfd, const char buff[], int size, int flag){
	if(send(sockfd, buff, size, flag) < 0){
		perror("TIMEOUT");
		exit(EXIT_FAILURE);
	}
}