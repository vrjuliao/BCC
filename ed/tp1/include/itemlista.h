#ifndef ITEMLISTA_TP1_ED
#define ITEMLISTA_TP1_ED

#include "aluno.h"

class ItemLista {
private:
    ItemLista *previous;
    ItemLista *next;
    Aluno *aluno;
public:
    ItemLista(ItemLista *mPrevious, Aluno *mAluno, ItemLista *mNext);
    Aluno *get_content();
    ItemLista *get_next();
    ItemLista *get_previous();
    void set_next(ItemLista *mNext);
    void set_previous(ItemLista *mPrevious);
};

#endif