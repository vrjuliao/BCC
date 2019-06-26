#ifndef BINARY_TREE_TP3
#define BINARY_TREE_TP3

#include <string>
#include <iostream>
#include"pair.hpp"

typedef {
	Pair reg;
	Pair *left, *right;
} Node;

class BinaryTree {
private:
	Node *root;
	char find_available_nodes(Node node);
public:
	BinaryTree();
	char find(std::string key);
	void add(Pair p);
	void print();
	~BinaryTree();
}

#endif