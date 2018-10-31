#include <stdlib.h>
#include <stdio.h>

int *alloc_array(int length){
	int *pointerArray;
	pointerArray = (int *) calloc(length, sizeof(int));
	if(pointerArray == 0 || pointerArray == NULL){
		printf("ERRO!\n Nao foi possivel alocar memoria solicitada!\n");
		exit(1);
	}
	return pointerArray;
}

void input_array_data(int *pointerArray, int length){
	int index, aux;
	for(index = 0; index < length; index++){
		printf("Idade do aluno %d: ", index+1);
		aux = 0;
		scanf("%d", &aux);
		pointerArray[index] = aux;
	}
}

float average(int length, int array[length]){
	float sum;
	int index;
	sum = 0.0;
	for(index = 0; index < length; index++){
		sum+=array[index];
	}
	return sum/((float) length);
}

int main(int argv, const char argc[]){
	int quantity;
	printf("Digite a quantidade de alunos para a turma: ");
	scanf("%d", &quantity);	
	
	int *students;
	students = alloc_array(quantity);
	input_array_data(students, quantity);
	
	float averageAge;
	averageAge = average(quantity, students);
	printf("\nMedia das idades: %f\n", averageAge);
	free(students);
	return 0;
}
