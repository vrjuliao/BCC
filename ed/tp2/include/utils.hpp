#ifndef UTILS_NAMESPACE_TP2
#define UTILS_NAMESPACE_TP2
#include <cstdlib>
#include <ctime>
#include <chrono>

namespace Utils {
	/*template <class T>
	void create_aleatory_vector(T *vector, int length);

	template <class T>
	void create_decreasing_vector(T *vector, int length);

	template <class T>
	void create_increasing_vector(T *vector, int length);

	template <class T>
	void clear_vector(T vector[], int length);*/

	void create_aleatory_vector(int vector[], int length);

	void create_decreasing_vector(int vector[], int length);

	void create_increasing_vector(int vector[], int length);

	void clear_vector(int vector[], int length);
}
//#include "../src/utils.cpp"
#endif