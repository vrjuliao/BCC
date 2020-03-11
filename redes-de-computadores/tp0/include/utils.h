#include <stdlib.h>
#include <errno.h>

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

int recv_(int sockfd, char buff[], int size, int flag){
	if(recv(sockfd, buff, size, flag) < 0 ||
		errno == EAGAIN || errno == EWOULDBLOCK
		|| errno == ETIMEDOUT){
		perror("TIMEOUT");
		return 0;
	}
	return 1;
}

int send_(int sockfd, const char buff[], int size, int flag){
	if(send(sockfd, buff, size, flag) < 0||
		errno == EAGAIN || errno == EWOULDBLOCK
		|| errno == ETIMEDOUT){
		perror("TIMEOUT");
		return 0;
	}
	return 1;
}