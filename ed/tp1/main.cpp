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
    // std::cout << std::endl;
    // std::cout << "============ adicionando cursos ============" << std::endl;
    // std::cout << numero_de_cursos << std::endl;
    Curso *cursos = new Curso[numero_de_cursos];
    for(index = 0; index < numero_de_cursos; index++){
        std::cin.ignore();
        getline(std::cin, nome_do_curso, '\n');
        //std::cin >> nome_do_curso;
        std::cin >> vagas_do_curso;
        
        // std::cout << nome_do_curso << ": " << numero_de_cursos << std::endl;
        
        cursos[index].set_nome(nome_do_curso);
        cursos[index].set_vagas(vagas_do_curso);
        cursos[index].set_id(index);
    }

    //adiciona os alunos já ordenando-os pela nota
    ItemLista *item;
    ItemLista *anterior;
    ItemLista *proximo;
    Aluno *aluno;

    //std::cout << std::endl;
    //std::cout << "============= Adicionando alunos ============="<< std::endl;
    //std::cout << total_de_alunos << std::endl;
    for(index = 0; index < total_de_alunos; index++){
        //std::cin >> nome_do_aluno;
        std::cin.ignore();
        getline(std::cin, nome_do_aluno, '\n');
        std::cin >> nota;
        std::cin >> opcao1;
        std::cin >> opcao2;
        
        aluno = new Aluno(nome_do_aluno, nota, opcao1, opcao2);
        
        
        proximo = sisu->get_last();
        if(aluno->get_nota() <= proximo->get_content()->get_nota())
            sisu->add_last(aluno);
        else{

            // std::cout << "Next of " << aluno->get_name() << std::endl;
            while(aluno->get_nota() > proximo->get_content()->get_nota()){
                // std::cout << "       " << proximo->get_content()->get_name() << std::endl;
                proximo = proximo->get_previous();
            }
            anterior = proximo;
            proximo = anterior->get_next();
            item = new ItemLista(anterior, aluno, proximo);
            // std::cout << "Nota do Anterior : " << anterior->get_content()->get_nota() << std::endl;
            // std::cout << "Nota do Proximo : " << proximo->get_content()->get_nota() << std::endl;
            anterior->set_next(item);
            proximo->set_previous(item);
        }
        // std::cout << "Aluno[i] = " << aluno->get_name() << std::endl;
    }

    // Aluno aluno_copy;
    // for(index = 1; index <= total_de_alunos; index++){
    //     // aluno_copy = sisu.get_item(index);
    //     aluno_copy = sisu.get_item(index)->get_content();
    //     std::cout << aluno_copy.get_name() << ": " << aluno_copy.get_nota()<< std::endl;
    // }



    // Ordenar o vetor

    // adicionando os alunos da primeira opcao
    item = sisu->get_first();
    for(index = 0; index < total_de_alunos; index++){
        item = item->get_next();
        aluno = item->get_content();
        opcao1 = aluno->get_option1();
        cursos[opcao1].add_last(aluno);
    }


    //pritar a selecao das primeiras opcoes selecionadas em cada curso
    for(index = 0; index < numero_de_cursos; index++){
        item = cursos[index].get_first()->get_next();
        // std::cout << "======Curso " << index << "======" << std::endl; 
        while (item != nullptr){
            aluno = item->get_content();
            // std::cout << aluno->get_name() << ": " << aluno->get_nota() << std::endl;
            item = item->get_next();
        }
    }


    item = sisu->get_first();
    for(index = 0; index < total_de_alunos; index++){
        item = item->get_next();
        aluno = item->get_content();
        opcao1 = aluno->get_option1();

        if(cursos[opcao1].get_vagas() < aluno->get_rank_option1()){
            // std::cout<< "Add:   " << aluno->get_name() << std::endl;
            cursos[aluno->get_option2()].add_on_second_option(aluno);
        }
    }

    // std::cout << std::endl;
    cursos[0].print();
    for(index = 1; index < numero_de_cursos; index++){
        // std::cout << "==========Curso " << index <<"=============" << std::endl;
        std::cout <<  std::endl;
        cursos[index].print();
    }

    //limpando a memoria
    
    // std::cout << std::endl << "deletando lista incial" << std::endl;
    sisu->free_content();
    delete sisu;

    // std::cout << std::endl << "deletando Cursos" << std::endl;
    delete [] cursos;

    return 1;
}