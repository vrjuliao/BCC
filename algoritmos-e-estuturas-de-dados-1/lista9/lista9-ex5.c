#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	FILE *arquivoDominio, *arquivoImagem;
	arquivoImagem = fopen("imagem.txt", "w");
	arquivoDominio = fopen("dominio.txt", "r");
	if(arquivoDominio == NULL)
		return 0;

	float a, b, c, d;
	scanf("%f %f %f %f", &a, &b, &c, &d);

	float num, resposta;
	while(!feof(arquivoDominio)){
		fscanf(arquivoDominio, "%f", &num);
		//ax 3 + bx 2 + cx + d
		resposta = (a * num * num * num) + (b * num * num) + (c * num) + d;
		fprintf(arquivoImagem, "%f\n", resposta);
	}
	fclose(arquivoImagem);
	fclose(arquivoDominio);
	return 0;
}