#ifndef UTILS_NAMESPACE_TP2
#define UTILS_NAMESPACE_TP2
#include <stdlib.h>
namespace Utils {

	template <class T>
	T *create_aleatory_vector(int length);
	template <class T>
	T *create_decreasing_vector(int length);
	template <class T>
	T *create_increasing_vector(int length);
	template <class T>
	void clear_vector(T &vector[], int length);

}

#endif