#include <stdlib.h>
#include <errno.h>

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

int recv_(int sockfd, char buff[], int size, int flag){
	int i;
	if( (i = recv(sockfd, buff, size, flag)) < 0 ||
		errno == EAGAIN || errno == EWOULDBLOCK
		|| errno == ETIMEDOUT){
		printf("TIMEOUT");
		return 0;
	}
	// printf("recv: %d %d\n", i, size);
	return 1;
}

int send_(int sockfd, const char buff[], int size, int flag){
	int i;
	if( (i = send(sockfd, buff, size, flag)) < 0||
		errno == EAGAIN || errno == EWOULDBLOCK
		|| errno == ETIMEDOUT){
		printf("TIMEOUT");
		return 0;
	}
	// printf("send: %d %d\n", i, size);
	return 1;
}