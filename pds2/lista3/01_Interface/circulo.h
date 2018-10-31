#ifndef PDS_LISTA3_CIRCULO
#define PDS_LISTA3_CIRCULO

#include "forma2d.h"
#include <string>

class Circulo : public Forma2D {
private:
    std::string mNome, mCor;
    double mRaio;
public:
    Circulo(std::string, double);
    virtual std::string get_cor();
    virtual std::string get_nome();
    virtual double get_area();
    virtual double get_perimetro();
};

#endif