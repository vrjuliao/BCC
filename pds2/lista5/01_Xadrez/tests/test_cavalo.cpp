#include "../include/cavalo.h"
#include"doctest.h"

TEST_CASE("Testando o Construtor")
{
	CHECK_THROWS(Cavalo r(-2, -4));
	CHECK_THROWS(Cavalo r(8, 8));
	CHECK_NOTHROW(Cavalo r(0, 0));
	CHECK_NOTHROW(Cavalo r(3, 4));
}
TEST_CASE("Testando getters")
{
	Cavalo r(3, 4);
	CHECK(r.getX() == 3);
	CHECK(r.getY() == 4);
}

TEST_CASE("Testando pode mover")
{
	Cavalo r(3, 4);
	CHECK_EQ(r.canMove(4, 6), true);
	CHECK_EQ(r.canMove(5, 5), true);
	CHECK_EQ(r.canMove(-1, 5), false);
	CHECK_EQ(r.canMove(3, 4), false);
	//CHECK(r.canMove(5, 3));
	// CHECK(r.canMove(2, 6));
	// CHECK(r.canMove(4, 6));
}

TEST_CASE("Testando falhas no movimento")
{
	Cavalo r(3, 4);
	CHECK_THROWS(r.Move(3, 4));
	CHECK_THROWS(r.Move(-1, 5));
	CHECK_NOTHROW(r.Move(5, 5));
	CHECK_NOTHROW(r.Move(4, 3));
	CHECK_THROWS(r.Move(6, 6));
	//CHECK(r.canMove(5, 3));
	// CHECK(r.canMove(2, 6));
	// CHECK(r.canMove(4, 6));
}


TEST_CASE("Testando nome")
{
	Cavalo r(3, 4);
	CHECK(r.getPeca() == "Cavalo");
}