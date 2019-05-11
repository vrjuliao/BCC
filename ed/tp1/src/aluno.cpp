#include "aluno.h"

Aluno::Aluno(){
    this->nome = "";
    this->nota = 0.0;
    this->opcao1 = 0;
    this->opcao2 = 0;
    this->posicao_opcao1 = 0;
}

Aluno::Aluno(std::string mNome, float mNota, int mOpcao1, int mOpcao2){
    this->nome = mNome;
    this->nota = mNota;
    this->opcao1 = mOpcao1;
    this->opcao2 = mOpcao2;
    this->posicao_opcao1 = 0;
}

std::string Aluno::get_nome(){
    return this->nome;
}

int Aluno::get_opcao1(){
    return this->opcao1;
}

int Aluno::get_opcao2(){
    return this->opcao2;
}

float Aluno::get_nota(){
    return this->nota;
}

void Aluno::set_nome(std::string mNome){
    this->nome = mNome;
}

void Aluno::set_opcao1(int mOpcao1){
    this->opcao1 = mOpcao1;
}

void Aluno::set_opcao2(int mOpcao2){
    this->opcao2 = mOpcao2;
}

void Aluno::set_nota(float mNota){
    this->nota = mNota;
}

void Aluno::set_posicao_opcao1(int rank){
    this->posicao_opcao1 = rank;
}

int Aluno::get_posicao_opcao1(){
    return posicao_opcao1;
}

Aluno::~Aluno(){}