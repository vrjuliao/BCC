#ifndef QUICKSORT_NON_RECURSIVE_TP2
#define QUICKSORT_NON_RECURSIVE_TP2
#include "quicksort.hpp"
#include "stack.hpp"
//template <class T>
class QuickSort_NonRecursive : public QuickSort {
protected:
	virtual void sort(int vector[], int &left, int &right);
public:
	QuickSort_NonRecursive();
	virtual ~QuickSort_NonRecursive();
};
//#include "../src/quicksort.cpp"
#endif