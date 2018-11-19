#include"../include/excecoes.h"
#include"../include/peao.h"

Peao::Peao(int x, int y):Peca(x,y){}

void Peao::Move(int x, int y) {
	if(y > 7 || y < 0 || x > 7 || x < 0){
		throw PosicaoInexistente(); 
	} else if(this->getX() == x && this->getY() == y){
		throw MovimentoInvalidoException(); 
	} else if( x != this->getX()){
		throw MovimentoInvalidoException();
	} else if(y-this->getY() <= 0){
		throw MovimentoInvalidoException(); 
	} else if(y-this->getY() >= 3){
		throw MovimentoInvalidoException(); 
	} 
	this->SetY(y);

}
bool Peao::canMove(int x, int y){
	bool i = true;
	if(y > 7 || y < 0 || x > 7 || x < 0){
		i = false;
	} else if(this->getX() == x && this->getY() == y){
		i = false;
	} else if( x != this->getX()){
		i = false;
	} else if(y-this->getY() <= 0){
		i = false;
	} else if(y-this->getY() >= 3){
		i = false;
	}
	return i;
}

std::string Peao::getPeca(){
	return "Peao";
}