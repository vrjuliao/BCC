#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "utils.h"

int main(int argc, const char* argv[]){
	// execution parameter treatment
	if(argc==4){
		if(strlen(argv[3]) != 8){
			printf("Key must has 8 char\n");
			return -1;
		}
	} else {
		printf("ERROR: incorrect params\n");
		return -1;
	}

	//initializing server connection
	int server_sck;
	if(!(server_sck = begin_active_socket(argc, argv))){
		return -1;	
	}
	
	int len;
	len = MAX_CHAR_ON_INT;
	char buff[len+1];

	if(!recv_(server_sck, buff, READY_LENGTH, 0, "READY")) exit(EXIT_FAILURE);
	if(!send_(server_sck, argv[3], KEY_LENGTH, 0)) exit(EXIT_FAILURE);
	
	int i;
	//while not match '\0' in buffer, keep receiving data
	while(1){
		memset(buff, 0, (len+1)*sizeof(char)); 
		i = recv(server_sck, buff, len+1, 0);

		printf("%s", buff);
		if(i < 0) exit(EXIT_FAILURE);
		else if (i>0 && buff[i-1]=='\0') break;
	}

	if(!send_(server_sck, "OK", OK_LENGTH, 0)) exit(EXIT_FAILURE);
	close(server_sck);
	return 0;
}