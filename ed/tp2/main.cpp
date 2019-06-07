#include <iostream>
#include <string>
#include <chrono>
#include "utils.hpp"
#include "quicksort.hpp"
#include "quicksort_median.hpp"
#include "quicksort_insertion.hpp"
#include "quicksort_first_element.hpp"
#include "quicksort_non_recursive.hpp"

void execute_whith_params(std::string algorithm_variation, std::string vector_type, 
                          unsigned int items_quantity, bool print_vector){

    unsigned int *vector = new unsigned int[items_quantity];
    QuickSort *qs;
    if(algorithm_variation == "QC") qs = new QuickSort();
    else if(algorithm_variation == "QM3") qs = new QuickSort_Median();
    else if(algorithm_variation == "QPE") qs = new QuickSort_FirstElement();
    else if(algorithm_variation == "QNR")  qs = new QuickSort_NonRecursive();
    else if(algorithm_variation == "QI1")  qs = new QuickSort_Insertion(1);
    else if(algorithm_variation == "QI5")  qs = new QuickSort_Insertion(5);
    else if(algorithm_variation == "QI10") qs = new QuickSort_Insertion(10);
    else {
        std::cout << "ERROR: Incorrect params" << std::endl;
        exit(1);
    }
    
    void (*mount_vector)(unsigned int *, unsigned int);
    if(vector_type == "Ale") mount_vector = &Utils::create_aleatory_vector;
    else if(vector_type == "OrdC") mount_vector = &Utils::create_increasing_vector;
    else if(vector_type == "OrdD") mount_vector = &Utils::create_decreasing_vector;
    else {
        std::cout << "ERROR: Incorrect params" << std::endl;
        exit(1);
    }

    int index = 0;
    const int MAX_ITERATIONS_TO_AVG = 21;
    // const int MAX_ITERATIONS_TO_AVG = 1;
    unsigned int **vectors_to_print = new unsigned int*[MAX_ITERATIONS_TO_AVG];
    if (print_vector) {
        for(index = 0; index < MAX_ITERATIONS_TO_AVG; index++){
            vectors_to_print[index] = new unsigned int[items_quantity];
        }
    }

    unsigned int *executions_times = new unsigned int[MAX_ITERATIONS_TO_AVG];
    unsigned long int sum_comparisons = 0;
    unsigned long int sum_movimentations = 0;
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
        
        /*std::cout << std::endl << "After ordened: " << std::endl;
        for(int j = 0; j < items_quantity; j++){
			std::cout << vector[j] << " ";
		}*/

        executions_times[index] = static_cast<unsigned int>(elapsed_time.count());
        sum_comparisons += qs->get_comparisons();
        sum_movimentations += qs->get_movimentations();
    }
    //TODO - ordenar o vetor de tempos
    qs->begin(executions_times, MAX_ITERATIONS_TO_AVG);
    unsigned int median_time = executions_times[11];
    unsigned int comparisons_avg = sum_comparisons / MAX_ITERATIONS_TO_AVG;
    unsigned int movimentations_avg = sum_movimentations / MAX_ITERATIONS_TO_AVG;
    //std::cout << std::endl;
    std::cout << algorithm_variation  << " ";
    std::cout << vector_type          << " ";
    std::cout << items_quantity       << " ";
    std::cout << comparisons_avg      << " ";
    std::cout << movimentations_avg   << " ";
    std::cout << median_time << std::endl;

    unsigned int *v;
    if(print_vector){
        for(index = 0; index < MAX_ITERATIONS_TO_AVG; index++){
            for(unsigned int indexJ = 0; indexJ < items_quantity; indexJ++){
                std::cout << vectors_to_print[index][indexJ] << " "; 
            }
            v = vectors_to_print[index];
            delete [] v;
            std::cout << std::endl;
        }
    }
    delete [] vectors_to_print;
    delete [] vector;
    delete [] executions_times;
    delete qs;
}

void execute_work_tests(){
    std::string algorithm_names[] = {"QC", "QM3", "QPE", "QI1", "QI5", "QI10", "QNR"};
    std::string vector_types[] = {"OrdC", "OrdD", "Ale"};
    unsigned int vector_length;
    for(int index_i = 0; index_i < 7; index_i++){
        for(int index_j = 0; index_j < 3; index_j++){
            for(vector_length = 50000; vector_length <= 500000; vector_length+=50000){
                execute_whith_params(algorithm_names[index_i], vector_types[index_j], vector_length, false);
            }
        }
    }
}

int main(int argc, const char *argv[]){
    if(argc > 1 && (argc < 4 || argc > 5)){
        std::cout << "ERROR: Incorrect params" << std::endl;
        exit(1);
    } else if(argc > 1){
        std::string algorithm_variation = argv[1];
        std::string vector_type = argv[2];
        unsigned int items_quantity;
        int quantity;
        try{
            quantity = atoi(argv[3]);
        } catch (std::exception &e){
            std::cout << "ERROR: Incorrect params" << std::endl;
            exit(1);
        }
        if(quantity < 0){
            std::cout << "ERROR: Incorrect params" << std::endl;
            exit(1);
        } else {
            items_quantity = static_cast<unsigned int>(quantity);
        }
        bool print_vector = false;
        if(argc == 5) {
            std::string last_argument = argv[4];
            if((last_argument == "-p")){
                print_vector = true;;
            } else {
                std::cout << "ERROR: Incorrect params" << std::endl;
                exit(1);
            }
        }
        execute_whith_params(algorithm_variation, vector_type, items_quantity, print_vector);
    } else {
        execute_work_tests();
    }
    return 1;
}