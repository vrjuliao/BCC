#include "curso.h"

Curso::Curso(std::string mNome, int mId, int mVagas):
Lista(){
    this->nome = mNome;
    this->vagas = mVagas;
    this->id = mId;
    this->alunos_inseridos = 0;
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

void Curso::add_last(Aluno *aluno){
    ItemLista *item_anterior = this->last;
    Aluno aluno_anterior = item_anterior->get_content();
    while(aluno_anterior.get_nota() < aluno->get_nota()){
        item_anterior = item_anterior->get_next();
        aluno_anterior = item_anterior->get_content();
    }
    this->alunos_inseridos++;
    itemLista *item_seguinte = this->item_anterior->get_next();
    ItemLista *new_item = new ItemLista(item_anterior, aluno, item_seguinte);
    item_seguinte->set_previous(new_item);
    item_anterior->set_next(new_item);
    return this->alunos_inseridos;
}

Curso::~Curso(){}