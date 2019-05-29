#ifndef QUICKSORT_MEDIAN_TP2
#define QUICKSORT_MEDIAN_TP2
#include "quicksort.hpp"
class QuickSort_Median : public QuickSort {
protected:
    virtual int getting_pivot(int vector[],int i, int j) override;
public:
	QuickSort_Median();
};
#endif