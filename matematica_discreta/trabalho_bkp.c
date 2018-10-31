#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

void printError(char *errorMessage, void param){
	//recebe uma string contendo a mensagem de erro
	//imprime a mensagem
	printf("\nERROR!\n");
	if(param == -1)
		printf(errorMessage);
	else
		printf(errorMessage, param);
	printf("\n");
	//faz um GoTo para a linha da funcao main que libera toda memoria alocada
	goto FREE_MEMORY;
}

void freeMatrix(int **matrix, int linesNumber){
	int indexI;
	for(indexI = 0; indexI < linesNumber; indexI++){
		free(matrix[indexI]);
	}
	free(matrix);
}

int readNumber(FILE *filePointer, int initialNumber){
	char ch;
	ch = fgetc(filePointer);
	// printf("%c\n", ch);
	if(ch == ' ' || ch == '\n' || feof(filePointer)) {
		return initialNumber;
	} else if(ch > '9' || ch < '0'){
		printf("readNumber ERROR\n");
		printf("Erro. Formato Incorreto! \nLeia as orientacoes do arquivo em readme.md");
		exit(1);
	} else{
		return readNumber(filePointer,(initialNumber*10) + (ch - '0'));
	}
}

int getNumber(FILE *filePointer){
	// count++;
	char ch;
	ch = fgetc(filePointer);
	if(ch == ' ' || ch == '\n' || ch == EOF || ((ch < '0' || ch > '9') && ch != '-')){
		printf("%d", ch);
		printf("getNumber ERROR\n");
		printf("Erro. Formato Incorreto! \nLeia as orientacoes do arquivo em readme.md\n");
		exit(1);
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
	// printf("%d\n", lastChar);
	isEOF = fgetc(filePointer);
	// printf("%d\n", isEOF);
	// fseek(filePointer, -1, SEEK_CUR);

	//obersevando se é fim de arquivo
	if(isEOF == EOF || lastChar == EOF){
		ch = EOF;
		// fseek(filePointer, -2, SEEK_CUR);
	} else {
		ch = lastChar;
		fseek(filePointer, -1, SEEK_CUR);
	}
	// ch = isEOF == EOF || lastChar == EOF ? EOF : lastChar;
	// printf("%d\n", ch);
	// ch = feof(filePointer) ?  EOF : ch;
	return ch;
}

void getElements(FILE *filePointer, int *elements, int size){
	int index, aux;
	for(index = 0; index < size; index++){
		aux = getNumber(filePointer);
		*(elements + index) = aux;
	}

	//pegando o ultimo caracter da linha lida
	// fseek(filePointer, -1, SEEK_CUR);
	char endChar;
	endChar = getLastReadChar(filePointer);
	
	//Valida se a linha está escrita corretamente
	// se o numero de ementos lidos nao é maior ou menor que 'size'
	if(endChar != '\n' && endChar != EOF){
		printf("Erro. getElements ERROR\n");
		printf("Erro. Formato Incorreto! \nLeia as orientacoes do arquivo em readme.md\n");
		exit(1);
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
	// fgetc(filePointer);
	int **uplas;

	while(getLastReadChar(filePointer) != EOF){
		uplas = new2ulpa(uplas, length);

		getElements(filePointer, *(uplas+((*length)-1)), 2);
	}
	// int i;
	// for(i = 0; i < length; i++){
	// 	printf("%d %d", uplas[i][0], uplas[i][1]);
	// 	printf("\n");
	// }
	return uplas;
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
			// printf("Relation Element: %d\n", searchedElement);
			// printf("Relation Index: %d\n", index);
			position = index;
			return position;
		}
	}
	if(position == -1){
		printf("Erro. O elemento %d nao esta presente no conjunto considerado\n", searchedElement);
		exit(1);
	}
}

int **mountGraphMatix(int *elements, int elementsNumber, int **relation, int relationLength){
	int **graphMatrix, indexI, indexJ;
	//alocando a espaço para a matriz
	graphMatrix = (int **) calloc(elementsNumber, sizeof(int *));
	for(indexI = 0; indexI < elementsNumber; indexI++){
		graphMatrix[indexI] = (int *) calloc(elementsNumber, sizeof(int));
		//zera todos os elementos da matriz
		for(indexJ = 0; indexJ < elementsNumber; indexJ++){
			graphMatrix[indexI][indexJ] = 0;
		}
	}

	// int i, j;
	// for(i = 0; i < elementsNumber; i++){
	// 	for(j = 0; j <elementsNumber; j++){
	// 		printf("%d ", graphMatrix[i][j]);
	// 	}
	// 	printf("\n");
	// }

	//adiciona valor 1 à todas as posições correspondentes à relação
	int positionX, positionY;
	for(indexI = 0; indexI < relationLength; indexI++){
		positionX = getIndexInArray(relation[indexI][0], elements, elementsNumber);
		positionY = getIndexInArray(relation[indexI][1], elements, elementsNumber);
		graphMatrix[positionX][positionY] = 1;
	}
	return graphMatrix;
}

int **getTransitiveSubset(int **graphMatrix, int elementsNumber, int **initialSubset, int *lengthOfInitialSubset){
	int indexI, indexJ, indexK, positionX, positionY, findElement;
	findElement = 0;
	// for(indexI = 0; indexI < elementsNumber; indexI++){
	// 	positionX = initialSubset[indexI][0];
	// 	positionY = initialSubset[indexI][1];
	// 	graphMatrix[positionX][positionY] = 1;
	// }
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

	// for(indexI=0; indexI < *lengthOfInitialSubset; indexI++){
	// 	printf("(%d,%d)\n", initialSubset[indexI][0], initialSubset[indexI][1]);
	// }
	//liberar espaço da matriz criada
	freeMatrix(graphMatrixTmp, elementsNumber);
	
	return initialSubset;
}

