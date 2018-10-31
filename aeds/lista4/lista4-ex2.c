#include <stdio.h>
#include <stdlib.h>

int divisão(int numerador, int denominador){
	int quociente;
	for(quociente = 0; numerador >= denominador; quociente++){
		numerador -= denominador;
	}
	int resto = numerador;
	return quociente;

}

int main(){

}