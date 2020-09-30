#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	FILE *arquivo;
	arquivo = fopen("primos.txt", "w");
	int elementos;
	printf("Elementos: ");
	scanf("%d", &elementos);

	int primo, indexI, indexJ;
	for(indexI = 1; indexI <= elementos; indexI++){
		primo = 1;
		for(indexJ = 2; indexJ < indexI; indexJ++){
			if(indexI%indexJ == 0 && indexI != indexJ){
				primo = 0;
				break;
			}
		}
		if(primo){
			fprintf(arquivo, "%d\n", indexI);
		}
	}
	fclose(arquivo);
	return 0;
}