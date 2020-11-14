#include "../include/rei.h"
#include"doctest.h"

TEST_CASE("Testando o Construtor")
{
	CHECK_THROWS(Rei r(-2, -4));
	CHECK_THROWS(Rei r(8, 8));
	CHECK_NOTHROW(Rei r(0, 0));
	CHECK_NOTHROW(Rei r(3, 4));
}

TEST_CASE("Testando getters")
{
	Rei r(3, 4);
	CHECK(r.getX() == 3);
	CHECK(r.getY() == 4);
}

TEST_CASE("Testando pode mover")
{
	Rei r(3, 4);
	CHECK_EQ(r.canMove(-1, 5), false);
	CHECK_EQ(r.canMove(3, 4), false);
	CHECK_EQ(r.canMove(6, 4), false);
	CHECK_EQ(r.canMove(4, 5), true);
}

TEST_CASE("Testando o movimento")
{
	Rei r(3, 4);
	CHECK_THROWS(r.Move(3, 4));
	CHECK_THROWS(r.Move(-1, 4));
	CHECK_THROWS(r.Move(5, 4));
	CHECK_NOTHROW(r.Move(4, 5));
}
TEST_CASE("Testando nome")
{
	Rei r(3, 4);
	CHECK(r.getPeca() == "Rei");
}