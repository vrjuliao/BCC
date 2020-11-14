#include "animal.h"
#include <vector>

unsigned int Animal::_next_id=1;

unsigned int Animal::get_new_id(){
    _next_id++;
    return _next_id-1;
}


void popula(std::vector<Animal*>& fazenda, Animal* A, unsigned int max_populacao){
    //int escolhido = rand() % fazenda.size();
    fazenda.push_back(A->reproduz());
    if(max_populacao > 0){
        popula(fazenda, A, max_populacao-1);
    }
}

Animal::~Animal(){};