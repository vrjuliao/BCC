#ifndef QUICKSORT_FIRST_ELEMENT_TP2
#define QUICKSORT_FIRST_ELEMENT_TP2
#include "quicksort.hpp"
// change the standard quicksort by selecting pivot for the first sub-vector element
class QuickSort_FirstElement : public QuickSort {
protected:
	// @Override QuickSort::getting_pivot
	// return pivot selectioning the first element of the vector
	virtual unsigned int getting_pivot(unsigned int vector[], int i, int j) override;	
public:
	QuickSort_FirstElement();
	virtual ~QuickSort_FirstElement();
};
#endif