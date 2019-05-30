#ifndef QUICKSORT_INSERTION_TP2
#define QUICKSORT_INSERTION_TP2
#include "quicksort_median.hpp"
class QuickSort_Insertion : public QuickSort_Median{
private:
	int mPercentual; //Define the percentual of elements that will be sorted by 'selection sort'
	int mNumElementsToBeginInsertionSort;
	void insertion_sort(int vector[], int left, int right);
public:
	QuickSort_Insertion(int percentual);
	virtual void begin(int vector[], int num_elements) override;
protected:
	virtual void sort(int vector[], int &left, int &right);
	virtual ~QuickSort_Insertion();
	//virtual void partition(int vector[], int left, int right, int &i, int &j);
};
#endif