#include "quicksort_non_recursive.hpp"
#include "quicksort.hpp"
//template <class T>
QuickSort_NonRecursive::QuickSort_NonRecursive(): QuickSort(){}

//template <class T>
void QuickSort_NonRecursive::sort(int vector[], int &left, int &right){
	Stack stack = Stack(right+1);
	int i, j;
	pair p;
	p.left = left;
	p.right = right;
	stack.push(p);
	do{
		if (right > left) {
			partition(vector, left, right, i, j);

			if ((j-left) > (right-i)){
				p.left = left;
				p.right = j;
				stack.push(p);
				left = i;
			} else {
				p.left = i;
				p.right = right;
				stack.push(p);
				right = j;
			}
		} else {
			p = stack.pop();
			left = p.left;
			right = p.right;
		}
	} while (!stack.is_empty());
}

QuickSort_NonRecursive::~QuickSort_NonRecursive(){}