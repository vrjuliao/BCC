#include "quicksort.hpp"
#include <iostream>
//template <class T>
QuickSort::QuickSort(){
	mComparisons = 0;
	mMovimentations = 0;
}

//template <class T>
int QuickSort::getting_pivot(int vector[], int i, int j){
	return vector[(i+j)/2];
}

//template <class T>
void QuickSort::begin(int vector[], int num_elements){
	mComparisons = 0;
	mMovimentations = 0;
	int i = 0;
	num_elements--;
	sort(vector, i, num_elements);
}

//template <class T>
void QuickSort::sort(int vector[], int &left, int &right){
	int i, j;
	partition(vector, left, right, i, j);
	mComparisons++;
	if(left < j)
		sort(vector, left, j);
	mComparisons++;
	if(i < right)
		sort(vector, i, right);
}

//template <class T>
void QuickSort::partition(int vector[], int left, int right, int &i, int &j){
	i = left;
	j = right;
	int pivot = getting_pivot(vector, i, j);
	int aux;
	do{
		while(pivot > vector[i]) {
			i++;
		}
		while(pivot < vector[j]) {
			j--;
		}
		mComparisons++;
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

int QuickSort::get_comparisons(){
	return mComparisons;
}

int QuickSort::get_movimentations(){
	return mMovimentations;
}

QuickSort::~QuickSort(){}