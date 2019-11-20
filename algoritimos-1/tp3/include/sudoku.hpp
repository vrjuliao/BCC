#ifndef TP3_SUDOKU_HPP
#define TP3_SUDOKU_HPP

#include <vector>
#include "graph.hpp"

class Sudoku {
private:
	std::vector<std::vector<int>> mMap;
	int mLength, mRows, mColumns;

	//to implement problem reduction
	Graph *mGraph;

	// reduces sudoku problem to colored graph problem
	void polinomial_transformation();

public:
	Sudoku(int length, int rows, int columns);
	void set_map_value(int value, int row, int column);
	int get_map_value(int row, int column);
	void solve();
};
#endif