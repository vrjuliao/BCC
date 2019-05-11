#ifndef CURSO_TP1_ED
#define CURSO_TP1_ED

#include <string>
#include <iostream>
#include <iomanip>
#include "lista.h"
#include "itemlista.h"
#include "aluno.h"
#include "lista.h"

class Curso : public Lista{
private:
    std::string nome;
    int vagas;
    float nota_de_corte;
    int alunos_inseridos;

public:
    Curso();
    Curso(std::string mNome, int mVagas);
    void set_nome(std::string mNome);
    void set_vagas(int mVagas);
    int get_vagas();
    std::string get_nome();
    int get_alunos_inseridos();
    void insere_ordenado(Aluno *aluno);
    void insere_fim(Aluno *aluno);
    void imprime();
    ~Curso();
};
#endif