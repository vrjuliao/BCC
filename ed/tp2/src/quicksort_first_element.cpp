#include "quicksort_first_element.hpp"
QuickSort_FirstElement::QuickSort_FirstElement():QuickSort(){}

unsigned int QuickSort_FirstElement::getting_pivot(unsigned int vector[], int i, int j){
    return vector[i];
}

QuickSort_FirstElement::~QuickSort_FirstElement(){}