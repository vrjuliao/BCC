#ifndef UTILS_NAMESPACE_TP2
#define UTILS_NAMESPACE_TP2
#include <cstdlib>
#include <ctime>
#include <chrono>

namespace Utils {
	void create_aleatory_vector(unsigned int vector[], unsigned int length);

	void create_decreasing_vector(unsigned int vector[], unsigned int length);

	void create_increasing_vector(unsigned int vector[], unsigned int length);
	
	void copy_vector(unsigned int copy_vector[], unsigned int paste_vector[], unsigned int length);
}
#endif