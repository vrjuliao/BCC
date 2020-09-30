#include <stdio.h>
#include <string.h>
struct tipo_endereco{
    char rua [50];
    int numero;
    char bairro [20];
    char cidade [30];
    char sigla_estado [3];
    long int CEP;
};
struct ficha_pessoal{
    char nome [50];
    long int telefone;
    struct tipo_endereco endereco;
};
int main (void){
    struct ficha_pessoal ficha;
    strcpy (ficha.nome,"Luiz Osvaldo Silva");
    ficha.telefone=4921234;
    strcpy (ficha.endereco.rua,"Rua das Flores");
    ficha.endereco.numero=10;
    strcpy (ficha.endereco.bairro,"Cidade Velha");
    strcpy (ficha.endereco.cidade,"Belo Horizonte");
    strcpy (ficha.endereco.sigla_estado,"MG");
    ficha.endereco.CEP=31340230;

    printf("Nome: %s\n", ficha.nome);
    printf("Telefone: %li\n", ficha.telefone);
    printf("Endereco\n");
    printf("\tRua: %s, Numero: %d\n", ficha.endereco.rua, ficha.endereco.numero);
    printf("\tBairro: %s\n", ficha.endereco.bairro);
    printf("\tCidade: %s - Estado: %s\n", ficha.endereco.cidade, ficha.endereco.sigla_estado);
    printf("\tCEP: %li\n", ficha.endereco.CEP);
    return 0;
}