#ifndef ITEMLISTA_TP1_ED
#define ITEMLISTA_TP1_ED

#include "aluno.h"

class ItemLista {
private:
    ItemLista *anterior;
    ItemLista *proximo;
    Aluno *aluno;
public:
    ItemLista(ItemLista *mAnterior, Aluno *mAluno, ItemLista *mProximo);
    Aluno *get_conteudo();
    ItemLista *get_proximo();
    ItemLista *get_anterior();
    void set_proximo(ItemLista *mNext);
    void set_anterior(ItemLista *mPrevious);
    ~ItemLista();
};

#endif