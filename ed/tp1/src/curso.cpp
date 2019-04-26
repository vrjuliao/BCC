#include "curso.h"
Curso::Curso():
Lista(){
    this->nome = "";
    this->vagas = NULL;
    this->id = NULL;
    this->alunos_inseridos = 0;
    this->nota_de_corte = 0.0;
}

Curso::Curso(std::string mNome, int mId, int mVagas):
Lista(){
    this->nome = mNome;
    this->vagas = mVagas;
    this->id = mId;
    this->alunos_inseridos = 0;
    this->nota_de_corte = 0.0;
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

void Curso::add_last(Aluno *aluno){
    Lista::add_last(aluno);
    this->alunos_inseridos++;
    aluno->set_rank_option1(this->alunos_inseridos);
    if(this->alunos_inseridos == this->vagas){
        this->nota_de_corte = aluno->get_nota();
    }
}

void Curso::add_on_second_option(Aluno *aluno){
    ItemLista *item_anterior = this->last;
    ItemLista *ultimo_colocado = nullptr;
    Aluno *aluno_anterior = item_anterior->get_content();
    int rank_option1;
    int nova_nota_de_corte = 0;
    
    //encontra o aluno que tem a nota menor que o aluno inserido
    while(aluno_anterior->get_nota() < aluno->get_nota()){
        rank_option1 = aluno_anterior->get_rank_option1();
        aluno_anterior->set_rank_option1(rank_option1+1);
        if(aluno_anterior->get_nota() == this->nota_de_corte){
            ultimo_colocado = item_anterior;
        }
        item_anterior = item_anterior->get_previous();
        aluno_anterior = item_anterior->get_content();
    }


    this->alunos_inseridos++;
    if(item_anterior == this->last){
        Lista::add_last(aluno);
    } else {
        ItemLista *item_seguinte = item_anterior->get_next();
        Aluno *aluno_seguinte = item_seguinte->get_content();
        ItemLista *new_item = new ItemLista(item_anterior, aluno, item_seguinte);
        item_seguinte->set_previous(new_item);
        item_anterior->set_next(new_item);
    }

    if(ultimo_colocado != nullptr){
        while(ultimo_colocado->get_content()->get_nota() == 
            ultimo_colocado->get_next()->get_content()->get_nota()){
            ultimo_colocado = ultimo_colocado->get_next();
        }

    }
}

void Curso::print(){
    std::cout << this->nome << " " << this->nota_de_corte << std::endl;
    //std::cout << "----------- Alunos inseridos: " << this->alunos_inseridos << std::endl;
    int index;
    ItemLista *item = this->first->get_next();
    Aluno *aluno;
    std::cout << "Classificados" << std::endl;
    for(index = 0; index < this->vagas && item != nullptr; index++){
        aluno = item->get_content();
        std::cout << aluno->get_name() << " " << aluno->get_nota() << std::endl;
        item = item->get_next();
    }
    if(item!= nullptr){
        std::cout << "Lista de espera" << std::endl;
        while(item!=nullptr){
            aluno = item->get_content();
            std::cout << aluno->get_name() << " " << aluno->get_nota() << std::endl;
            item = item->get_next();
        }
    }
    std::cout << std::endl;
}

Curso::~Curso(){}