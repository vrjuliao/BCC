#include <iostream>
#include "../include/tabuleiro.h"
#include"../include/excecoes.h"
#include <stdexcept>


int main() {

	try
	{ 
		Tabuleiro tab;
		Posicao a(4, 5);
		Posicao b(2, 3);
		tab.move(a, b);
	}
	catch (std::exception e)
	{

	}
    return 0;
}
