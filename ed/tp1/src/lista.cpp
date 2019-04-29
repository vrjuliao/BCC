// #include <iostream>
#include "lista.h"
Lista::Lista(){
    this->first = new ItemLista(nullptr, new Aluno("HEADER", 1001.0, 0, 0), nullptr);
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
    //this->first->set_previous(new_item);
    new_item->set_next(this->first);
    this->first = new_item;
}

void Lista::insere_ordenado(Aluno *aluno){
    ItemLista *proximo = this->last;
    ItemLista *anterior;
    if(aluno->get_nota() <= proximo->get_content()->get_nota())
        this->add_last(aluno);
    else{

        while(aluno->get_nota() > proximo->get_content()->get_nota()){
            proximo = proximo->get_previous();
        }
        anterior = proximo;
        proximo = anterior->get_next();
        ItemLista *item = new ItemLista(anterior, aluno, proximo);
        // std::cout << "Nota do Anterior : " << anterior->get_content()->get_nota() << std::endl;
        // std::cout << "Nota do Proximo : " << proximo->get_content()->get_nota() << std::endl;
        anterior->set_next(item);
        proximo->set_previous(item);
    }
}

void Lista::add_last(Aluno *aluno){
  //  std::cout << "Adicionando aluno: " << aluno->get_name() << std::endl;
    ItemLista *new_item  = new ItemLista(this->last, aluno, nullptr);
    //new_item->set_previous(this->last);
    this->last->set_next(new_item);
    this->last = new_item;
}

void Lista::free_content(){
    ItemLista *item = this->last;
    Aluno *aluno;
    while(this->last != nullptr){
        this->last = item->get_previous();
        aluno = item->get_content();
        // std::cout << "Deletando:" << item->get_content()->get_name() << std::endl;
        delete aluno;
        item = this->last;
    }
}

Lista::~Lista(){
    ItemLista *item = this->last;
    // std::cout << "Deletando Lista" << std::endl;
    while(this->last != nullptr){
        this->last = item->get_previous();
        
        // std::cout << "Deletando:" << item->get_content()->get_name() << std::endl;
        delete item;
        item = this->last;
    }
}