#include "curso.h"

Curso::Curso():
Lista(){
    this->nome = "";
    this->vagas = 0;
    this->alunos_inseridos = 0;
    this->nota_de_corte = 0.0;
}

Curso::Curso(std::string mNome, int mVagas):
Lista(){
    this->nome = mNome;
    this->vagas = mVagas;
    this->alunos_inseridos = 0;
    this->nota_de_corte = 0.0;
}

void Curso::set_nome(std::string mNome){
    this->nome = mNome;
}

void Curso::set_vagas(int mVagas){
    this->vagas = mVagas;
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

void Curso::insere_fim(Aluno *aluno){
    Lista::insere_fim(aluno);
    this->alunos_inseridos++;
    aluno->set_posicao_opcao1(this->alunos_inseridos);
    if(this->alunos_inseridos == this->vagas){
        this->nota_de_corte = aluno->get_nota();
    }
}

void Curso::insere_ordenado(Aluno *aluno){
    ItemLista *item_anterior = this->ultimo;
    ItemLista *ultimo_colocado = nullptr;
    Aluno *aluno_anterior = item_anterior->get_conteudo();
    int rank_option1;
    
    while(aluno_anterior->get_nota() < aluno->get_nota()){
        rank_option1 = aluno_anterior->get_posicao_opcao1();
        aluno_anterior->set_posicao_opcao1(rank_option1+1);
        if(aluno_anterior->get_nota() == this->nota_de_corte){
            ultimo_colocado = item_anterior;
        }
        item_anterior = item_anterior->get_anterior();
        aluno_anterior = item_anterior->get_conteudo();
    }

    this->alunos_inseridos++;
    if(item_anterior == this->ultimo){
        Lista::insere_fim(aluno);
    } else {
        ItemLista *item_seguinte = item_anterior->get_proximo();
        ItemLista *new_item = new ItemLista(item_anterior, aluno, item_seguinte);
        item_seguinte->set_anterior(new_item);
        item_anterior->set_proximo(new_item);
    }

    if(ultimo_colocado != nullptr){
        while(ultimo_colocado->get_conteudo()->get_nota() == 
            ultimo_colocado->get_proximo()->get_conteudo()->get_nota()){
            ultimo_colocado = ultimo_colocado->get_proximo();
        }

    }
}

void Curso::imprime(){
    std::cout << this->nome << " " ;
    std::cout << std::fixed << std::setprecision(2) << this->nota_de_corte << std::endl;
    int index;
    ItemLista *item = this->primeiro->get_proximo();
    Aluno *aluno;
    std::cout << "Classificados" << std::endl;
    for(index = 0; index < this->vagas && item != nullptr; index++){
        aluno = item->get_conteudo();
        std::cout << aluno->get_nome() << " ";
        std::cout << std::fixed << std::setprecision(2) << aluno->get_nota() << std::endl;
        item = item->get_proximo();
    }
    std::cout << "Lista de espera" << std::endl;
    while(item!=nullptr){
        aluno = item->get_conteudo();
        std::cout << aluno->get_nome() << " ";
        std::cout << std::fixed << std::setprecision(2) << aluno->get_nota() << std::endl;
        item = item->get_proximo();
    }
}

Curso::~Curso(){}