#include "graph.hpp"
	
bool Graph::color_alowed(int node_index, int color){
	Node *n = mNodes[node_index];
	int size = n->neighbors.size();
	for(int i=0; i<size; i++){
		if(n->neighbors[i]->color == color) return false;
	}
	return true;
}

bool Graph::backtracking_color(int node_index){
	if(node_index == mNodes.size()) return true;
	Node *n = mNodes[node_index];

	if(n->color != NONE_COLOR) {
		return backtracking_color(node_index+1);
	}

	for (int color = 1; color <= mQtt_colors; color++){
		if(color_alowed(node_index, color)){
			n->color = color;
			if(backtracking_color(node_index+1) == true) return true;
			n->color = NONE_COLOR;
		}
	}
	return false;
}

int Graph::get_vertex_color(int node_index){
	return mNodes[node_index]->color;
}

Graph::Graph(int qtt_colors){
	mNodes = std::vector<Node*>();
	mQtt_colors = qtt_colors;
}

void Graph::add_vertex(int color){
	Node *n = new Node();
	n->color = color;
	n->neighbors = std::vector<Node*>();
	mNodes.push_back(n);
}

void Graph::add_edge(int index_from, int index_to){
	Node *n = mNodes[index_from];
	Node *n_to = mNodes[index_to];
	n->neighbors.push_back(n_to);
}

bool Graph::color(){
	return backtracking_color(0);
}

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