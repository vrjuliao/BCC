/**
e' possivel usar apenas uma variavel na implementacao
basta somar na propria variavel 'd', o valor resultante da aplicacao dos juros
d+= d*0.01
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	float d, p, s, t;
	d = 500.0; //deposito inicial
	
	//apos o primeiro mes
	//d+=d*0.01;
	p = d + d*0.01;

	//apos o segundo mes
	//d+=d*0.01;
	s = p + p*0.01;

	//apos o terceiro mes
	//d+=d*0.01;
	t = s + s*0.01;

	// printf("Valor da conta = %0.2f\n", d);
	printf("Valor da conta = %0.2f\n", t);
	return 0;
}