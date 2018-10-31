#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	FILE *arquivoResposta, *arquivoNumeros;
	arquivoResposta = fopen("resposta.txt", "w");
	arquivoNumeros = fopen("numeros.txt", "r");
	if(arquivoNumeros == NULL)
		return 0;

	int num, primo, indexJ;
	while(!feof(arquivoNumeros)){
		fscanf(arquivoNumeros, "%d", &num);
		// __fpurge(arquivoNumeros);
		
		primo = 1;
		for(indexJ = 2; indexJ < num; indexJ++){
			if(num%indexJ == 0){
				primo = 0;
				break;
			}
		}
		if(primo){
			fprintf(arquivoResposta, "primo\n");
		} else {
			fprintf(arquivoResposta, "nao primo\n");
		}
	}
	fclose(arquivoResposta);
	fclose(arquivoNumeros);
	return 0;
}