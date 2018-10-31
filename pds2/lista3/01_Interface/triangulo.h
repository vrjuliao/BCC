#ifndef PDS_LISTA3_TRIANGULO
#define PDS_LISTA3_TRIANGULO

#include "forma2d.h"
#include <string>

class Triangulo : public Forma2D {
private:
    std::string mNome, mCor;
    double mLado1, mLado2, mLado3;
public:
    Triangulo(std::string, double, double, double);
    virtual std::string get_cor();
    virtual std::string get_nome();
    virtual double get_area();
    virtual double get_perimetro();
};
#endif