#include <stdio.h>
#include <stdlib.h>

int divisao(int *numerador, int *denominador){
	int quociente;
	for(quociente = 0; (*numerador) >= (*denominador); quociente++){
		(*numerador) -= (*denominador);
	}
	int resto = (*numerador);
	return quociente;

}

int main(){
	int a,b;
	a = 12;
	b = 4;
	printf("%d\n",divisao(&a, &b));
}