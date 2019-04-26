#include "aluno.h"

Aluno::Aluno(){
    this->name = "";
    this->nota = NULL;
    this->option1 = NULL;
    this->option2 = NULL;
    this->rank_option1 = 0;
    this->rank_option2 = 0;
    std::cout << "Allocate empty constructor" << std::endl;
}

Aluno::Aluno(std::string mName, float mNota, int mOption1, int mOption2){
    this->name = mName;
    this->nota = mNota;
    this->option1 = mOption1;
    this->option2 = mOption2;
    this->rank_option1 = 0;
    this->rank_option2 = 0;
    std::cout << "Allocate " << mName << std::endl;
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

float Aluno::get_nota(){
    return this->nota;
}

void Aluno::set_name(std::string mName){
    this->name = mName;
}

void Aluno::set_option1(int mOption1){
    this->option1 = mOption1;
}

void Aluno::set_option2(int mOption2){
    this->option2 = mOption2;
}

void Aluno::set_nota(float mNota){
    this->nota = mNota;
}

void Aluno::set_rank_option1(int rank){
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

Aluno::~Aluno(){}