#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	FILE *arquivoDominio, *arquivoImagem;
	arquivoImagem = fopen("imagem.txt", "w");
	arquivoDominio = fopen("dominio.txt", "r");
	if(arquivoDominio == NULL)
		return 0;

	float num, resposta;
	while(!feof(arquivoDominio)){
		fscanf(arquivoDominio, "%f", &num);
		//x 2 - 5x + 1
		resposta = (num * num) - (5 * num) + 1.0;
		fprintf(arquivoImagem, "%f\n", resposta);
	}
	fclose(arquivoImagem);
	fclose(arquivoDominio);
	return 0;
}