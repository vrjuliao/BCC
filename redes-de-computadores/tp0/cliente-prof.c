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
#define OK_LENGTH sizeof("ok")

#define MAX_STUDENTS 256
#define MAX_CHAR_ON_INT 10

int main(int argc, const char* argv[]){
	if(argc==2){
		if(strlen(argv[1]) != 8){
			printf("Key must has 8 char\n");
			return -1;
		}
	} else {
		printf("ERROR: Execute without key param\n");
		return -1;
	}

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
		printf("Connection Failed \n");
		return -1;
	}

	int len;
	len = (MAX_STUDENTS*(MAX_CHAR_ON_INT+1))+1;
	char buff[len];
	int read_value;
	read_value = read(server_sck, buff, READY_LENGTH);
	write(server_sck, argv[1], 8);
	int i, num;
	i=0;
	read_value = read(server_sck, buff, len*sizeof(char));
	char c;
	printf("%s", buff);
	write(server_sck, "OK", 2);
	close(server_sck);

	return 0;
}