#include <stdio.h>
#include <stdlib.h>

#define LEN 50
struct endereco {
    char rua[LEN];
    char cidade [15];
    char estado [3];
    char cep [10];
};
struct endereco obtem_endereco(void){
    struct endereco ender;
    printf("\t Entre rua: ");
    // gets(ender.rua);
    //gets() nao funciona no GNU/Linux 16.04 LTS
    fgets(ender.rua, LEN,stdin);
    __fpurge(stdin);
    printf("\t Entre cidade: ");
    fgets(ender.cidade, 15,stdin);
    __fpurge(stdin);
    printf("\t Entre estado: ");
    fgets(ender.estado, 3,stdin);
    __fpurge(stdin);
    printf("\t Entre cep: ");
    fgets(ender.cep, 10,stdin);
    __fpurge(stdin);
    return ender;
}

void imprime_endereco(struct endereco ender){
    printf("\t %s\n", ender.rua);
    printf("\t %s\n", ender.cidade);
    printf("\t %s\n", ender.estado);
    printf("\t %s\n", ender.cep);
}

void main(void){
    struct endereco residencia;
    printf("Entre seu endereco residencial:\n");
    residencia = obtem_endereco();
    printf("\nSeu endereco eh:\n");
    imprime_endereco(residencia);
}