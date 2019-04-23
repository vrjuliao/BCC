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
    ItemLista *get_first();
    ItemLista *get_item(int index);
    ItemLista *get_last();
    void add_item(Aluno *item, int index);
    void add_first(Aluno *item);
    void add_last(Aluno *item);
};
#endif