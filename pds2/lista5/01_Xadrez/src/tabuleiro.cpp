#include"../include/tabuleiro.h"
#include"../include/rei.h"
#include"../include/torre.h"
#include"../include/rainha.h"
#include"../include/bispo.h"
#include"../include/peao.h"
#include"../include/cavalo.h"

#include"../include/excecoes.h"
#include <iostream>
Tabuleiro::Tabuleiro() {
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			tabuleiro.emplace_back(new Posicao(j,i));
		}
	}
	//colocar peças
	//brancas
	pecas[tabuleiro[0]] = new Torre(0,0);
	pecas[tabuleiro[1]] = new Cavalo(1,0);
	pecas[tabuleiro[2]] = new Bispo(2,0);
	pecas[tabuleiro[3]] = new Rainha(3,0);
	pecas[tabuleiro[4]] = new Rei(4,0);
	pecas[tabuleiro[5]] = new Bispo(5,0);
	pecas[tabuleiro[6]] = new Cavalo(6,0);
	pecas[tabuleiro[7]] = new Torre(6,0);
	pecas[tabuleiro[8]] = new Peao(0,1);
	pecas[tabuleiro[9]] = new Peao(1,1);
	pecas[tabuleiro[10]] = new Peao(2,1);
	pecas[tabuleiro[11]] = new Peao(3,1);
	pecas[tabuleiro[12]] = new Peao(4,1);
	pecas[tabuleiro[13]] = new Peao(5,1);
	pecas[tabuleiro[14]] = new Peao(6,1);
	pecas[tabuleiro[15]] = new Peao(7,1);

	for(int t=0; t<16; t++) {
		tabuleiro[t]->porPeca();
	}
	//pretas
	pecas[tabuleiro[63]] = new Torre(7,7);
	pecas[tabuleiro[62]] = new Cavalo(6,7);
	pecas[tabuleiro[61]] = new Bispo(5,7);
	pecas[tabuleiro[60]] = new Rainha(4,7);
	pecas[tabuleiro[59]] = new Rei(3,7);
	pecas[tabuleiro[58]] = new Bispo(2,7);
	pecas[tabuleiro[57]] = new Cavalo(1,7);
	pecas[tabuleiro[56]] = new Torre(0,7);
	pecas[tabuleiro[55]] = new Peao(0,6);
	pecas[tabuleiro[54]] = new Peao(1,6);
	pecas[tabuleiro[53]] = new Peao(2,6);
	pecas[tabuleiro[52]] = new Peao(3,6);
	pecas[tabuleiro[51]] = new Peao(4,6);
	pecas[tabuleiro[50]] = new Peao(5,6);
	pecas[tabuleiro[49]] = new Peao(6,6);
	pecas[tabuleiro[48]] = new Peao(7,6);

	for(int t=48; t<64; t++) {
		tabuleiro[t]->porPeca();
	}

}

void Tabuleiro::move(Posicao a, Posicao b) {
	Posicao *aux;
	for(int i = 0; i < 64; i++){
		aux = tabuleiro[i];
		if(a.getX()== aux->getX() && a.getY()== aux->getY())
			break;
	}

	if(!(aux->isEmpty())) {
		if((pecas[aux]->canMove(b.getX(),b.getY())) && (b.isEmpty())) {
			pecas[aux]->Move(b.getX(),b.getY());
			a.retirarPeca();
			b.porPeca();
		}else {
			throw MovimentoInvalidoException();
		}
	} else {
		throw PosicaoSemPecaException();
	}
}
