#ifndef QUICKSORT_FIRST_ELEMENT_TP2
#define QUICKSORT_FIRST_ELEMENT_TP2
#include "quicksort.hpp"
class QuickSort_FirstElement : public QuickSort {
protected:
	virtual int getting_pivot(int vector[],int i, int j);	
public:
	QuickSort_FirstElement();
	virtual ~QuickSort_FirstElement();
};
#endif