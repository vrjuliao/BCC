#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 51511
#define READY_LENGTH sizeof("READY")
#define INTEGER_MAX_LENGTH 8
#define OK_LENGTH sizeof("OK")

int main(int argc, const char* argv[]){
	int num;
	//execution param treatment
	if(argc==3){
		if(strlen(argv[1]) != 8){
			printf("Key must has 8 char\n");
			return -1;
		}
		num = atoi(argv[2]);
	} else {
		printf("ERROR: Execute without key param\n");
		return -1;
	}

	//initializing socket
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

	char buff[11];
	int read_value;
	read_value = recv(server_sck, buff, READY_LENGTH, 0);
	send(server_sck, argv[1], 8, 0);
	read_value = recv(server_sck, buff, OK_LENGTH, 0);
	read_value = recv(server_sck, buff, sizeof("MATRICULA"), 0);

	//send number
	int32_t conv;
	conv = htonl(num);
	char *data;
	data = (char*)&conv;
	int len;
	len = sizeof(conv);
	send(server_sck, data, len, 0);
	read_value = recv(server_sck, buff, OK_LENGTH, 0);

	close(server_sck);

	return 0;
}