#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 51511
#define STUDENT 1
#define PROFESSOR 2

void get_keys(int argc, const char* argv[], const char **key1, const char **key2){
	if(argc != 3){
		perror("keys was not included in server execution");
		exit(EXIT_FAILURE);
	}

	*key1 = argv[1];
	*key2 = argv[2];
}

int type_of_key(char buffer[], const char *professor_key, const char *student_key){
	if(!(strncmp(buffer, professor_key, strlen(professor_key))))
		return PROFESSOR;
	if(!(strncmp(buffer, student_key, strlen(professor_key))))
		return STUDENT;
	else
		return -1;
}

int main(int argc, char const *argv[]){
	/* code */
	int server_sck, client_sck, read_value;
	struct sockaddr_in address;
	char buffer[1024] = {0};

	//getting initial keys
	const char *professor_key, *student_key;
	get_keys(argc, argv, &professor_key, &student_key);

	if ((server_sck = socket(AF_INET,  SOCK_STREAM, 0)) == 0) { 
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


	//put in loop
	if((client_sck = accept(server_sck, (struct sockaddr*)&address, sizeof(address))) < 0){
		perror("accept");
		exit(EXIT_FAILURE);
	}

	read_value = read(client_sck, buffer, 1024);
	int key;
	key = type_of_key(buffer, professor_key, student_key);

	if(key == -1){
		close(client_sck);
	} else if (key == PROFESSOR){
		//execute professor proccess
	} else {
		//execute student proccess
	}
	//send(client_sck, hello , strlen(hello) , 0 );
	return 0;
}