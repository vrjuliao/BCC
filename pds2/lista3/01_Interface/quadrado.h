#ifndef PDS_LISTA3_QUADRADO
#define PDS_LISTA3_QUADRADO

#include "forma2d.h"
#include <string>

class Quadrado : public Forma2D {
private:
    std::string mNome, mCor;
    double mLado;
public:
    Quadrado(std::string, double);
    virtual std::string get_cor();
    virtual std::string get_nome();
    virtual double get_area();
    virtual double get_perimetro();
};

#endif