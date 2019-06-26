#include "lista.h"
#include "itemlista.h"
#include "aluno.h"
#include "curso.h"
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    Lista *sisu = new Lista();

    int total_de_alunos;
    std::string nome_do_aluno;
    int opcao1, opcao2;
    float nota;

    int numero_de_cursos;
    std::string nome_do_curso;
    int vagas_do_curso;

    std::cin >> numero_de_cursos;
    std::cin >> total_de_alunos;
    
    //adiciona o vetor de cursos
    int index;
    Curso *cursos = new Curso[numero_de_cursos];
    for(index = 0; index < numero_de_cursos; index++){
        std::cin.ignore();
        getline(std::cin, nome_do_curso, '\n');
        std::cin >> vagas_do_curso;
        
        cursos[index].set_nome(nome_do_curso);
        cursos[index].set_vagas(vagas_do_curso);
    }

    //adiciona os alunos já ordenando-os pela nota
    ItemLista *item;
    Aluno *aluno;

    for(index = 0; index < total_de_alunos; index++){
        std::cin.ignore();
        getline(std::cin, nome_do_aluno, '\n');
        std::cin >> nota;
        std::cin >> opcao1;
        std::cin >> opcao2;
        
        aluno = new Aluno(nome_do_aluno, nota, opcao1, opcao2);
        
        sisu->insere_ordenado(aluno);
    }

    // adicionando os alunos da primeira opcao
    item = sisu->get_primeiro();
    for(index = 0; index < total_de_alunos; index++){
        item = item->get_proximo();
        aluno = item->get_conteudo();
        opcao1 = aluno->get_opcao1();
        cursos[opcao1].insere_fim(aluno);
    }

    // adicionando os alunos na segunda opção
    item = sisu->get_primeiro();
    for(index = 0; index < total_de_alunos; index++){
        item = item->get_proximo();
        aluno = item->get_conteudo();
        opcao1 = aluno->get_opcao1();

        if(cursos[opcao1].get_vagas() < aluno->get_posicao_opcao1()){
            cursos[aluno->get_opcao2()].insere_ordenado(aluno);
        }
    }

    //imprime os cursos
    cursos[0].imprime();
    for(index = 1; index < numero_de_cursos; index++){
        std::cout <<  std::endl;
        cursos[index].imprime();
    }

    //limpando a memoria
    
    // std::cout << std::endl << "deletando lista incial" << std::endl;
    sisu->free_content();
    delete sisu;

    // std::cout << std::endl << "deletando Cursos" << std::endl;
    delete [] cursos;

    return 1;
}