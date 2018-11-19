#ifndef PDS2_POSICAO_H
#define PDS2_POSICAO_H
#include"../include/peca.h"

class Posicao {
private:
	bool IsEmpty;
	int x;
	int y;

public:

	Posicao(int x, int y);
	inline bool isEmpty(){return IsEmpty;}
	inline void porPeca(){IsEmpty = false;}
	inline void retirarPeca(){IsEmpty = true;}
	inline int getX(){return x;}
	inline int getY(){return y;}
};

#endif