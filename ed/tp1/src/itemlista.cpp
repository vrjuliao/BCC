#include "itemlista.h"

ItemLista::ItemLista(ItemLista *mAnterior, Aluno *mAluno, ItemLista *mProximo){
    this->proximo = mProximo;
    this->anterior = mAnterior;
    this->aluno = mAluno;
}

Aluno *ItemLista::get_conteudo(){
    return this->aluno;
}

ItemLista *ItemLista::get_proximo(){
    return this->proximo;
}

ItemLista *ItemLista::get_anterior(){
    return this->anterior;
}

void ItemLista::set_proximo(ItemLista *mProximo){
    this->proximo = mProximo;
}

void ItemLista::set_anterior(ItemLista *mAnterior){
    this->anterior = mAnterior;
}

ItemLista::~ItemLista(){}