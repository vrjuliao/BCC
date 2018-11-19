#include "doctest.h"
#include "triangulo.h"


TEST_CASE("Teste VPL - Equilatero") {
    Triangulo t(5, 5, 5);
    Tipo tipo = t.determinar_tipo();
    CHECK_EQ(tipo, Tipo::EQUILATERO);
}

TEST_CASE("Teste VPL - Excecao Negativo") {
    CHECK_THROWS(new Triangulo(5, -5, 5));
}

TEST_CASE("Teste VPL - Escaleno") {
    Triangulo t(9, 5, 6);
    Tipo tipo = t.determinar_tipo();
    CHECK_EQ(tipo, Tipo::ESCALENO);
}

TEST_CASE("Teste VPL - Isosceles") {
    Triangulo t(3, 3, 1);
    Tipo tipo = t.determinar_tipo();
    CHECK_EQ(tipo, Tipo::ISOSCELES);
}

TEST_CASE("Teste VPL - Isosceles 2") {
    Triangulo t(1, 3, 3);
    Tipo tipo = t.determinar_tipo();
    CHECK_EQ(tipo, Tipo::ISOSCELES);
}

TEST_CASE("Teste VPL - Isosceles 3") {
    Triangulo t(3, 1, 3);
    Tipo tipo = t.determinar_tipo();
    CHECK_EQ(tipo, Tipo::ISOSCELES);
}


TEST_CASE("Teste VPL - Triangulo inexistente") {
    CHECK_THROWS(new Triangulo(3, 1, 1));
    CHECK_THROWS(new Triangulo(1, 7, 9));
    CHECK_THROWS(new Triangulo(1, 9, 7));
}