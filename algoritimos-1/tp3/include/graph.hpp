#ifndef TP3_COLORED_GRAPH_HPP
#define TP3_COLORED_GRAPH_HPP

#include <vector>

// data structure to represent a vertex
// reduced by a sudoku cell
struct Node{
	int color;
	std::vector<Node*> neighbors; //adjacent list
};

// Implement a backtrackin solution of colored graph problem
class Graph{
private:
	// list of vertexes
	std::vector<Node*> mNodes;

	//constant to represents a unexistent color
	static const int NONE_COLOR = 0;

	// colors are integer numbers from 1 to mQtt_colors;
	int mQtt_colors;

	// check if a color coul be attributed in a vertex
	bool color_alowed(int node_index, int color);
	
	// recursive method
	// implement the backtrackin solution to color a graph with @mQtt_colors colors
	bool backtracking_color(int node_index);

public:
	// constructor
	Graph(int qtt_colors);

	// Alloc memory and add a new vertex in end of @mNodes
	void add_vertex(int color);

	// create an edge between two vertex
	void add_edge(int index_from, int index_to);
	
	// prepare the data and calls backtrackin solution
	bool color();

	// return the @Node.color attribute of a specific vertex
	int get_vertex_color(int node_index);

	// clear allocated memory
	~Graph();
};
#endif