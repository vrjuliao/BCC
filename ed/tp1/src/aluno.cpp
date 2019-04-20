#include "aluno.h"

Aluno::Aluno(std::string mName, int mNota, int mOption1, int mOption2){
    this->name = mName;
    this->nota = mNota;
    this->option1 = mOption1;
    this->option2 = mOption2;
    this->rank_option1 = 0;
    this->rank_option2 = 0;
}

std::string Aluno::get_name(){
    return this->name;
}

int Aluno::get_option1(){
    return this->option1;
}

int Aluno::get_option2(){
    return this->option2;
}

int Aluno::get_nota(){
    return this->nota;
}

void ALuno::set_rank_option1(int rank){
    this->rank_option1 = rank;
}
void Aluno::set_rank_option2(int rank){
    this->rank_option2 = rank;
}
int Aluno::get_rank_option1(){
    return rank_option1;
}

int Aluno::get_rank_option2(){
    return rank_option2;
}