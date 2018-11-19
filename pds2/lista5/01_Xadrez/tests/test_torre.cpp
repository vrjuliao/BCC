#include "../include/torre.h"
#include"doctest.h"


TEST_CASE("Testando o Construtor")
{
	CHECK_THROWS(Torre r(-2, -4));
	CHECK_THROWS(Torre r(8, 8));
	CHECK_NOTHROW(Torre r(0, 0));
	CHECK_NOTHROW(Torre r(3, 4));
}
TEST_CASE("Testando getters")
{
	Torre r(3, 4);
	CHECK(r.getX() == 3);
	CHECK(r.getY() == 4);
}
TEST_CASE("Testando pode mover")
{
	Torre r(3, 4);
	CHECK_EQ(r.canMove(3, 4), false);
	CHECK_EQ(r.canMove(-3, 4), false);
	CHECK_EQ(r.canMove(3, 7), true);
	CHECK_EQ(r.canMove(5, 4), true);
}

TEST_CASE("Testando o movimento")
{
	Torre r(3, 4);
	CHECK_THROWS(r.Move(3, 4));
	CHECK_THROWS(r.Move(-3, 4));
	CHECK_NOTHROW(r.Move(3, 7));
	CHECK_NOTHROW(r.Move(5, 7));
}

TEST_CASE("Testando nome")
{
	Torre r(3, 4);
	CHECK(r.getPeca() == "Torre");
}