#include <string>
#include "esfera.h"
#include <cmath>

Esfera::Esfera(std::string cor, double raio):
Forma3D::Forma3D(), mCor(cor), mRaio(raio)
{
    mNome = "esfera";
}

std::string Esfera::get_cor(){
    return mCor;
}

std::string Esfera::get_nome(){
    return mNome;
}

double Esfera::get_volume(){
    return (4 * M_PI * pow(mRaio, 3))/3;
}