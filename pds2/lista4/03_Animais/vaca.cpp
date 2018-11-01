#include <iostream>
#include "vaca.h"
#include "animal.h"

Vaca::Vaca(std::string cor,float producao_leite){
    _cor=cor;
    _producao_leite=producao_leite;
    _id=Animal::get_new_id();
}
Animal* Vaca::reproduz(){
    Animal* bezerro= new Vaca(_cor,_producao_leite);
    return bezerro;
}
void Vaca::faz_barulho(){
    std::cout<<"Muuu"<<std::endl;
}

unsigned int Vaca::get_id(){
    return _id;
}

Vaca::~Vaca(){}
