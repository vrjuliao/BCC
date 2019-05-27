#ifndef QUICKSORT_TP2
#define QUICKSORT_TP2

template <class T>
class QuickSort {
protected:
	int mComparisons;
	virtual getting_pivot_index(int i, int j);
public:
	QickSort();
	virtual void begin(T &vector[], int elements);
	virtual void sort();
	virtual void partition();
	virtual int get_comparisons();
}

#endif