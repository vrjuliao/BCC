#include "graph.hpp"

// verify if a vertice does not have a neighbor (adjacent vertice) with a specific color
bool Graph::color_alowed(int node_index, int color){
	Node *n = mNodes[node_index];
	int size = n->neighbors.size();
	for(int i=0; i<size; i++){
		if(n->neighbors[i]->color == color) return false;
	}
	return true;
}

// solve m-graph coloration by backtracking techinique
bool Graph::backtracking_color(int node_index){
	if(node_index == mNodes.size()) return true;
	Node *n = mNodes[node_index];

	// recursive call
	if(n->color != NONE_COLOR) {
		return backtracking_color(node_index+1);
	}

	// for all colors check if there is a color allowed to a vertex
	// set the vertex color
	for (int color = 1; color <= mQtt_colors; color++){
		if(color_alowed(node_index, color)){
			n->color = color;
			if(backtracking_color(node_index+1) == true) return true;
			n->color = NONE_COLOR;
		}
	}
	return false;
}

// return the color of a specific vertex
int Graph::get_vertex_color(int node_index){
	return mNodes[node_index]->color;
}

// contructor
Graph::Graph(int qtt_colors){
	mNodes = std::vector<Node*>();
	mQtt_colors = qtt_colors;
}

// alloc memory and create a new vertex on graph
void Graph::add_vertex(int color){
	Node *n = new Node();
	n->color = color;
	n->neighbors = std::vector<Node*>();
	mNodes.push_back(n);
}

// create a new edge on graph using the @Node.neighbors adjacent list
void Graph::add_edge(int index_from, int index_to){
	Node *n = mNodes[index_from];
	Node *n_to = mNodes[index_to];
	n->neighbors.push_back(n_to);
}

// call backtracking color method beginning from the first element mNodes[0] of graph
bool Graph::color(){
	return backtracking_color(0);
}

// clear memory
Graph::~Graph(){
	int size = mNodes.size();
	Node *n;
	for(int i=0; i<size; i++){
		n = mNodes[i];
		n->neighbors.clear();
		delete n;
	}
	mNodes.clear();
}