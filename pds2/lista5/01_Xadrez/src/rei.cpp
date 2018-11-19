#include"../include/rei.h"
#include"../include/excecoes.h"

Rei::Rei(int x, int y):Peca(x,y){}


void Rei::Move(int x, int y) 
{
	if((this->getX() == x) && (this->getY() == y)){
		throw MovimentoInvalidoException(); 
	} else if(y > 7 || y < 0 || x > 7 || x < 0){
		throw PosicaoInexistente(); 
	} else if(( (std::abs(this->getX() - x)) == 1 ) || ((std::abs(this->getY() - y)) == 1)){
		this->SetY(y);
		this->SetX(x);
	} else {
		throw MovimentoInvalidoException(); 
	}
}

bool Rei::canMove(int x, int y){
	bool i = false;
	if(this->getX() == x && this->getY() == y){
		i = false;
	} else if(y > 7 || y < 0 || x > 7 || x < 0){
		i = false;
	} else if(((std::abs(this->getX() - x)) == 1) || ((std::abs(this->getY() - y)) == 1)){
		i = true;
	} else i = false;

	return i;
}

std::string Rei::getPeca(){
	return "Rei";
}