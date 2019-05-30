#include "quicksort_first_element.hpp"
#include <iostream>
QuickSort_FirstElement::QuickSort_FirstElement():QuickSort(){
    //std::cout << "quicksortfirstelement" << std::endl;
}

int QuickSort_FirstElement::getting_pivot(int vector[],int i, int j){
    return vector[i];
}

QuickSort_FirstElement::~QuickSort_FirstElement(){}