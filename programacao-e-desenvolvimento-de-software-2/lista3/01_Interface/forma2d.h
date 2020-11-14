#ifndef PDS_LISTA3_FORMA2D
#define PDS_LISTA3_FORMA2D

#include "forma.h"

class Forma2D : public Forma {
public:
    virtual std::string get_cor() = 0;
    virtual std::string get_nome() = 0;
    virtual double get_area() = 0;
    virtual double get_perimetro() = 0;
};

#endif