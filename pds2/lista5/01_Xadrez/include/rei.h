#ifndef PDS2_REI_H
#define PDS2_REI_H

#include "peca.h"

class Rei: public Peca {
public:
	Rei(int x, int y);
	void Move(int x, int y) override;
	bool canMove(int x, int y) override;
	std::string getPeca() override;
};

#endif
