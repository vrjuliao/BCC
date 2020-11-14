#include"../include/excecoes.h"
#include"../include/cavalo.h"

/*int moduloa(int a){
	if (a < 0){
		a *= -1;
	}
	return a;
}*/

Cavalo::Cavalo(int x, int y):Peca(x,y){}


void Cavalo::Move(int x, int y) {
	if(this->getX() == x && this->getY() == y){
		throw MovimentoInvalidoException();
	} else if(y > 7 || y < 0 || x > 7 || x < 0){
		throw PosicaoInexistente(); 
	} else if((std::abs(this->getX() - x) == 1) && (std::abs(this->getY() - y) == 2)){
		this->SetX(x);
		this->SetY(y);
	} else if((std::abs(this->getX() - x) == 2) && (std::abs(this->getY() - y) == 1)){
		this->SetX(x);
		this->SetY(y);
	} else {
		throw MovimentoInvalidoException(); 
	}
}
bool Cavalo::canMove(int x, int y){
	bool i = false;
	if(this->getX() == x && this->getY() == y){
		i = false;
	} else if(y > 7 || y < 0 || x > 7 || x < 0){
		i = false;
	} else if((std::abs(this->getX() - x) == 1) && (std::abs(this->getY() - y) == 2)){
		i = true;
	} else if((std::abs(this->getX() - x) == 2) && (std::abs(this->getY() - y) == 1)){
		i = true;
	}
	return i;
}
std::string Cavalo::getPeca(){
	return "Cavalo";
}