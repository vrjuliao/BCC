/*
#include<constream>
#include<iostream>
#include<string>
#include "lista.h"
#include "itemlista.h"
#include "aluno.h"
#include "curso.h"

int main() {
    int total_de_alunos;
    std::string nome_do_aluno;
    int opcao1, opcao2;
    float nota;

    int numero_de_cursos;
    std::string nome_do_curso
    int vagas_do_curso;

    std::cin >> numero_de_cursos;
    std::cin >> total_de_alunos;
    
    int index;
    Curso *cursos = new (nothrow) Curso[numero_de_cursos];
    for(index = 0; index < numero_de_cursos; index++){
        std::cin >> nome_do_curso;
        std::cin >> vagas_do_curso;
        cursos[index].set_nome(nome_do_curso);
        cursos[index].set_vagas(vagas_do_curso);
        cursos[index].set_id(index);
    }

    Aluno *alunos = new (nothrow) Aluno[total_de_alunos];
    for(index = 0; index < total_de_alunos; index++){
        std::cin >> nome_do_aluno;
        std::cin >> nota;
        std::cin >> opcao1;
        std::cin >> opcao2;

        alunos[index].set_nome(nome_do_aluno);
        alunos[index].set_nota(nota);
        alunos[index].set_opcao1(opcao1);
        alunos[index].set_opcao2(opcao2);
    }



    // Ordenar o vetor

    // adicionando os alunos da primeira opcao
    Aluno *aluno_i;
    for(index = 0; index< total_de_alunos; index++){
        aluno_i = alunos[i];
        opcao1 = aluni_i
    }

    
}*/
#include<iostream>
#include "aluno.h"

int main(){
    Aluno **alunos = new Aluno* [2];
    alunos[0] = new Aluno("Juliao", 10, 10, 11);
    alunos[1] = new Aluno("Kelly", 10, 10, 11);
    
    std::cout << "Endereco de memoria aluno 0: " << alunos[0] << std::endl;
    std::cout << alunos[0]->get_name() << ": "<< alunos[0]->get_nota() << std::endl;
    Aluno *aluno = alunos[0];
    aluno->set_nota(897823);
    std::cout << alunos[0]->get_name() << ": " << alunos[0]->get_nota() << std::endl;
    std::cout << "Endereco de memoria aluno 1: " << alunos[1] << std::endl;
    std::cout << alunos[1]->get_name() << ": " << alunos[1]->get_nota() << std::endl;
    aluno = alunos[1];
    aluno->set_nota(101010);
    std::cout << alunos[1]->get_name() << ": " << alunos[1]->get_nota() << std::endl;
    delete aluno;
    aluno = alunos[0];
    delete aluno;
    std::cout << "Lindao" << std::endl;
    delete [] alunos;
    return 0;
}