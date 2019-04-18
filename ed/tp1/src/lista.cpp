#include "lista.h"
Lista::Lista(){
    this->frist = nullptr;
    this->last = nullptr;
}

ItemLista *Lista::get_first(){
    return this->first;
}

ItemLista *Lista::get_last(){
    return this->last;
}

ItemLista *Lista::get_item(int index){
    ItemLista *item = this->first;
    for(int i = 0; i < index; i++){
        item = item->get_next();
    }
    return item;
}

void Lista::add_item(Aluno *aluno, int index){
    ItemLista *prev;
    ItemLista *next;
    next = this->get_item(index);
    prev = next->prev;
    ItemLista *new_item  = new ItemLista(prev, aluno, next);
    next->set_previous(item);
    prev->set_next(item);
}

void Lista::add_frist(Aluno *aluno){
    ItemLista *new_item  = new ItemLista(nullptr, aluno, this->first);
    this->first->set_previous(new_item);
    this->frist = new_item;
}

void Lista::add_last(Aluno *aluno){
    ItemLista *new_item  = new ItemLista(this->last, aluno, nullptr);
    this->last->set_next(new_item);
    this->last = new_item;
}