#ifndef QUICKSORT_MEDIAN_TP2
#define QUICKSORT_MEDIAN_TP2
#include "quicksort.hpp"

// the pivot is selectioned by median of three sub-vector elements
class QuickSort_Median : public QuickSort {
protected:
	// @Override QuickSort::getting_pivot
	// return pivot selectioning the median between first, last and central elements of the vector
    virtual unsigned int getting_pivot(unsigned int vector[], int i, int j) override;
public:
	QuickSort_Median();
	virtual ~QuickSort_Median();
};
#endif