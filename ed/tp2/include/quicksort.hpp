#ifndef QUICKSORT_TP2
#define QUICKSORT_TP2

//template <class T>
class QuickSort {
protected:
	unsigned int mComparisons;
	unsigned int mMovimentations;
	virtual int getting_pivot(int vector[],int i, int j);
	virtual void sort(int vector[], int &left, int &right);
	virtual void partition(int vector[], int left, int right, int &i, int &j);
public:
	QuickSort();
	virtual void begin(int vector[], int num_elements);
	virtual int get_comparisons();
	virtual int get_movimentations();
};
//#include "../src/quicksort.cpp"
#endif