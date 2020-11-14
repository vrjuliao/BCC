#ifndef PDS2_PEAO_H
#define PDS2_PEAO_H

#include "peca.h"

class Peao: public Peca {

public:
	Peao(int x, int y);
	void Move(int x, int y) override;
	bool canMove(int x, int y) override;
	std::string getPeca() override;
};

#endif
