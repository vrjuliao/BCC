#ifndef TP3_SUDOKU_HPP
#define TP3_SUDOKU_HPP

#include <vector>
#include "graph.hpp"


// implements the sudoku matrix
// reduces sudoku problem to color graph problem
class Sudoku {
private:
	// matrix\map of elements in sudoku
	std::vector<std::vector<int>> mMap;
	
	// sudoku matrix is squared, N*N
	// mLength represents N, it's the same of number of elements in a column, block or row.
	int mLength;

	// Blocks of sudoku matriz have the atribute columns and rows
	int mRows, mColumns;

	//to implement problem reduction
	Graph *mGraph;

	// reduces sudoku problem to colored graph problem
	// sudoku cells will be vertex graphs
	// edger represents that a cell is in the same block, row or column that other
	// colors will be represented with numbers
	void polinomial_transformation();

public:
	//constructor that initialize the atributes of Sudoku class
	Sudoku(int length, int rows, int columns);
	
	//set a specific value in sudoku matrix, give a row and column atribute
	void set_map_value(int value, int row, int column);

	//get a specific value from sudoku matrix
	int get_map_value(int row, int column);

	//call the colored graph solution
	void solve();
};
#endif
