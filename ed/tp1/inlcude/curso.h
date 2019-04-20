#include<string>
#include"lista.h"
#include"itemlista.h"
#include"aluno.h"
#include"lista.h"

class Curso : public Lista{
private:
    std::string nome;
    int id;
    int vagas;
    int alunos_inseridos;

public:
    Curso(std::string mNome, int mId, int mVagas);
    int get_vagas();
    std::string get_nome();
    int get_alunos_inseridos();
    void add_last(Aluno *aluno);
}