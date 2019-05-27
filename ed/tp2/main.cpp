#include <iostream>
#include <string>

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

    
    return 1;
}