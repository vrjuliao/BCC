#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include "travel_islands.hpp"


int main(int argc, const char *argv[]){
    //getting parameter whether time must be show
    bool show_time = false, show_both = false;
    std::string filename;
    if(argc > 1){
        filename = argv[1];
        if(argc > 2){
            std::string param_time = "-t";
            std::string param_both = "-b";
            show_both = param_both == argv[2];
            show_time = param_time == argv[2];
        }
    } else {
        std::cout << "Error: file name is not valid" << std::endl;
        return 0;
    }

    //file manipulators
    std::string line;
    std::ifstream myfile(filename);
    
    //throw error if filename is incorrect
    if(!myfile.is_open()){
        std::cout << "Error: file name is not valid" << std::endl;
        return 0;
    }

    //time manipulators
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    //instance of a timer that compute in nanoseconds
    std::chrono::duration<double, std::nano> elapsed_time;

    int islands_qtt, max_cost, score, price;
    myfile >> max_cost >> islands_qtt;
    TravelIslands travel = TravelIslands(islands_qtt);
	for(int i=0; i < islands_qtt; i++){
        myfile >> price >> score;
        travel.add_island(i, price, score);
	}
    auto p = travel.get_better_by_greedy(max_cost);
    std::cout << p.first << ' ' << p.second << std::endl;

    //counting time of execution
    unsigned int execution_time;
    t1 = std::chrono::high_resolution_clock::now();
    
    t2 = std::chrono::high_resolution_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    execution_time = static_cast<unsigned int>(elapsed_time.count());
}