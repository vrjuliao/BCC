#include "curso.h"
Curso::Curso():
Lista(){
    this->nome = "";
    this->vagas = NULL;
    this->id = NULL;
    this->alunos_inseridos = 0;
}

Curso::Curso(std::string mNome, int mId, int mVagas):
Lista(){
    this->nome = mNome;
    this->vagas = mVagas;
    this->id = mId;
    this->alunos_inseridos = 0;
}

void Curso::set_nome(std::string mNome){
    this->nome = mNome;
}

void Curso::set_vagas(int mVagas){
    this->vagas = mVagas;
}

void Curso::set_id(int mId){
    this->id = mId;
}

int Curso::get_vagas(){
    return this->vagas;
}

std::string Curso::get_nome(){
    return this->nome;
}

int Curso::get_alunos_inseridos(){
    return this->alunos_inseridos;
}

void Curso::add_on_second_option(Aluno *aluno){
    ItemLista *item_anterior = this->last;
    Aluno *aluno_anterior = item_anterior->get_content();
    while(aluno_anterior->get_nota() < aluno->get_nota()){
        item_anterior = item_anterior->get_next();
        aluno_anterior = item_anterior->get_content();
    }
    this->alunos_inseridos++;
    ItemLista *item_seguinte = item_anterior->get_next();
    ItemLista *new_item = new ItemLista(item_anterior, aluno, item_seguinte);
    item_seguinte->set_previous(new_item);
    item_anterior->set_next(new_item);
}

Curso::~Curso(){}