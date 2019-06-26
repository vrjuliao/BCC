#include "quicksort.hpp"
QuickSort::QuickSort(){
	mComparisons = 0;
	mMovimentations = 0;
}

unsigned int QuickSort::getting_pivot(unsigned int vector[], int i, int j){
	return vector[(i+j)/2];
}

void QuickSort::begin(unsigned int vector[], int num_elements){
	mComparisons = 0;
	mMovimentations = 0;
	int i = 0;
	num_elements--;
	sort(vector, i, num_elements);
}

void QuickSort::sort(unsigned int vector[], int &left, int &right){
	int i, j;
	partition(vector, left, right, i, j);
	if(left < j)
		sort(vector, left, j);
	if(i < right)
		sort(vector, i, right);
}

void QuickSort::partition(unsigned int vector[], int left, int right, int &i, int &j){
	i = left;
	j = right;
	unsigned int pivot = getting_pivot(vector, i, j);
	unsigned int aux;
	do{
		mComparisons++;	
		while(pivot > vector[i]) {
			i++;
			mComparisons++;
		}
		mComparisons++;	
		while(pivot < vector[j]) {
			j--;
			mComparisons++;
		}
		if(i <= j){
			aux = vector[i];
			vector[i] = vector[j];
			vector[j] = aux;
			mMovimentations++;
			i++;
			j--;
		}
	} while(i <= j);
}

unsigned long int QuickSort::get_comparisons(){
	return mComparisons;
}

unsigned long int QuickSort::get_movimentations(){
	return mMovimentations;
}

QuickSort::~QuickSort(){}