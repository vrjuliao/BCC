#include "quicksort_median.hpp"
QuickSort_Median::QuickSort_Median():QuickSort(){}

unsigned int QuickSort_Median::getting_pivot(unsigned int vector[],int i, int j){
    int central_index = (i+j)/2;
    unsigned int median = vector[i];
    mComparisons+=4;
    if((median < vector[central_index] && median < vector[j])
    || (median > vector[central_index] && median > vector[j])){
        mComparisons+=4;
        median = vector[j];
        if((median < vector[central_index] && median < vector[i])
        || (median > vector[central_index] && median > vector[i])){
            median = vector[central_index];
        }
    }
    return median;
}

QuickSort_Median::~QuickSort_Median(){}