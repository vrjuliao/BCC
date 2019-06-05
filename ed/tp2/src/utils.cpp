#include "utils.hpp"
namespace Utils {
	void create_aleatory_vector(unsigned int vector[], unsigned int length){
		auto now = std::chrono::system_clock::now();
    	auto now_ms = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    	auto value = now_ms.time_since_epoch();
    	long duration = value.count();
		std::srand(duration);
		for(unsigned int index = 0; index < length; index++){
			vector[index] = (std::rand()%length) + 1;
		}
	}

	void create_increasing_vector(unsigned int vector[], unsigned int length){
		for(unsigned int index = 0; index < length; index++) {
			vector[index] = index+1;
		}
	}

	void create_decreasing_vector(unsigned int vector[], unsigned int length){
		for(unsigned int index = 0; index < length; index++){
			vector[index] = length-index;
		}
	}

	void copy_vector(unsigned int copy_vector[], unsigned int paste_vector[], unsigned int length){
		for(unsigned int index = 0; index < length; index++)
			paste_vector[index] = copy_vector[index];
	}
}