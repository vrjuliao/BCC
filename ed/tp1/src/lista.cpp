#include "lista.h"
Lista::Lista(){
    this->primeiro = new ItemLista(nullptr, new Aluno("HEADER", 1001.0, 0, 0), nullptr);
    this->ultimo = this->primeiro;
}

ItemLista *Lista::get_primeiro(){
    return this->primeiro;
}

ItemLista *Lista::get_ultimo(){
    return this->ultimo;
}

ItemLista *Lista::get_item(int index){
    ItemLista *item = this->primeiro;
    for(int i = 0; i < index; i++){
        item = item->get_proximo();
    }
    return item;
}

void Lista::insere_item(Aluno *aluno, int index){
    ItemLista *prev;
    ItemLista *next;
    next = this->get_item(index);
    prev = next->get_anterior();
    ItemLista *new_item  = new ItemLista(prev, aluno, next);
    next->set_anterior(new_item);
    prev->set_proximo(new_item);
}

void Lista::insere_inicio(Aluno *aluno){
    ItemLista *segundo = this->primeiro->get_proximo();
    ItemLista *new_item  = new ItemLista(this->primeiro, aluno, segundo);
    this->primeiro->set_proximo(new_item);
    segundo->set_anterior(new_item);
}

void Lista::insere_ordenado(Aluno *aluno){
    ItemLista *proximo = this->ultimo;
    ItemLista *anterior;
    if(aluno->get_nota() <= proximo->get_conteudo()->get_nota())
        this->insere_fim(aluno);
    else{

        while(aluno->get_nota() > proximo->get_conteudo()->get_nota()){
            proximo = proximo->get_anterior();
        }
        anterior = proximo;
        proximo = anterior->get_proximo();
        ItemLista *item = new ItemLista(anterior, aluno, proximo);
        anterior->set_proximo(item);
        proximo->set_anterior(item);
    }
}

void Lista::insere_fim(Aluno *aluno){
    ItemLista *new_item  = new ItemLista(this->ultimo, aluno, nullptr);
    this->ultimo->set_proximo(new_item);
    this->ultimo = new_item;
}

void Lista::free_content(){
    ItemLista *item = this->ultimo;
    Aluno *aluno;
    while(item != this->primeiro){
        aluno = item->get_conteudo();
        delete aluno;
        item = item->get_anterior();
    }
}

Lista::~Lista(){
    Aluno *header = this->primeiro->get_conteudo();
    delete header;
    ItemLista *item;
    while(this->ultimo != nullptr){
        item = this->ultimo;
        this->ultimo = item->get_anterior();
        delete item;
    }
}