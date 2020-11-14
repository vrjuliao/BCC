#include"../include/excecoes.h"
#include "../include/peca.h"

Peca::Peca(int x, int y){
	if((x < 0) || (x > 7) || (y < 0) || (y > 7)){
		throw PosicaoInexistente();
	}
	_x = x;
	_y = y;
}

int Peca::getX(){
	return _x;
}

int Peca::getY(){
	return _y;
}

