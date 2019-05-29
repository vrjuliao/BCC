#include <iostream>
#include <string>
#include <chrono>
#include "utils.hpp"
#include "quicksort.hpp"
#include "quicksort_median.hpp"
#include "quicksort_insertion.hpp"
#include "quicksort_first_element.hpp"

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
    if (print_vector) {
        for(index = 0; index < MAX_ITERATIONS_TO_AVG; index++){
            vectors_to_print[index] = new int[items_quantity];
        }
    }
    
    std::cout << "Argc: " << argc << std::endl;
    std::cout << "Variacao algoritmo: " << algorithm_variation << std::endl;
    std::cout << "Tipo do vetor: " << vector_type << std::endl;
    std::cout << "Quantidade de Itens: " << items_quantity << std::endl;
    std::cout << "Print vector: " << print_vector << std::endl;

    int *vector = new int[items_quantity];
    QuickSort *qs;
    if(algorithm_variation == "QC") qs = new QuickSort();
    else if(algorithm_variation == "QM3") qs = new QuickSort_Median();
    else if(algorithm_variation == "QPE") qs = new QuickSort_FirstElement();
    else if(algorithm_variation == "QNR")  int a = 1+1;//qs = new QuickSort_NonRecursive();
    else if(algorithm_variation == "QI1")  qs = new QuickSort_Insertion(1);
    else if(algorithm_variation == "QI5")  qs = new QuickSort_Insertion(5);
    else if(algorithm_variation == "QI10") qs = new QuickSort_Insertion(10);
    
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
            mount_vector(vectors_to_print[index], items_quantity);
            Utils::copy_vector(vectors_to_print[index], vector, items_quantity);
        } else {
            mount_vector(vector, items_quantity);
        }
        t1 = std::chrono::high_resolution_clock::now();
        qs->begin(vector, items_quantity);
        t2 = std::chrono::high_resolution_clock::now();
        elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        
        std::cout << std::endl << "After ordened: " << std::endl;
        for(int j = 0; j < items_quantity; j++){
			std::cout << vector[j] << " ";
		}

        executions_times[index] = elapsed_time.count();
        sum_comparisons += qs->get_comparisons();
        sum_movimentations += qs->get_movimentations();
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
    }
    delete [] vectors_to_print;
    delete [] vector;
    delete qs;
   return 1;
}