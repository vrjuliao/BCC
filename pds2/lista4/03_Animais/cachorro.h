#ifndef CACHORRO_H
#define CACHORRO_H

#include <iostream>
#include "animal.h"

class Cachorro : public Animal {
    public:
        Cachorro(std::string cor);
        virtual Animal* reproduz();
        virtual void faz_barulho();
        virtual unsigned int get_id();
        virtual ~Cachorro();
};


#endif