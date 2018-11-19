#ifndef PDS2_TABULEIRO_H
#define PDS2_TABULEIRO_H


#include"../include/posicao.h"
#include<map>
#include<vector>

class Tabuleiro {
private:
	std::map<Posicao*, Peca*> pecas;
	std::vector<Posicao*> tabuleiro;

public:
	Tabuleiro();
	void move(Posicao a, Posicao b);
};
#endif