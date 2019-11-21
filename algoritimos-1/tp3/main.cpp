#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>
#include "sudoku.hpp"

//print data according received parameters
void show_response(bool show_both, bool show_time, std::pair<int,int> p, unsigned int time){
    if(show_both || !(show_both || show_time)){
        std::cout << p.first << ' ' << p.second;
    }
    if(show_time || show_both){
        if(show_both)
            std::cout << " - time in nanoseconds: ";
        std::cout << time;   
    }
    std::cout << std::endl;
}

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

    // a sudoku block is composed by i_rows an j_cols
    int sudoku_length, i_rows, j_cols;
    myfile >> sudoku_length >> j_cols >> i_rows;
    Sudoku sudoku = Sudoku(sudoku_length, i_rows, j_cols);
    // std::vector<std::vector<int>> sudoku_table = std::vector<std::vector<int>>(sudoku_length);
    int io_read;
    for(int i=0; i<sudoku_length; i++){
    	// sudoku_table[i] = std::vector<int>(sudoku_length);
    	for(int j=0; j<sudoku_length; j++){
    		// myfile >> sudoku_table[i][j];
    		myfile >> io_read;
    		sudoku.set_map_value(io_read, i, j);
    	}
    }

    sudoku.solve();
    for(int i=0; i<sudoku_length; i++){
    	// std::cout << sudoku_table[i][0];
    	std::cout << sudoku.get_map_value(i,0);
    	for(int j=1; j<sudoku_length; j++){
    		std::cout << ' ' << sudoku.get_map_value(i,j);
    		// std::cout << ' ' <<sudoku_table[i][j]; 
    	}
    	std::cout << std::endl;
    }

    return 1;
}