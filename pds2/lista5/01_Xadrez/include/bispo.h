#ifndef PDS2_BISPO_H
#define PDS2_BISPO_H

#include "peca.h"

class Bispo: public Peca {
public:
	Bispo(int x, int y);
	void Move(int x, int y) override;
	bool canMove(int x, int y) override;
	std::string getPeca() override;
};

#endif
