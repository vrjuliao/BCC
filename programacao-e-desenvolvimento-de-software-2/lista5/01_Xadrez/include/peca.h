#ifndef PECA_H
#define PECA_H

#include <string>

class Peca {
private:
	int _x,_y;
public:
	Peca(int x, int y);
	virtual void Move(int x, int y) = 0;
	virtual bool canMove(int x, int y) = 0;
	virtual std::string getPeca() = 0;
	int getX();
	int getY();
	inline void SetX(int x){ _x = x;}
	inline void SetY(int y){ _y = y;}
};

#endif