void printReflexivity(char *relationName, int *elements, int **subset, int subsetLength){
	printf("%s: ", relationName);
	if(subsetLength == 0){
		printf("V\n");
	} else {
		printf("F\n          ");
		int indexI, elementX, elementY;
		for(indexI = 0; indexI < subsetLength; indexI++){
			elementX = elements[subset[indexI][0]];
			elementY = elements[subset[indexI][1]];
			printf("(%d, %d); ", elementX, elementY);
		}
		printf("\n");
	}
}

void printSymmetry(char *relationName, int *elements, int **subset, int subsetLength){
	printf("%s: ", relationName);
	if(subsetLength == 0){
		printf("V\n");
	} else {
		printf("F\n          ");
		int indexI, elementX, elementY;
		for(indexI = 0; indexI < subsetLength; indexI+=2){
			elementX = elements[subset[indexI][0]];
			elementY = elements[subset[indexI][1]];
			printf("(%d, %d) e ", elementX, elementY);
			elementX = elements[subset[indexI+1][0]];
			elementY = elements[subset[indexI+1][1]];
			printf("(%d, %d); ", elementX, elementY);
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

void verifyRelations(int *elements, int **graphMatrix, int elementsNumber){
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
			} else if (graphMatrix[indexI][indexJ] != graphMatrix[indexJ][indexI]){
				simetricSubset = addNewElementOn2upla(simetricSubset, &simetricSubsetLength, indexJ, indexI);
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
		printReflexivity("Reflexiva", elements, reflectiveSubset, reflectiveSubsetLength);
	printf("2. ");
		printReflexivity("Irreflexiva", elements, irreflectiveSubset, irreflectiveSubsetLength);
	printf("3. ");
		printSymmetry("Simetrica", elements, simetricSubset, simetricSubsetLength);
	printf("4. ");
		printSymmetry("Antissimetrica", elements, antissimetricSubset, antissimetricSubsetLength);
	char isAssimetric;
	isAssimetric = antissimetricSubsetLength + irreflectiveSubsetLength > 0 ? 'F' : 'V';
	printf("5. ");
		printf("Assimetrica: %c\n", isAssimetric);
	printf("6. ");
		printReflexivity("Transitiva", elements, transitiveSubset, transitiveSubsetLength);

	char relacaoEquivalencia, relacaoParcial;
	relacaoEquivalencia = getOrdemEquivalencia(transitiveSubsetLength, simetricSubsetLength, reflectiveSubsetLength);
	printf("\nRelacao de equivalencia: %c", relacaoEquivalencia);
	relacaoParcial = getOrdemParcial(transitiveSubsetLength, antissimetricSubsetLength, reflectiveSubsetLength);
	printf("\nRelacao de ordem parcial: %c\n", relacaoParcial);

	//liberando espaço alocado nas matrizes
	freeMatrix(reflectiveSubset, reflectiveSubsetLength);
	freeMatrix(transitiveSubset, transitiveSubsetLength);
	freeMatrix(irreflectiveSubset, irreflectiveSubsetLength);
	freeMatrix(simetricSubset, simetricSubsetLength);
	freeMatrix(antissimetricSubset, antissimetricSubsetLength);
}


int main(int argc, char *argv[]){
	/*
	Medir tempo
	*/
	// time_t inicio, fim;
	// inicio = time(NULL);

	// count = 0;
	FILE *filePointer;
	filePointer = fopen("texto.txt","r");
	//validar se o arquivo foi aberto com sucesso

	int elementsNumber;
	elementsNumber = getNumber(filePointer);
	if(elementsNumber > 50 || elementsNumber < 1){
		// printError("Erro. Quantidade de elementos inválida!", -1);
		printf("Erro. Quantidade de elementos inválida!\n");
		return 0;
	}
	int *elements, **relation, **graphMatrix, relationLength;
	elements = calloc(elementsNumber, sizeof(int));
	getElements(filePointer, elements, elementsNumber);
	
	// int i;
	// for(i = 0; i < elementsNumber; i++){
	// 	printf("%d ", elements[i]);
	// }
	// printf("====== PEGOU A PRIMEIRA LINHA CERTINHO =====\n");

	relationLength = 0;
	relation = read2uplas(filePointer, &relationLength);
	graphMatrix = mountGraphMatix(elements, elementsNumber, relation, relationLength);
	// print graphMatrix
	// int i, j;
	// for(i = 0; i < elementsNumber; i++){
	// 	for(j = 0; j <elementsNumber; j++){
	// 		printf("%d ", graphMatrix[i][j]);
	// 	}
	// 	printf("\n");
	// }

	verifyRelations(elements, graphMatrix, elementsNumber);

	//preciso desalocar todas as matrizes nesse ponto
	FREE_MEMORY:
	freeMatrix(graphMatrix, elementsNumber);
	freeMatrix(relation, relationLength);
	free(elements);

	fclose(filePointer);

	/*
		Medir o tempo de execução
	*/
	// fim = time(NULL); //Isto deve ficar no final
	// double Tempo ;
	// Tempo = (inicio - fim) * 1000.0 / CLOCKS_PER_SEC;
	// printf("\n%0.10lf miliseconds\n", Tempo);
	return 0;
}