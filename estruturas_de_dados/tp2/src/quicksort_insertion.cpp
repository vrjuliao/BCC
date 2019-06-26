#include "quicksort_insertion.hpp"
QuickSort_Insertion::QuickSort_Insertion(int percentual):
QuickSort_Median(){
    mPercentual = percentual;
}

void QuickSort_Insertion::sort(unsigned int vector[], int &left, int &right){
    if((right-left) <=  mNumElementsToBeginInsertionSort){
        insertion_sort(vector, left, right);
    } else {
        QuickSort_Median::sort(vector, left, right);
    }
}

void QuickSort_Insertion::begin(unsigned int vector[], int num_elements){
    mNumElementsToBeginInsertionSort = (num_elements*mPercentual)/100;
    mComparisons = 0;
	mMovimentations = 0;
	int i = 0;
	num_elements--;
	sort(vector, i, num_elements);
}

void QuickSort_Insertion::insertion_sort(unsigned int vector[], int left, int right){
    unsigned int current_element;
    int i, j;
    for(i = left+1; i<=right; i++){
        current_element = vector[i];
        mComparisons++;
        for(j = i-1; (j >= left) && current_element < vector[j]; j--){
            vector[j+1] = vector[j];
            mMovimentations++;
            mComparisons++;
        }
        mMovimentations++;  
        vector[j+1] = current_element;
    }
}

QuickSort_Insertion::~QuickSort_Insertion(){}