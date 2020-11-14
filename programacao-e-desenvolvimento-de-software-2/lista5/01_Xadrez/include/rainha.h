#ifndef PDS2_RAINHA_H
#define PDS2_RAINHA_H

#include "peca.h"

class Rainha: public Peca {
public:
	Rainha(int x, int y);
	void Move(int x, int y) override;
	bool canMove(int x, int y) override;
	std::string getPeca() override;
};

#endif
