#ifndef LISTA_TP1_ED
#define LISTA_TP1_ED

#include "aluno.h"
#include "itemlista.h"

class Lista {
protected:
    ItemLista *first;
    ItemLista *last;
public:
    Lista();
    ItemLista *get_first(); //retirar
    ItemLista *get_item(int index); //retirar
    ItemLista *get_last(); //retirar
    void add_item(Aluno *item, int index); //retirar
    void add_first(Aluno *item); //retirar
    void insere_ordenado(Aluno *aluno);
    void add_last(Aluno *item); //renomear para "insere_fim"
    void free_content(); //renomear para "libera alunos"
    ~Lista();
};
#endif