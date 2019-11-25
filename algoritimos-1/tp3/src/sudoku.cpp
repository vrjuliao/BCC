#include "sudoku.hpp"
#include <iostream>
Sudoku::Sudoku(int length, int rows, int columns){
	mMap = std::vector<std::vector<int>>(length);
	mLength = length;
	mRows = rows;
	mColumns = columns;
	//initialize all vectors in vector of vectors (mMap)
	for(int i=0; i < length; i++)
		mMap[i] = std::vector<int>(length);
}

void Sudoku::set_map_value(int value, int row, int column){
	mMap[row][column] = value;
}

int Sudoku::get_map_value(int row, int column){
	return mMap[row][column];
}

bool Sudoku::solve(){
	// call the polinomial transformation and solve the problem
	return this->polinomial_transformation();
}

bool Sudoku::polinomial_transformation(){
	mGraph = new Graph(mLength);

	// each cell of sudoku map, will be converted for a graph vertex
	for(int i=0; i<mLength; i++){
		for(int j=0; j<mLength; j++){
			mGraph->add_vertex(mMap[i][j]);
		}
	}

	// adjacent list implementation
	// two cells on the same row or column have and egde between each other
	int current_vertex_index, neighbor_vertex_index;
	for(int i=0; i<mLength; i++){
		for(int j=0; j<mLength; j++){
			current_vertex_index = (i*mLength)+j;
			for(int k=0; k<mLength; k++){
				// k!=j - carrying for no exists recursive edges
				if(k!=j){
					//add vertex for rows
					neighbor_vertex_index = (i*mLength)+k;
					mGraph->add_edge(current_vertex_index, neighbor_vertex_index);
				}
				// k!=i - carrying for no exists recursive edges
				if(k!=i){
					//add vertex for columns
					neighbor_vertex_index = (k*mLength)+j;
					mGraph->add_edge(current_vertex_index, neighbor_vertex_index);
				}
			}
		}
	}

	// adjacent list implementation
	// two cells on the block have and egde between each other
	int initial_column, initial_row;
	int row, column;
	for(int i=0; i<mLength; i++){
		initial_row = i - (i%mRows);
		for(int j=0; j<mLength; j++){
			initial_column = j - (j%mColumns);
			current_vertex_index = (i*mLength)+j;
			for(int r=0; r<mRows; r++){
				row = initial_row+r;
				for(int c=0; c<mColumns; c++){
					column = initial_column+c;
					if(column==j || row == i){
						continue;
					} else {
						neighbor_vertex_index = (row*mLength)+column;
						mGraph->add_edge(current_vertex_index, neighbor_vertex_index);
					}
				}
			}
		}
	}

	//call coloration method from graph
	bool s = mGraph->color();

	//set sudoku matrix with all values of 'colors' after the solution
	int local_row;
	Node *n;
	for (int i = 0; i < mLength; i++){
		local_row = i*mLength;
		for (int j = 0; j < mLength; j++){
			mMap[i][j] = mGraph->get_vertex_color(local_row + j);
		}
	}
	delete mGraph;
	return s;
}