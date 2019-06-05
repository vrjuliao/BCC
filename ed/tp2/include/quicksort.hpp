#ifndef QUICKSORT_TP2
#define QUICKSORT_TP2

// Standard way to sort element by quicksort
class QuickSort {
protected:
	unsigned int mComparisons;
	unsigned int mMovimentations;

	//get the pivot selectioning the central element of the vector
	virtual unsigned int getting_pivot(unsigned int vector[], int i, int j);

	//recursive method, responsible to sort elements
	virtual void sort(unsigned int vector[], int &left, int &right);

	//divide the vector in two subvectors, classifying the elements larger and smaller than the pivot 
	virtual void partition(unsigned int vector[], int left, int right, int &i, int &j);
public:
	QuickSort();

	// start sort procedure
	virtual void begin(unsigned int vector[], int num_elements);
	
	virtual unsigned int get_comparisons();
	virtual unsigned int get_movimentations();
	virtual ~QuickSort();
};
//#include "../src/quicksort.cpp"
#endif