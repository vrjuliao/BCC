#include "aluno.h"

Aluno::Aluno(std::string mName, int mOption1, int mOption2){
    this->name = mName;
    this->option1 = mOption1;
    this->option2 = mOption2;
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