#ifndef QUICKSORT_NON_RECURSIVE_TP2
#define QUICKSORT_NON_RECURSIVE_TP2
#include "quicksort.hpp"
#include "stack.hpp"
// Non recursive way to execute quicksort
class QuickSort_NonRecursive : public QuickSort {
protected:
	// @override QuickSort::sort
	// execute quicksort through non recursive algorithm
	virtual void sort(unsigned int vector[], int &left, int &right) override;
public:
	QuickSort_NonRecursive();
	virtual ~QuickSort_NonRecursive();
};
#endif