#include "quicksort.hpp"
#include <iostream>
//template <class T>
QuickSort::QuickSort(){
	mComparisons = 0;
	mMovimentations = 0;
}

//template <class T>
int QuickSort::getting_pivot_index(int i, int j){
	return (i+j)/2;
}

//template <class T>
void QuickSort::begin(int vector[], int elements){
	mComparisons = 0;
	mMovimentations = 0;
	int i = 0;
	elements--;
	sort(vector, i, elements);
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
	int pivot_index = getting_pivot_index(i, j);
	int pivot = vector[pivot_index];
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