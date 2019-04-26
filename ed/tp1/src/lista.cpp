#include "lista.h"
Lista::Lista(){
    this->first = new ItemLista(nullptr, new Aluno("", 1001.0, 0, 0), nullptr);
    this->last = this->first;
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
    prev = next->get_previous();
    ItemLista *new_item  = new ItemLista(prev, aluno, next);
    next->set_previous(new_item);
    prev->set_next(new_item);
}

void Lista::add_first(Aluno *aluno){
    ItemLista *new_item  = new ItemLista(nullptr, aluno, this->first);
    this->first->set_previous(new_item);
    new_item->set_next(this->first);
    this->first = new_item;
}

void Lista::add_last(Aluno *aluno){
    ItemLista *new_item  = new ItemLista(this->last, aluno, nullptr);
    new_item->set_previous(this->last);
    this->last->set_next(new_item);
    this->last = new_item;
}