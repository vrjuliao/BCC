#ifndef QUICKSORT_INSERTION_TP2
#define QUICKSORT_INSERTION_TP2
#include "quicksort_median.hpp"

// execute the quicksort until a quantity specified of elements
// then, execute insertion sort
// the pivot is selectioned by median of three sub-vector elements
class QuickSort_Insertion : public QuickSort_Median{
private:
	int mPercentual; //Define the percentual of elements that will be sorted by 'insertion sort'
	int mNumElementsToBeginInsertionSort;

	//sort by insertion algorithm
	void insertion_sort(unsigned int vector[], int left, int right);
public:
	QuickSort_Insertion(int percentual);

	// @override QuickSort_Median::QuickSort::begin
	// calculate quantity of elements necessary to start insertion sort and start the recursivity of quicksort 
	virtual void begin(unsigned int vector[], int num_elements) override;
protected:
	// @override QuickSort_Median::QuickSort::sort
	// verify if the quantity of elements is correct to begin insertion sort
	// start insertion sort or restart the recursivity of quicksort according the quantity of elements on the sub-vector
	virtual void sort(unsigned int vector[], int &left, int &right) override;
	virtual ~QuickSort_Insertion();
};
#endif