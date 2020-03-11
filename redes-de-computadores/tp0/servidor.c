#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 51511
#define STUDENT 1
#define PROFESSOR 2
#define KEY_LENGTH 8
#define MAX_STUDENTS 256

#define MAX_CHAR_ON_INT 10

void get_keys(int argc, const char* argv[], const char **key1, const char **key2){
	if(argc != 3){
		perror("keys was not included in server execution");
		exit(EXIT_FAILURE);
	}

	if(strlen(argv[1])!=8 || strlen(argv[2])!=8){
		perror("keys must has 8 char");
		exit(EXIT_FAILURE);	
	}
	*key1 = argv[1];
	*key2 = argv[2];
}

int type_of_key(char buffer[], const char *professor_key, const char *student_key){
	if(!(strncmp(buffer, professor_key, KEY_LENGTH)))
		return PROFESSOR;
	if(!(strncmp(buffer, student_key, KEY_LENGTH)))
		return STUDENT;
	else 
		return -1;
}

void professor_proccess(int *students, int n, int client_sck){
	int len;
	len = n*(MAX_CHAR_ON_INT+1);
	char buff[len+1];
	memset(buff, '\0', (len+1)*sizeof(char));
	int i;
	for(i=0; i<n; i++){
		sprintf(buff+((int)strlen(buff)), "%d%c", students[i], '\n');
	}
	i = send(client_sck, buff, (len+1)*sizeof(char), 0);
	recv(client_sck, "OK", sizeof("OK"), 0);
}

int student_proccess(int client_sck){
	int read_value;
	send(client_sck, "OK", sizeof("OK"), 0);
	send(client_sck, "MATRICULA", sizeof("MATRICULA"), 0);


	int32_t ret;
	char *data = (char*)&ret;
	int left = sizeof(ret);
	read_value = recv(client_sck, data, left, 0);

	send(client_sck, "OK", sizeof("OK"), 0);
	return ntohl(ret);
}

int main(int argc, char const *argv[]){
	int server_sck, client_sck, read_value, len;
	struct sockaddr_in address;

	//getting initial keys
	const char *professor_key, *student_key;
	get_keys(argc, argv, &professor_key, &student_key);

	//initializing passive socket
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

	// set default timeout
	struct timeval tv;
	tv.tv_sec = 1;
	setsockopt(server_sck, SOL_SOCKET, SO_RCVTIMEO,(struct timeval *)&tv,sizeof(struct timeval));
	setsockopt(server_sck, SOL_SOCKET, SO_SNDTIMEO,(struct timeval *)&tv,sizeof(struct timeval));

	char key[KEY_LENGTH];

	int students[MAX_STUDENTS];
	int n_students;
	n_students = 0;
	while(1){
		len = sizeof(address);
		if((client_sck = accept(server_sck, (struct sockaddr*)&address, (socklen_t*)&len)) < 0){
			perror("accept");
			exit(EXIT_FAILURE);
		}
		send(client_sck, "READY", sizeof("READY"), 0);
		
		//read key
		read_value = recv(client_sck, key, sizeof(key), 0);
		int type_key;
		type_key = type_of_key(key, professor_key, student_key);

		if(type_key == STUDENT){
			//execute student proccess
			students[n_students] = student_proccess(client_sck);
			n_students++;
		} else if (type_key == PROFESSOR){
			//execute professor proccess
			professor_proccess(students, n_students, client_sck);
		}
		close(client_sck);
	}
	return 0;
}