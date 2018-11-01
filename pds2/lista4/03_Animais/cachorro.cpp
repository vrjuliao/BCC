#include <iostream>
#include "cachorro.h"
#include "animal.h"

Cachorro::Cachorro(std::string cor){
    _cor=cor;
    _id=get_new_id();
}
Animal* Cachorro::reproduz(){
    Animal* filhote= new Cachorro(_cor);
    return filhote;
}
void Cachorro::faz_barulho(){
    std::cout<<"Au Au"<<std::endl;
}

unsigned int Cachorro::get_id(){
    return _id;
}

Cachorro::~Cachorro(){};