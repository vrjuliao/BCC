#include <cmath>
#include "triangulo.h"

Triangulo::Triangulo(std::string cor, double lado1, double lado2, double lado3):
mCor(cor), mLado1(lado1), mLado2(lado2), mLado3(lado3)
{
    mNome = "triangulo";
}

std::string Triangulo::get_cor(){
    return mCor;
}

std::string Triangulo::get_nome(){
    return mNome;
}

double Triangulo::get_perimetro(){
    return mLado1+mLado2+mLado3;
}

double Triangulo::get_area(){
    double area, semiperimetro;
    semiperimetro = get_perimetro()/2;
    area = sqrt(semiperimetro * (semiperimetro - mLado1) * (semiperimetro - mLado2) * (semiperimetro - mLado3));
    
    return area;
}
