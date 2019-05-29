#include "quicksort_median.hpp"
#include <iostream>
QuickSort_Median::QuickSort_Median():QuickSort(){
    // std::cout << "quicksortmedian" << std::endl;
}

int QuickSort_Median::getting_pivot(int vector[],int i, int j){
    // std::cout << "quicksortmedian" << std::endl;
    int central_index = (i+j)/2;
    int median = vector[i];
    if((median < vector[central_index] && median < vector[j])
    || (median > vector[central_index] && median > vector[j])){
        median = vector[j];
        if((median < vector[central_index] && median < vector[i])
        || (median > vector[central_index] && median > vector[i])){
            median = vector[central_index];
        }
    }
    return median;
}