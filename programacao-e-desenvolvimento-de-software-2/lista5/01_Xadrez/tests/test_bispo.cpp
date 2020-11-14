#include "../include/bispo.h"
#include"doctest.h"



TEST_CASE("Testando o Construtor"){
	CHECK_THROWS(Bispo r(-2, -4));
	CHECK_THROWS(Bispo r(8, 8));
	CHECK_NOTHROW(Bispo r(0, 0));
	CHECK_NOTHROW(Bispo r(3, 4));
}

TEST_CASE("Testando getters"){
	Bispo r(3, 4);
	CHECK(r.getX() == 3);
	CHECK(r.getY() == 4);
}

TEST_CASE("Testando pode mover"){
	Bispo r(3, 4);
	CHECK_EQ(r.canMove(3, 4),false);
	CHECK_EQ(r.canMove(-1, -1),false);
	CHECK_EQ(r.canMove(5, 3),false);
	CHECK_EQ(r.canMove(4, 5), true);
	//CHECK(r.canMove(4, 5));
	//CHECK(r.canMove(2, 3));
	//CHECK(r.canMove(4, 3));
	//CHECK(r.canMove(2, 5));
}

TEST_CASE("Testando falhas no movimento"){
	Bispo r(3, 4);
	CHECK_THROWS(r.Move(3, 4));
	CHECK_THROWS(r.Move(-1, -1));
	CHECK_THROWS(r.Move(5, 3));
	CHECK_NOTHROW(r.Move(4, 5));
}

TEST_CASE("Testando nome"){
	Bispo r(3, 4);
	CHECK_EQ(r.getPeca(), "Bispo");
}