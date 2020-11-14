#ifndef PDS2_CAVALO_H
#define PDS2_CAVALO_H

#include "peca.h"

class Cavalo: public Peca {
public:
	Cavalo(int x, int y);
	void Move(int x, int y) override;
	bool canMove(int x, int y) override;
	std::string getPeca() override;
};

#endif
