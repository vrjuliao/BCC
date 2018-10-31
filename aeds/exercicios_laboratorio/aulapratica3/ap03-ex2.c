#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	int num1, num2;
	printf("Digite dois numeros:\n");
	scanf("%d %d", &num1, &num2);

	int rest;
	while(num2 != 0){
		rest = num1%num2;
		num1 = num2;
		num2 = rest;
	}
	printf("MDC: %d\n", num1);
	return 0;
}