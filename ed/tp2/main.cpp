#include <iostream>
#include <string>
#include <chrono>

int main(int argc, const char *argv[]){
    std::string algorithm_variation = argv[1];
    std::string vector_type = argv[2];
    int items_quantity = atoi(argv[3]);
    bool print_vector = false;
    if(argc == 5) {
        std::string last_argument = argv[4];
        print_vector = (last_argument == "-p");
    }
    
    std::cout << "Argc: " << argc << std::endl;
    std::cout << "Variacao algoritmo: " << algorithm_variation << std::endl;
    std::cout << "Tipo do vetor: " << vector_type << std::endl;
    std::cout << "Quantidade de Itens: " << items_quantity << std::endl;
    std::cout << "Print vector: " << print_vector << std::endl;


    // Pega o horoario do sistema antes da execucao do cpodigo
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();



    // Pega o horario do sistema depois da execucao do codigo
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    // Obtem a diferenca entre o horario de fim e o de inicio
    std::chrono::duration<double, std::micro> elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "Tempo de execucao: " << elapsed_time.count() << " microssegundos" << std::endl;
    
    return 1;
}