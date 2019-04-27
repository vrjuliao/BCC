#include "itemlista.h"
// #include <iostream>

ItemLista::ItemLista(ItemLista *mPrevious, Aluno *mAluno, ItemLista *mNext){
    this->next = mNext;
    this->previous = mPrevious;
    this->aluno = mAluno;
}

Aluno *ItemLista::get_content(){
    return this->aluno;
}

ItemLista *ItemLista::get_next(){
    return this->next;
}

ItemLista *ItemLista::get_previous(){
    return this->previous;
}

void ItemLista::set_next(ItemLista *mNext){
    this->next = mNext;
}

void ItemLista::set_previous(ItemLista *mPrevious){
    this->previous = mPrevious;
}

ItemLista::~ItemLista(){}