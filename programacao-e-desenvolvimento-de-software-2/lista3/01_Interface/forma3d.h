#ifndef PDS_LISTA3_FORMA3D
#define PDS_LISTA3_FORMA3D

#include <string>
#include "forma.h"

class Forma3D : public Forma {
public:
    virtual std::string get_cor() = 0;
    virtual std::string get_nome() = 0;
    virtual double get_volume() = 0;
};
#endif