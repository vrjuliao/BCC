#include <string>
#include "cubo.h"
#include <cmath>

Cubo::Cubo(std::string cor, double lado):
Forma3D::Forma3D(), mCor(cor), mLado(lado)
{
    mNome = "cubo";
}

std::string Cubo::get_cor(){
    return mCor;
}

std::string Cubo::get_nome(){
    return mNome;
}

double Cubo::get_volume(){
    return pow(mLado, 3);
}