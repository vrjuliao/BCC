#ifndef TP3_COLORED_GRAPH_HPP
#define TP3_COLORED_GRAPH_HPP

#include <vector>

struct Node{
	int color;
	std::vector<Node*> neighbors;
};

class Graph{
private:
	std::vector<Node*> mNodes;
	static const int NONE_COLOR = 0;

	// colors are integer numbers from 1 to mQtt_colors;
	int mQtt_colors;

	bool color_alowed(int node_index, int color);
	bool backtracking_color(int node_index);

public:
	Graph(int qtt_colors);
	void add_vertex(int color);
	void add_edge(int index_from, int index_to);
	bool color();
	int get_vertex_color(int node_index);
	~Graph();
};
#endif