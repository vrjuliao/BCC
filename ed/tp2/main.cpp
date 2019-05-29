#include <iostream>
#include <string>
#include <chrono>
#include "utils.hpp"
#include "quicksort.hpp"

int main(int argc, const char *argv[]){
    std::string algorithm_variation = argv[1];
    std::string vector_type = argv[2];
    int items_quantity = atoi(argv[3]);
    bool print_vector = false;
    if(argc == 5) {
        std::string last_argument = argv[4];
        print_vector = (last_argument == "-p");
    }

    int index = 0;
    const int MAX_ITERATIONS_TO_AVG = 21;
    int **vectors_to_print = new int*[MAX_ITERATIONS_TO_AVG];
    int *unique_vector;
    if (print_vector) {
        for(index = 0; index < MAX_ITERATIONS_TO_AVG; index++){
            vectors_to_print[index] = new int[items_quantity];
        }
    } else {
        unique_vector = new int[items_quantity];
    }
    
    std::cout << "Argc: " << argc << std::endl;
    std::cout << "Variacao algoritmo: " << algorithm_variation << std::endl;
    std::cout << "Tipo do vetor: " << vector_type << std::endl;
    std::cout << "Quantidade de Itens: " << items_quantity << std::endl;
    std::cout << "Print vector: " << print_vector << std::endl;

    // Pega o horoario do sistema antes da execucao do cpodigo
    //std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    int *vector;
    QuickSort qs;
    if(algorithm_variation == "QC") qs = QuickSort();
    else if(algorithm_variation == "QM3") int a = 1+1;//qs = QuickSort_Median();
    else if(algorithm_variation == "QPE")  int a = 1+1; //qs = QuickSort_FirstElement();
    else if(algorithm_variation == "QNR")  int a = 1+1; //qs = QuickSort_NonRecursive();
    else if(algorithm_variation == "QI1")  int a = 1+1; //qs = QuickSort_Insertion(1);
    else if(algorithm_variation == "QI5")  int a = 1+1; //qs = QuickSort_Insertion(5);
    else if(algorithm_variation == "QI10")  int a = 1+1; //qs = QuickSort_Insertion(10);
    
    void (*mount_vector)(int *, int);
    if(vector_type == "Ale") mount_vector = Utils::create_aleatory_vector;
    else if(vector_type == "OrdC") mount_vector = &Utils::create_increasing_vector;
    else if(vector_type == "OrdD") mount_vector = &Utils::create_decreasing_vector;

    float *executions_times = new float[MAX_ITERATIONS_TO_AVG];
    unsigned int sum_comparisons = 0;
    unsigned int sum_movimentations = 0;
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    std::chrono::duration<double, std::micro> elapsed_time;
    for(index = 0; index < MAX_ITERATIONS_TO_AVG; index++){
        if(print_vector){
            vector = vectors_to_print[index];
        } else {
            vector = unique_vector;
        }
        mount_vector(vector, items_quantity);
        t1 = std::chrono::high_resolution_clock::now();
        qs.begin(vector, items_quantity);
        t2 = std::chrono::high_resolution_clock::now();
        elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        executions_times[index] = elapsed_time.count();
        sum_comparisons += qs.get_comparisons();
        sum_movimentations += qs.get_movimentations();
    }
    //TODO - ordenar o vetor de tempos
    float median_time = executions_times[11];
    unsigned int comparisons_avg = sum_comparisons / MAX_ITERATIONS_TO_AVG;
    unsigned int movimentations_avg = sum_movimentations / MAX_ITERATIONS_TO_AVG;
    std::cout << std::endl;
    std::cout << algorithm_variation << " ";
    std::cout << vector_type         << " ";
    std::cout << items_quantity      << " ";
    std::cout << comparisons_avg     << " "; 
    std::cout << movimentations_avg  << " "; 
    std::cout << median_time         << std::endl;

    if(print_vector){
        for(index = 0; index < MAX_ITERATIONS_TO_AVG; index++){
            for(int indexJ = 0; indexJ < items_quantity; indexJ++){
                std::cout << vectors_to_print[index][indexJ] << " "; 
            }
            delete [] vectors_to_print[index];
            std::cout << std::endl;
        }
        delete [] vectors_to_print;
    } else {
        delete[] unique_vector;
    }

    /*std::cout << std::endl << "Increasing vector" << std::endl;
    Utils::create_increasing_vector(vector, items_quantity);
    for(int index = 0; index < items_quantity; index++){
        std::cout << vector[index] << ' ';
    }

    std::cout << std::endl << "Decreasing vector" << std::endl;
    Utils::create_decreasing_vector(vector, items_quantity);
    for(int index = 0; index < items_quantity; index++){
        std::cout << vector[index] << ' ';
    }

    std::cout << std::endl << "Aleatory vector" << std::endl;
    Utils::create_aleatory_vector(vector, items_quantity);
    for(int index = 0; index < items_quantity; index++){
        std::cout << vector[index] << ' ';
    }

    QuickSort qs = QuickSort();
    qs.begin(vector, items_quantity);
    std::cout << std::endl << "After sort" << std::endl;
    for(int index = 0; index < items_quantity; index++){
        std::cout << vector[index] << ' ';
    }*/

    // Pega o horario do sistema depois da execucao do codigo
    //std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    // Obtem a diferenca entre o horario de fim e o de inicio
    // std::chrono::duration<double, std::micro> elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    //std::cout << std::endl << "Tempo de execucao: " << elapsed_time.count() << " microssegundos" << std::endl;
    
    return 1;
}