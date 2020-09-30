#ifndef LISTA_TP1_ED
#define LISTA_TP1_ED

#include "aluno.h"
#include "itemlista.h"

class Lista {
protected:
    ItemLista *primeiro;
    ItemLista *ultimo;
public:
    Lista();
    ItemLista *get_primeiro(); 
    ItemLista *get_item(int index);
    ItemLista *get_ultimo();
    void insere_item(Aluno *item, int index);
    void insere_inicio(Aluno *item);
    void insere_ordenado(Aluno *aluno);
    void insere_fim(Aluno *item);
    void free_content();
    ~Lista();
};
#endif