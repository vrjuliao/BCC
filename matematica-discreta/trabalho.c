/**********************************************************
*   Matematica Discreta                                   *
*   Professor Antonio Alfredo Ferreira Loureiro           *
*                                                         *
*   Trabalho Pratico 2018/1 - Relacoes Binarias           *
*   Nome: Vinicius Juliao Ramos                           *
*   Matricula: 2018054630                                 *
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

#define ELEMENTS_NUMBER_ERROR -1
#define MOUNT_GRAPH_MATRIX_ERROR -2
#define READ_2UPLAS_ERROR -3
#define GET_ELEMENTS_ERROR -4
#define MAIN_JUMPER 1
#define SECONDARY_JUMPER 0


jmp_buf mainJumper, secondaryJumper;
void printError(char *errorMessage, int errorCode, int typeJumper){
	//recebe uma string contendo a mensagem de erro
	//imprime a mensagem
	printf("ERROR!\n");
	printf("%s",errorMessage);
	printf("\n");
	if(typeJumper == MAIN_JUMPER)
		longjmp(mainJumper, errorCode);
	else
		longjmp(secondaryJumper, errorCode);
}

void freeMatrix(int **matrix, int linesNumber){
	int indexI;
	if(linesNumber>0){
		for(indexI = 0; indexI < linesNumber; indexI++){
			free(matrix[indexI]);
		}
	}
	if(matrix != NULL)
		free(matrix);
}

int readNumber(FILE *filePointer, int initialNumber){
	char ch;
	ch = fgetc(filePointer);
	if(ch == ' ' || ch == '\n' || feof(filePointer)) {
		return initialNumber;
	} else if(ch > '9' || ch < '0'){
		printError("Formato Incorreto! \nLeia as orientacoes do arquivo em leiame.txt", GET_ELEMENTS_ERROR, SECONDARY_JUMPER);
	} else{
		return readNumber(filePointer,(initialNumber*10) + (ch - '0'));
	}
}

int getNumber(FILE *filePointer){
	char ch;
	ch = fgetc(filePointer);
	if(ch == ' ' || ch == '\n' || ch == EOF || ((ch < '0' || ch > '9') && ch != '-')){
		printError("Formato Incorreto! \nLeia as orientacoes do arquivo em leiame.txt", GET_ELEMENTS_ERROR, SECONDARY_JUMPER);
		return 0;
	} else if(ch == '-'){
		return getNumber(filePointer) * (-1);
	} else {
		return readNumber(filePointer, ch - '0');
	}
}

char getLastReadChar(FILE *filePointer){
	char isEOF, lastChar, ch;
	fseek(filePointer, -1, SEEK_CUR);
	lastChar = fgetc(filePointer);
	isEOF = fgetc(filePointer);

	//obersevando se é fim de arquivo
	if(isEOF == EOF || lastChar == EOF){
		ch = EOF;
	} else {
		ch = lastChar;
		fseek(filePointer, -1, SEEK_CUR);
	}
	return ch;
}

void getElements(FILE *filePointer, int *elements, int size, int canEqualsElements){
	int index, aux;
	for(index = 0; index < size; index++){
		aux = getNumber(filePointer);
		if(canEqualsElements == 1){
			*(elements + index) = aux;			
		} else {
			int indexI;
			for(indexI = 0; indexI < index; indexI++){
				if(elements[indexI] == aux){
					index--;
					break;
				}
			}
			if(indexI == index){
				*(elements + index) = aux;			
			}
		}
	}

	//pegando o ultimo caracter da linha lida
	char endChar;
	endChar = getLastReadChar(filePointer);
	
	//Valida se a linha está escrita corretamente
	// se o numero de ementos lidos nao é maior ou menor que 'size'
	if(endChar != '\n' && endChar != EOF){
		printError("Formato Incorreto! \nLeia as orientacoes do arquivo em leiame.txt", GET_ELEMENTS_ERROR, SECONDARY_JUMPER);
	}
}

int **new2ulpa(int **oldMatrix, int *length){
	(*length)++;
	if(*length > 1){
		oldMatrix = (int **)realloc(oldMatrix, (*length)*sizeof(int *));
	} else {
		oldMatrix = (int **) calloc(*length, sizeof(int *));
	}

	oldMatrix[(*length)-1] = calloc(2, sizeof(int));
	return oldMatrix;
}

int **read2uplas(FILE *filePointer, int *length){
	int **uplas;
	if(setjmp(secondaryJumper) == 0){
		while(getLastReadChar(filePointer) != EOF){
			uplas = new2ulpa(uplas, length);

			getElements(filePointer, *(uplas+((*length)-1)), 2, 1);
		}
		return uplas;
	} else {
		freeMatrix(uplas, *length);
		longjmp(mainJumper, GET_ELEMENTS_ERROR);
	}

}

int **addNewElementOn2upla(int **oldMatrix, int *length, int elementX, int elementY){
	oldMatrix = new2ulpa(oldMatrix, length);
	oldMatrix[(*length)-1][0] = elementX;
	oldMatrix[(*length)-1][1] = elementY;

	return oldMatrix;
}

//encontra o indice em quem 'searchedElement' está dentro do conjunto 'elements'
//caso nao encontre o valor do indice de 'searchedElement', retorna um erro e sai do programa
int getIndexInArray(int searchedElement, int *elements, int elementsNumber){
	int index, position;
	position = -1;
	for(index = 0; index < elementsNumber; index++){
		if(elements[index] == searchedElement){
			position = index;
			return position;
		}
	}
	if(position == -1){
		char errorMessage[1];
		sprintf(errorMessage, "O elemento %d nao esta presente no conjunto considerado", searchedElement);
		printError(errorMessage, MOUNT_GRAPH_MATRIX_ERROR, SECONDARY_JUMPER);
	}
}

int **mountGraphMatix(int *elements, int elementsNumber, int **relation, int relationLength){
	int **graphMatrix, indexI, indexJ, elNum;
	elNum = elementsNumber;
	if(setjmp(secondaryJumper) == 0){
		//alocando a espaço para a matriz
		graphMatrix = (int **) calloc(elementsNumber, sizeof(int *));
		for(indexI = 0; indexI < elementsNumber; indexI++){
			graphMatrix[indexI] = (int *) calloc(elementsNumber, sizeof(int));
			//zera todos os elementos da matriz
			for(indexJ = 0; indexJ < elementsNumber; indexJ++){
				graphMatrix[indexI][indexJ] = 0;
			}
		}

		//adiciona valor 1 à todas as posições correspondentes à relação
		int positionX, positionY;
		for(indexI = 0; indexI < relationLength; indexI++){
			positionX = getIndexInArray(relation[indexI][0], elements, elementsNumber);
			positionY = getIndexInArray(relation[indexI][1], elements, elementsNumber);
			graphMatrix[positionX][positionY] = 1;
		}
		return graphMatrix;
	} else {
		freeMatrix(graphMatrix, elNum);
		longjmp(mainJumper, MOUNT_GRAPH_MATRIX_ERROR);
	}
}

int **getTransitiveSubset(int **graphMatrix, int elementsNumber, int **initialSubset, int *lengthOfInitialSubset){
	int indexI, indexJ, indexK, positionX, positionY, findElement;
	findElement = 0;
	int valueIJ, valueJK, valueIK;
	for(indexI = 0; indexI < elementsNumber; indexI++){
		for(indexJ = 0; indexJ < elementsNumber; indexJ++){
			for(indexK = 0; indexK < elementsNumber; indexK++){
				valueIJ = graphMatrix[indexI][indexJ];
				valueJK = graphMatrix[indexJ][indexK];
				valueIK = graphMatrix[indexI][indexK];
				if(valueIJ && valueJK && !valueIK){
					initialSubset = addNewElementOn2upla(initialSubset, lengthOfInitialSubset, indexI, indexK);
					graphMatrix[indexI][indexK] = 1;
					findElement = 1;
				}
			}
		}
	}
	if(findElement)
		return getTransitiveSubset(graphMatrix, elementsNumber, initialSubset, lengthOfInitialSubset);
	else
		return initialSubset;
}

//retorna a matriz de 2uplas com o complemento do fecho transitivo
int **confirmTransitivity(int **graphMatrix, int elementsNumber, int **initialSubset, int *lengthOfInitialSubset){
	//cria copia da matriz de relações 
	//add à matriz de relações os elementos do fecho transitivo
	int **graphMatrixTmp, indexI, indexJ;
	//alocando a espaço para a matriz
	graphMatrixTmp = (int **) calloc(elementsNumber, sizeof(int *));
	for(indexI = 0; indexI < elementsNumber; indexI++){
		graphMatrixTmp[indexI] = (int *) calloc(elementsNumber, sizeof(int));
		
		for(indexJ = 0; indexJ < elementsNumber; indexJ++){
			graphMatrixTmp[indexI][indexJ] = graphMatrix[indexI][indexJ];
		}
	}
	int positionX, positionY;
	for(indexI = 0; indexI < *lengthOfInitialSubset; indexI++){
		positionX = initialSubset[indexI][0];
		positionY = initialSubset[indexI][1];
		graphMatrixTmp[positionX][positionY] = 1;
	}

	//valida recursivamente se graphMatrixTmp nao necessita mais de elementos que complementem sua transitividade
	initialSubset = getTransitiveSubset(graphMatrixTmp, elementsNumber, initialSubset, lengthOfInitialSubset);

	//liberar espaço da matriz criada
	freeMatrix(graphMatrixTmp, elementsNumber);
	
	return initialSubset;
}

void print2uplas(char *propertyName, int *elements, int **subset, int subsetLength){
	printf("%s: ", propertyName);
	if(subsetLength == 0){
		printf("V\n");
	} else {
		printf("F\n          ");
		int indexI, elementX, elementY;
		for(indexI = 0; indexI < subsetLength; indexI++){
			elementX = elements[subset[indexI][0]];
			elementY = elements[subset[indexI][1]];
			printf("(%d,%d); ", elementX, elementY);
		}
		printf("\n");
	}
}

void printAntissymmetry(char *propertyName, int *elements, int **subset, int subsetLength){
	printf("%s: ", propertyName);
	if(subsetLength == 0){
		printf("V\n");
	} else {
		printf("F\n          ");
		int indexI, elementX, elementY;
		for(indexI = 0; indexI < subsetLength; indexI+=2){
			elementX = elements[subset[indexI][0]];
			elementY = elements[subset[indexI][1]];
			printf("(%d,%d) e ", elementX, elementY);
			elementX = elements[subset[indexI+1][0]];
			elementY = elements[subset[indexI+1][1]];
			printf("(%d,%d); ", elementX, elementY);
		}
		printf("\n");
	}
}

char getOrdemEquivalencia(int transitiveSubsetLength, int simetricSubsetLength, int reflectiveSubsetLength){
	if(transitiveSubsetLength > 0
	|| simetricSubsetLength > 0
	|| reflectiveSubsetLength > 0) return 'F';
	else return 'V';
}

char getOrdemParcial(int transitiveSubsetLength, int antissimetricSubsetLength, int reflectiveSubsetLength){
	if(transitiveSubsetLength > 0
	|| antissimetricSubsetLength > 0
	|| reflectiveSubsetLength > 0) return 'F';
	else return 'V';
}

void printSubset(int **relations, int relationsLength, int *elements, int **subset, int subsetLength){
	int index, elementY, elementX;
	if(relationsLength > 0){
		printf("{(%d,%d)", relations[0][0], relations[0][1]);
		for(index = 1; index < relationsLength; index++){
			printf(", (%d,%d)", relations[index][0], relations[index][1]);
		}
		index = 0;
	} else {
		elementX = elements[subset[0][0]];
		elementY = elements[subset[0][1]];
		printf("{(%d,%d)", elementX, elementX);
		index = 1;
	}
	for(; index < subsetLength; index ++){
		elementX = elements[subset[index][0]];
		elementY = elements[subset[index][1]];
		printf(", (%d,%d)", elementX, elementY);
	}
	printf("}");

}

void verifyRelations(int *elements, int **graphMatrix, int elementsNumber, int **relations, int relationsLength){
	//complemento dos fechos que serão preenchidos com os indices da matriz 'graphMatrix'
	//depois esses indices serão convertidos nos verdadeiros elementos que estão no vetor 'elements' na MAIN
	int **reflectiveSubset, **transitiveSubset, **irreflectiveSubset,
	**simetricSubset, **antissimetricSubset;

	
	//tamanho das matrizes de tuplas
	//para validar se existe algum elemento dentro dos fechos, basta saber
	//se o tamanho de cada matriz de fecho é maior que 0
	int reflectiveSubsetLength, transitiveSubsetLength, irreflectiveSubsetLength,
	simetricSubsetLength, antissimetricSubsetLength;

	reflectiveSubsetLength = transitiveSubsetLength = irreflectiveSubsetLength =
	simetricSubsetLength = antissimetricSubsetLength  = 0;

	int indexI, indexJ, indexK;
	int valueIJ, valueJK, valueIK;
	for(indexI = 0; indexI < elementsNumber; indexI++){
		//verifica a existencia de alguma tupla reflexiva
		//caso seja exista, adiciona os indices como parametro no fecho irreflexivo
		//se não existir o elemento reflexivo, entao adiciona ele dentro do fecho reflexivo
		if(graphMatrix[indexI][indexI] == 1){
			irreflectiveSubset = addNewElementOn2upla(irreflectiveSubset, &irreflectiveSubsetLength, indexI, indexI);
		} else {
			reflectiveSubset = addNewElementOn2upla(reflectiveSubset, &reflectiveSubsetLength, indexI, indexI);
		}
		
		for(indexJ = 0; indexJ < elementsNumber; indexJ++){
			// descobrindo a simetria
			// para os elementos assimetricos, o complemento do fecho contará apenas com os elementos que nao estão em irreflectiveSubset, ao imprimir basta juntar os dois complementos de fecho irreflective + antissimetric
			// neste caso acima os elementos serão adicionados duplamente(x,y)(y,x) e depois (y,x)(x,y), para que estes fiquem numa boa ordem para a imprimir na tela. basta imprimir metade dos elementos dessas matrizes
			if(graphMatrix[indexI][indexJ] == 1
				&& graphMatrix[indexJ][indexI] == 1){
				//faz a validação apenas pegando os valores da matriz triangular superior
				// a matriz que identifica uma antissimetria, tem sua triagular superior espelhada na triangular inferior
				if(indexI < indexJ){
					//dupla adicao no fecho antissimetrico
					antissimetricSubset = addNewElementOn2upla(antissimetricSubset, &antissimetricSubsetLength, indexI, indexJ);
					antissimetricSubset = addNewElementOn2upla(antissimetricSubset, &antissimetricSubsetLength, indexJ, indexI);
				}
			} else if (graphMatrix[indexI][indexJ] != graphMatrix[indexJ][indexI] && graphMatrix[indexI][indexJ] == 0){
				simetricSubset = addNewElementOn2upla(simetricSubset, &simetricSubsetLength, indexI, indexJ);
			}

			//validando transitividade
			for(indexK = 0; indexK < elementsNumber; indexK++){
				valueIJ = graphMatrix[indexI][indexJ];
				valueJK = graphMatrix[indexJ][indexK];
				valueIK = graphMatrix[indexI][indexK];
				if(valueIJ && valueJK && !valueIK){
					transitiveSubset = addNewElementOn2upla(transitiveSubset, &transitiveSubsetLength, indexI, indexK);
				}
			}
		}
	}
	if(transitiveSubsetLength > 0){
		transitiveSubset = confirmTransitivity(graphMatrix, elementsNumber, transitiveSubset, &transitiveSubsetLength);
	}


	//imprimir as relações
	printf("Propriedades\n");
	printf("1. ");
		print2uplas("Reflexiva", elements, reflectiveSubset, reflectiveSubsetLength);
	printf("2. ");
		print2uplas("Irreflexiva", elements, irreflectiveSubset, irreflectiveSubsetLength);
	printf("3. ");
		print2uplas("Simetrica", elements, simetricSubset, simetricSubsetLength);
	printf("4. ");
		printAntissymmetry("Antissimetrica", elements, antissimetricSubset, antissimetricSubsetLength);
	char isAssimetric;
	isAssimetric = antissimetricSubsetLength + irreflectiveSubsetLength > 0 ? 'F' : 'V';
	printf("5. ");
		printf("Assimetrica: %c\n", isAssimetric);
	printf("6. ");
		print2uplas("Transitiva", elements, transitiveSubset, transitiveSubsetLength);

	char relacaoEquivalencia, relacaoParcial;
	relacaoEquivalencia = getOrdemEquivalencia(transitiveSubsetLength, simetricSubsetLength, reflectiveSubsetLength);
	printf("\nRelacao de equivalencia: %c", relacaoEquivalencia);
	relacaoParcial = getOrdemParcial(transitiveSubsetLength, antissimetricSubsetLength, reflectiveSubsetLength);
	printf("\nRelacao de ordem parcial: %c\n", relacaoParcial);

	//liberando espaço alocado nas matrizes
	if(reflectiveSubsetLength > 0){
		printf("\nFecho reflexivo da relacao = ");
		printSubset(relations, relationsLength, elements, reflectiveSubset, reflectiveSubsetLength);	
		freeMatrix(reflectiveSubset, reflectiveSubsetLength);
	}
	if(simetricSubsetLength > 0) {
		printf("\nFecho simetrico da relacao = ");
		printSubset(relations, relationsLength, elements, simetricSubset, simetricSubsetLength);
		freeMatrix(simetricSubset, simetricSubsetLength);
	}
	if(transitiveSubsetLength > 0){
		printf("\nFecho transitivo da relacao = ");
		printSubset(relations, relationsLength, elements, transitiveSubset, transitiveSubsetLength);
		freeMatrix(transitiveSubset, transitiveSubsetLength);
	}
	if(irreflectiveSubsetLength > 0) freeMatrix(irreflectiveSubset, irreflectiveSubsetLength);
	if(antissimetricSubsetLength > 0) freeMatrix(antissimetricSubset, antissimetricSubsetLength);
	printf("\n");
}

int main(int argc, char *argv[]){
	FILE *filePointer;
	filePointer = fopen("relacao.txt","r");
	
	//validar se o arquivo foi aberto com sucesso
	if(filePointer == NULL){
		printf("Erro! \nArquivo \"relacao.txt\" nao encontrado.\n");
		return 0;
	}

	int elementsNumber;
	int *elements, **relation, **graphMatrix, relationLength;
	relationLength = 0;
	switch(setjmp(mainJumper)){
		case 0:
			elementsNumber = getNumber(filePointer);
			if(elementsNumber > 50 || elementsNumber < 1){
				printError("Erro. Quantidade de elementos invalida!", ELEMENTS_NUMBER_ERROR, MAIN_JUMPER);
			}
			elements = calloc(elementsNumber, sizeof(int));
			if(setjmp(secondaryJumper)==0){
				getElements(filePointer, elements, elementsNumber, 0);
			} else {
				longjmp(mainJumper, GET_ELEMENTS_ERROR);
			}
			
			relation = read2uplas(filePointer, &relationLength);
			graphMatrix = mountGraphMatix(elements, elementsNumber, relation, relationLength);
			// printf("here\n");
			verifyRelations(elements, graphMatrix, elementsNumber, relation, relationLength);

			freeMatrix(graphMatrix, elementsNumber);
			if(relationLength > 0)freeMatrix(relation, relationLength);
			free(elements);
		break;

		case ELEMENTS_NUMBER_ERROR:
		break;

		case MOUNT_GRAPH_MATRIX_ERROR:
			if(relationLength > 0) freeMatrix(relation, relationLength);
		case READ_2UPLAS_ERROR:
		case GET_ELEMENTS_ERROR:
			free(elements);
		break;
	}	
	fclose(filePointer);
	return 0;
}