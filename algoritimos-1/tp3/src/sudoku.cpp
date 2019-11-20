#include "sudoku.hpp"

Sudoku::Sudoku(int length, int rows, int columns){
	// mGraph = new Graph(length);
	mMap = std::vector<std::vector<int>>(length);
	mLength = length;
	mRows = rows;
	mColumns = columns;
	for(int i=0; i < length; i++)
		mMap[i] = std::vector<int>(length);
}

void Sudoku::set_map_value(int value, int row, int column){
	mMap[row][column] = value;
}

int Sudoku::get_map_value(int row, int column){
	return mMap[row][column];
}

void Sudoku::solve(){
	this->polinomial_transformation();
	mGraph->color();
}

void Sudoku::polinomial_transformation(){
	mGraph = new Graph(mLength);

	//cada célula do sudoku será um vertice do grafo
	for(int i=0; i<mLength; i++){
		for(int j=0; j<mLength; j++){
			mGraph->add_vertex(mMap[i][j]);
		}
	}
	
	//duas células na mesma linha representam uma aresta entre dois vértices
	//duas células na mesma coluna representam uma aresta entre dois vértices
	int current_vertex_index, neighbor_vertex_index;
	for(int i=0; i<mLength; i++){
		for(int j=0; j<mLength; j++){
			current_vertex_index = (i*mLength)+j;
			for(int k=0; k<mLength; k++){
				if(k!=j){
					neighbor_vertex_index = (i*mLength)+k;
					mGraph->add_edge(current_vertex_index, neighbor_vertex_index);
				}
				if(k!=i){
					neighbor_vertex_index = (k*mLength)+j;
					mGraph->add_edge(current_vertex_index, neighbor_vertex_index);
				}
			}
		}
	}

	//duas células no mesmo bloco representam uma aresta entre dois vértices
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
}