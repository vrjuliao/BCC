#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "utils.h"

int main(int argc, const char* argv[]){
	// execution parameter treatment
	if(argc==2){
		if(strlen(argv[1]) != 8){
			printf("Key must has 8 char\n");
			return -1;
		}
	} else {
		printf("ERROR: Execute without key param\n");
		return -1;
	}

	// initialing socket
	struct sockaddr_in serv_addr;
	int server_sck;

	if ((server_sck = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("Socket creation error \n");
		return -1;
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(PORT);

	if (connect(server_sck, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
		printf("TIMEOUT\n");
		return -1;
	}

	int len;
	// max length of a string with 256 students
	//      where each key has 10 characters
	len = (MAX_STUDENTS*(MAX_CHAR_ON_INT+1))+1;
	char buff[len];
	
	recv_(server_sck, buff, READY_LENGTH, 0);
	send_(server_sck, argv[1], 8, 0);
	recv_(server_sck, buff, len, 0);

	printf("%s", buff);
	send_(server_sck, "OK", OK_LENGTH, 0);
	close(server_sck);
	return 0;
}