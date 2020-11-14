#include "circulo.h"
#include <cmath>

Circulo::Circulo(std::string cor, double raio):
Forma2D(), mCor(cor), mRaio(raio)
{
    mNome = "circulo";
}

std::string Circulo::get_cor(){
    return mCor;
}

std::string Circulo::get_nome(){
    return mNome;
}

double Circulo::get_perimetro(){
    return 2 * M_PI * mRaio;
}

double Circulo::get_area(){
    return mRaio * mRaio * M_PI;
}