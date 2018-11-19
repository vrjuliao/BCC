#include"../include/excecoes.h"
#include "../include/rainha.h"

Rainha::Rainha(int x, int y):Peca(x,y){}

void Rainha::Move(int x, int y) {
	if(this->getX() == x && this->getY() == y){
		throw MovimentoInvalidoException(); 
	} else if(y > 7 || y < 0 || x > 7 || x < 0){
		throw PosicaoInexistente(); 
	} else if(std::abs(this->getX() - x) == std::abs(this->getY() - y)){
		this->SetX(x);
		this->SetY(y);
	} else if((this->getX() == x) && (this->getY() != y)){
		this->SetY(y);
	} else if((this->getY() == y) && (this->getX() != x)){
		this->SetX(x);
	} else throw MovimentoInvalidoException(); 
}
bool Rainha::canMove(int x, int y){
	if(this->getX() == x && this->getY() == y){
		return false;
	}else if(y > 7 || y < 0 || x > 7 || x < 0){
		return false;
	}else if(std::abs(this->getX() - x) == std::abs(this->getY() - y)){
		return true;
	}else if((this->getX() == x) && (this->getY() != y)){
		return true;
	}else if((this->getY() == y) && (this->getX() != x)){
		return true;
	}
	return false;
}
std::string Rainha::getPeca(){
	return "Rainha";
}