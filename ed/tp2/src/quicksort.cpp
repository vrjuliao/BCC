#include "quicksort.hpp"

QuickSort::QuickSort(){
	mComparisons = 0;
}

int QuickSort::getting_pivot_index(int i, int j){
	return (i+j)/2;
}

template <class T>
void QuickSort::begin(T &vector[], int elements){
	sort(T vector[], 0, elements-1);
}

template <class T>
void QuickSort::sort(T &vector[], int &left, int &right){
	int i, j;
	partition(vector, left, right, i, j);
	if(left < j)
		sort(vector, left, j);
	if(i < rigth)
		sort(vector, i, right);
}

template <class T>
void QuickSort::partition(T &vector[], int left, int right, int &i, int &j){
	i = left;
	j = right;
	int pivot_index = getting_pivot_index(i, j);
	T pivot = vector[pivot_index];

	T aux;
	do{
		while(pivot.get_key() > vector[i].get_key()) i++;
		while(pivot.get_key() < vector[j].get_key()) j++;
		if(i <= j){
			aux = vector[i];
			vector[i] = vector[j];
			vector[j] = aux;
			i++;
			j++;
		}
	} while(i <= j);
}