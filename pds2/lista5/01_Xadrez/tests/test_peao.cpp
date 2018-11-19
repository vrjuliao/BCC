#include "../include/peao.h"
#include"doctest.h"

TEST_CASE("Testando o Construtor")
{
	CHECK_THROWS(Peao r(-2, -4));
	CHECK_THROWS(Peao r(8, 8));
	CHECK_NOTHROW(Peao r(0, 0));
	CHECK_NOTHROW(Peao r(3, 4));
}
TEST_CASE("Testando getters")
{
	Peao r(3, 4);
	CHECK(r.getX() == 3);
	CHECK(r.getY() == 4);
}
TEST_CASE("Testando pode mover")
{
	Peao r(3, 3);
	CHECK_EQ(r.canMove(-3, 1), false);
	CHECK_EQ(r.canMove(3, 3), false);
	CHECK_EQ(r.canMove(4, 2), false);
	CHECK_EQ(r.canMove(3, 0), false);
	CHECK_EQ(r.canMove(3, 6), false);
	CHECK_EQ(r.canMove(3, 5), true);
}

TEST_CASE("Testando o movimento")
{
	Peao r(3, 3);
	CHECK_THROWS(r.Move(-3, 1));
	CHECK_THROWS(r.Move(3, 3));
	CHECK_THROWS(r.Move(4, 2));
	CHECK_THROWS(r.Move(3, 0));
	CHECK_THROWS(r.Move(3, 6));
	CHECK_NOTHROW(r.Move(3, 5));
}

TEST_CASE("Testando nome")
{
	Peao r(3, 4);
	CHECK(r.getPeca() == "Peao");
}