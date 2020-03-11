#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "utils.h"

// generate keys on ascii only alpha numeric characters
void get_keys(char *professor, char *student){
	srand(time(NULL));
	int i, r;
	for(i=0; i<KEY_LENGTH; i++){
		r = (rand()%75)+48;
		if((r>=58 && r<=64) || (r>=91 && r<=96)){
			i--;
		} else {
			professor[i] = r;
		}
	}

	for(i=0; i<KEY_LENGTH; i++){
		r = (rand()%75)+48;
		if((r>=58 && r<=64) || (r>=91 && r<=96)){
			i--;
		} else {
			student[i] = r;
		}
	}
}

//compare type of key
int type_of_key(char buffer[], const char *professor_key, const char *student_key){
	if(!(strncmp(buffer, professor_key, KEY_LENGTH)))
		return PROFESSOR;
	if(!(strncmp(buffer, student_key, KEY_LENGTH)))
		return STUDENT;
	else 
		return -1;
}

int professor_proccess(int *students, int n, int client_sck){
	int len;
	len = n*(MAX_CHAR_ON_INT+1);
	char buff[len+1];
	memset(buff, '\0', (len+1)*sizeof(char));
	// for each student, aggegreat a string with the number + '\n'
	int i;
	for(i=0; i<n; i++){
		sprintf(buff+((int)strlen(buff)), "%d%c", students[i], '\n');
	}
	if(!send_(client_sck, buff, (len+1)*sizeof(char), MSG_WAITALL)) return 0;
	if(!recv_(client_sck, buff, OK_LENGTH, MSG_WAITALL)) return 0;
	return 1;
}

int student_proccess(int client_sck, int students[], int *n_students){
	if(!send_(client_sck, "OK", OK_LENGTH, MSG_WAITALL)) return 0;
	if(!send_(client_sck, "MATRICULA", sizeof("MATRICULA"), MSG_WAITALL)) return 0;

	// casting network data to integer
	int32_t ret;
	char *data = (char*)&ret;
	int left = sizeof(ret);
	if(!recv_(client_sck, data, left, 0)) return 0;

	if(!send_(client_sck, "OK", OK_LENGTH, 0)) return 0;
	students[*n_students] = ntohl(ret);
	(*n_students)++;
	return 1;
}

int main(int argc, char const *argv[]){
	int server_sck, client_sck, len;
	struct sockaddr_in address;

	//getting initial keys
	char professor_key[KEY_LENGTH+1] = {'\0'};
	char student_key[KEY_LENGTH+1] = {'\0'};
	get_keys(professor_key, student_key);
	printf("%s\n", professor_key);
	printf("%s\n", student_key);

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

	char key[KEY_LENGTH];

	int students[MAX_STUDENTS];
	int n_students;
	n_students = 0;
	// set up timeout by 1 second
	setsockopt(server_sck, SOL_SOCKET, SO_RCVTIMEO,(struct timeval *)&tv,sizeof(struct timeval));
	setsockopt(server_sck, SOL_SOCKET, SO_SNDTIMEO,(struct timeval *)&tv,sizeof(struct timeval));
	while(1){
		len = sizeof(address);
		if((client_sck = accept(server_sck, (struct sockaddr*)&address, (socklen_t*)&len)) < 0){
			perror("TIMEOUT");
			continue;
		}

		
		if(!send_(client_sck, "READY", READY_LENGTH, MSG_WAITALL)){
			close(client_sck);
			continue;
		}
		
		//read key
		if(!recv_(client_sck, key, sizeof(key), MSG_WAITALL)){
			close(client_sck);
			continue;
		}
		int type_key;
		type_key = type_of_key(key, professor_key, student_key);

		if(type_key == STUDENT){
			//execute student proccess
			if(!student_proccess(client_sck, students, &n_students)){
				close(client_sck);
				continue;
			}
		} else if (type_key == PROFESSOR){
			//execute professor proccess
			if(!professor_proccess(students, n_students, client_sck)){
				close(client_sck);
				continue;
			}
		}
		close(client_sck);
	}
	return 0;
}