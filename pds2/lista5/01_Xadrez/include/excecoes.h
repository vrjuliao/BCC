#ifndef EXCECOES
#define EXCECOES
#include <stdexcept>

class InvalidMovimentException : public std::exception{};
class InvalidPositionException: public std::exception{};
class MovimentoInvalidoException: public std::exception{};
class PosicaoSemPecaException: public std::exception{};
class PosicaoInexistente: public std::exception{};

#endif