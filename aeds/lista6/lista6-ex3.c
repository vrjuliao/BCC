#include <stdio.h>
#include <stdlib.h>

float mediaAritmetica(float value1, float value2){
	return (value1 + value2)/2.0;
}

float percentual(int total, int value){
	return ((float)value/ (float) total) * 100.0;
}

void situacaoAluno(float mediaNotas){
	printf("Situacao: ");
	if(mediaNotas > 60.0){
		printf("Aluno aprovado.\n");
	} else {
		printf("Aluno reprovado.\n");
	}
}

int main(int argc, char *argv[]){
	int totalAulas, matriculaAluno, primeiraProva, 
		segundaProva, primeiroTrabalho, segundoTrabalho, 
		presencaAluno;

	printf("Total de aulas da turma: ");
	scanf("%d", &totalAulas);
	printf("Matricula do aluno: ");
	scanf("%d", &matriculaAluno);
	printf("Nota da primeira prova: ");
	scanf("%d", &primeiraProva);
	printf("Nota da segunda prova: ");
	scanf("%d", &segundaProva);
	printf("Nota do primeiro trabalho: ");
	scanf("%d", &primeiroTrabalho);
	printf("Nota do segundo trabalho: ");
	scanf("%d", &segundoTrabalho);
	printf("Total de aulas assistidas pelo aluno: ");
	scanf("%d", &presencaAluno);
//matrícula, média das provas, 
//média dos trabalhos, média final, 
//situação do aluno e percentual de faltas do aluno.
	float mediaNotaProva;
	mediaNotaProva = mediaAritmetica((float) primeiraProva, (float) segundaProva);
	float mediaNotaTrabalho;
	mediaNotaTrabalho = mediaAritmetica((float) primeiroTrabalho, (float) segundoTrabalho);
	float mediaNotas;
	mediaNotas = mediaAritmetica(mediaNotaTrabalho, mediaNotaProva);

	printf("\n------Aluno------\n");
	printf("Matrícula: %d\n", matriculaAluno);
	printf("Média das provas: %0.2f\n", mediaNotaProva);
	printf("Média dos trabalhos: %0.2f\n", mediaNotaTrabalho);
	printf("Média final: %0.2f\n", mediaNotas);
	situacaoAluno(mediaNotas);
	printf("Percentual de faltas: %0.2f%%\n", 100.0-percentual(totalAulas, presencaAluno));
	return 0;
}