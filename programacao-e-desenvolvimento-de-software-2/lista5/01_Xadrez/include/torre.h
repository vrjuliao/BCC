#ifndef PDS2_TORRE_H
#define PDS2_TORRE_H

#include "peca.h"

class Torre: public Peca {
public:
	Torre(int x, int y);
	void Move(int x, int y) override;
	bool canMove(int x, int y) override;
	std::string getPeca() override;
};

#endif
