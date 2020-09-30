#ifndef ALUNO_TP1_ED
#define ALUNO_TP1_ED

#include <string>
//#include<iostream>

class Aluno {
private:
    std::string nome;
    float nota;
    int opcao1;
    int opcao2;
    int posicao_opcao1; //colocacao do aluno em sua primeira opcao de curso
public:
    Aluno();
    Aluno(std::string mNome, float mNota, int mOpcao1, int mOpcao2);
    std::string get_nome();
    int get_opcao1();
    int get_opcao2();
    float get_nota();
    void set_nome(std::string mNome);
    void set_opcao1(int mOpcao1);
    void set_opcao2(int mOpcao2);
    void set_nota(float mNota);
    void set_posicao_opcao1(int rank);
    int get_posicao_opcao1();
    ~Aluno();
};

#endif