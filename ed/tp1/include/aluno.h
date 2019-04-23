#ifndef ALUNO_TP1_ED
#define ALUNO_TP1_ED

#include<string>
#include<iostream>

class Aluno {
private:
    std::string name;
    int nota;
    int option1;
    int option2;
    int rank_option1;
    int rank_option2;
public:
    Aluno();
    Aluno(std::string mName, int mNota, int mOption1, int mOption2);
    std::string get_name();
    int get_option1();
    int get_option2();
    int get_nota();
    void set_name(std::string mName);
    void set_option1(int mOption1);
    void set_option2(int mOption2);
    void set_nota(int mNota);
    void set_rank_option1(int rank);
    void set_rank_option2(int rank);
    int get_rank_option1();
    int get_rank_option2();
    ~Aluno();
};

#endif