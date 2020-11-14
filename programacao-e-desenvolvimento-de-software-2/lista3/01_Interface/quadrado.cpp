#include "quadrado.h"
#include <cmath>

class Forma2D;

Quadrado::Quadrado(std::string cor, double lado):
Forma2D(), mCor(cor), mLado(lado)
{
    mNome = "quadrado";
}

std::string Quadrado::get_cor(){
    return mCor;
}

std::string Quadrado::get_nome(){
    return mNome;
}

double Quadrado::get_area(){
    return pow(mLado, 2);
}

double Quadrado::get_perimetro(){
    return mLado * 4.0;
}