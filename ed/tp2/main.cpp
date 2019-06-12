#include <iostream>
#include <string>
#include <chrono>
#include "utils.hpp"
#include "quicksort.hpp"
#include "quicksort_median.hpp"
#include "quicksort_insertion.hpp"
#include "quicksort_first_element.hpp"
#include "quicksort_non_recursive.hpp"

/*Execute a quicksort variation 21 times, for 21 different vectors
/@params
    algorithm_variation: Type of variantion, shold be between (QC, QM3, QPE, QNR, QI1, QI10, QI5)
    vector_type: Type vector organization, shold be between (Ale, OrdC, OrdD)
    items_quantity: Quantity of elements in vectors that will be sorted
    print_vector: flag to specify if the 21 vectors will be printed
*/
void execute_whith_params(std::string algorithm_variation, std::string vector_type, 
                          unsigned int items_quantity, bool print_vector){

    unsigned int *vector = new unsigned int[items_quantity];
    QuickSort *qs;
    //Select class of algorith variation using polimorfism
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
    
    //select way to construct vectors for sort operaions
    void (*mount_vector)(unsigned int *, unsigned int);
    if(vector_type == "Ale") mount_vector = &Utils::create_aleatory_vector;
    else if(vector_type == "OrdC") mount_vector = &Utils::create_increasing_vector;
    else if(vector_type == "OrdD") mount_vector = &Utils::create_decreasing_vector;
    else {
        std::cout << "ERROR: Incorrect params" << std::endl;
        exit(1);
    }

    //manipulations of the vectors allocations, acoording to the need to print these vectors
    int index = 0;
    const int MAX_ITERATIONS_TO_AVG = 21;
    unsigned int **vectors_to_print = new unsigned int*[MAX_ITERATIONS_TO_AVG];
    if (print_vector) {
        for(index = 0; index < MAX_ITERATIONS_TO_AVG; index++){
            vectors_to_print[index] = new unsigned int[items_quantity];
        }
    }

    //instantiation of time manipulators
    unsigned int *executions_times = new unsigned int[MAX_ITERATIONS_TO_AVG];
    unsigned long int sum_comparisons = 0;
    unsigned long int sum_movimentations = 0;
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    std::chrono::duration<double, std::micro> elapsed_time;

    //execute 21 loops, according specified  previously
    for(index = 0; index < MAX_ITERATIONS_TO_AVG; index++){
        if(print_vector){
            mount_vector(vectors_to_print[index], items_quantity);
            Utils::copy_vector(vectors_to_print[index], vector, items_quantity);
        } else {
            mount_vector(vector, items_quantity);
        }
        //init time
        t1 = std::chrono::high_resolution_clock::now();
        //sort vector
        qs->begin(vector, items_quantity);
        //end time
        t2 = std::chrono::high_resolution_clock::now();
        //difference between init and end time
        elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        // out data manipulation to calculate average and median of these data
        executions_times[index] = static_cast<unsigned int>(elapsed_time.count());
        sum_comparisons += qs->get_comparisons();
        sum_movimentations += qs->get_movimentations();
    }
    //sort the vector of times to get the median
    qs->begin(executions_times, MAX_ITERATIONS_TO_AVG);
    unsigned int median_time = executions_times[11];

    //calculate average of comparations and movimentations
    unsigned long int comparisons_avg = sum_comparisons / MAX_ITERATIONS_TO_AVG;
    unsigned long int movimentations_avg = sum_movimentations / MAX_ITERATIONS_TO_AVG;

    //print out data
    std::cout << algorithm_variation  << " ";
    std::cout << vector_type          << " ";
    std::cout << items_quantity       << " ";
    std::cout << comparisons_avg      << " ";
    std::cout << movimentations_avg   << " ";
    std::cout << median_time << std::endl;

    //According to the necessity of print vectors, execute print operations
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

    //prevent memory leaks
    delete [] vectors_to_print;
    delete [] vector;
    delete [] executions_times;
    delete qs;
}

//execute all study case of proposed exercice
void execute_work_tests(){
    //all algorithm variations
    std::string algorithm_names[] = {"QC", "QM3", "QPE", "QI1", "QI5", "QI10", "QNR"};
    //all vectors organizarion
    std::string vector_types[] = {"OrdC", "OrdD", "Ale"};
    unsigned int vector_length;
    for(int index_i = 0; index_i < 7; index_i++){
        for(int index_j = 0; index_j < 3; index_j++){
            //all values proposed by work description
            for(vector_length = 50000; vector_length <= 500000; vector_length+=50000){
                execute_whith_params(algorithm_names[index_i], vector_types[index_j], vector_length, false);
            }
        }
    }
}


int main(int argc, const char *argv[]){
    // Maniupulations of parameters received by execution of this program
    // the number of parametrs shoul be 0, 3 or 4 and need to be correct according work description
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
