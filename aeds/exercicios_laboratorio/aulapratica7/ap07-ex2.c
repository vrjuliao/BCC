#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char *argv[]){
	int array[10];
	int index, less, lessNumberPosition;
	printf("Elemento %d: ", 1);
	scanf("%d", &less);
	array[0] = less;
	lessNumberPosition = 0;
	
	for(index = 0; index < 10; index++){
		printf("Elemento %d: ", index);
		scanf("%d", &array[index]);
		if(less > array[index]){
			less = array[index];
			lessNumberPosition = index;
		}
	}
	
	printf("O menor elemento de N é: %d\n", less);
	printf("E sua posicao dentro do vetor é: %d\n", lessNumberPosition);
	
	return 0;
}
