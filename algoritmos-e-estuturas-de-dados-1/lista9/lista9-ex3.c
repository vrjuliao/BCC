#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	FILE *arquivoPrimos, *arquivoOutros, *arquivoNumeros;
	arquivoPrimos = fopen("primos.txt", "w");
	arquivoOutros = fopen("outros.txt", "w");
	arquivoNumeros = fopen("numeros.txt", "r");
	if(arquivoNumeros == NULL)
		return 0;

	int num, primo, indexJ;
	while(!feof(arquivoNumeros)){
		fscanf(arquivoNumeros, "%d", &num);
		
		primo = 1;
		for(indexJ = 2; indexJ < num; indexJ++){
			if(num%indexJ == 0){
				primo = 0;
				break;
			}
		}
		if(primo){
			fprintf(arquivoPrimos, "%d\n", num);
		} else {
			fprintf(arquivoOutros, "%d\n", num);
		}
	}
	fclose(arquivoPrimos);
	fclose(arquivoOutros);
	fclose(arquivoNumeros);
	return 0;
}