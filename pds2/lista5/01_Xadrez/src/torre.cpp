#include"../include/torre.h"
#include"../include/excecoes.h"

Torre::Torre(int x, int y):Peca(x,y){}

void Torre::Move(int x, int y) {
	if(y > 7 || y < 0 || x > 7 || x < 0){
		throw PosicaoInexistente(); 
	} else if((this->getX() == x) && (this->getY() != y)){
		this->SetY(y);
	} else if((this->getX() != x) && (this->getY() == y)){
		this->SetX(x);
	} else {
		throw MovimentoInvalidoException();
	}
}

bool Torre::canMove(int x, int y){
	bool i = false;
	if(y > 7 || y < 0 || x > 7 || x < 0){
		i = false;
	} else if((this->getX() == x) && (this->getY() != y)){
		i = true;
	} else if((this->getX() != x) && (this->getY() == y)){
		i = true;
	}
	return i;
}

std::string Torre::getPeca(){
	return "Torre";
}