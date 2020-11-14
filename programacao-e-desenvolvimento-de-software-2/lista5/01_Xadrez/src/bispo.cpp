#include"../include/excecoes.h"
#include"../include/bispo.h"

Bispo::Bispo(int x, int y):Peca(x,y){}

void Bispo::Move(int x, int y) {
	if(this->getX() == x && this->getY() == y){
		throw MovimentoInvalidoException(); 
	} else if(y > 7 || y < 0 || x > 7 || x < 0){
		throw new PosicaoInexistente(); 
	} else if((this->getX() - x) != (this->getY() - y) && (this->getX() - x) != ((this->getY() - y))*(-1)){
		throw MovimentoInvalidoException();
	}
	this->SetX(x);
	this->SetY(y);

}
bool Bispo::canMove(int x, int y)
{
	if(this->getX() == x && this->getY() == y){
		return false;
	} else if(y > 7 || y < 0 || x > 7 || x < 0){
		return false;
	} else if((this->getX() - x) != (this->getY() - y) && (this->getX() - x) != ((this->getY() - y))*(-1)){
		return false;
	}
	return true;
}
std::string Bispo::getPeca(){
	return "Bispo";
}