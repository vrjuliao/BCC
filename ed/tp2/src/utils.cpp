#include "utils.hpp"
#include <iostream>
namespace Utils {
	//template <class T>
	void create_aleatory_vector(int vector[], int length){
		auto now = std::chrono::system_clock::now();
    	auto now_ms = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    	auto value = now_ms.time_since_epoch();
    	long duration = value.count();

		//std::chrono::duration<double, std::micro> elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t1+t1);
		//double time_now = elapsed_time.count();
		// std::srand(std::time(NULL));
		std::srand(duration);
		std::cout << "Gen Elements" << std::endl;
		for(int index = 0; index < length; index++){
			vector[index] = (std::rand()%length) + 1;
			std::cout << vector[index] << " ";
		}
		std::cout << std::endl;
	}

	//template <class T>
	void create_increasing_vector(int vector[], int length){
		for(int index = 0; index < length; index++) {
			vector[index] = index+1;
		}
	}

	//template <class T>
	void create_decreasing_vector(int vector[], int length){
		for(int index = 0; index < length; index++){
			vector[index] = length-index;
		}
	}
}