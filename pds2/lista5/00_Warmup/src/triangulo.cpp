#include "triangulo.h"
#include <iostream>


Triangulo::Triangulo(double x, double y, double z){
    //testa valor negativo
    if((x < 0.0) || (y < 0.0) || (z < 0.0)){
       throw TrianguloInvalidoException(); 
    }
    //Testa existencia de um triangulo
    //| b - c | < a < b + c
    float diffXY;
    diffXY = x-y > 0.0 ? x-y : y-x;
    if(diffXY > z || z > (x+y)){
        throw TrianguloInvalidoException();
    }
    
    _x = x;
    _y = y;
    _z = z;
}

Tipo Triangulo::determinar_tipo(){
    if(_z==_x) {
        if(_z==_y){
            return Tipo::EQUILATERO;    
        } else {
            return Tipo::ISOSCELES;
        }
    } else if(_x==_y) {
        return Tipo::ISOSCELES;
    } else if(_z==_y){
        return Tipo::ISOSCELES;
    } else {
        return Tipo::ESCALENO;
    }
}