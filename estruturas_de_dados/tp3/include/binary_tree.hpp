#ifndef BINARY_TREE_TP3
#define BINARY_TREE_TP3

#include <string>
#include <iostream>
#include <exception>
#include "pair.hpp"

struct Node {
	Pair *reg;
	Node *left;
	Node *right;
};

class BinaryTree {
private:
	static const char SCORE = '-';
	static const char DOT = '.';
	static const char EMPTY_CHAR = '\0';
	Node *root;
	//find a key value at a avalailable node
	char _find(std::string key, Node *node, int string_position);
	// add values at available nodes
	void _add(const Pair &p, Node *sub_root, int string_position);
	//cleaning tree
	void delete_node_pos_order(Node *node);
	//call available nodes to print char values
	void _print(Node *node);
public:
	BinaryTree();
	//find a morse translation
	char find(std::string key);
	//add a new translation configuration
	void add(const Pair &p);
	//print tree in pre-order 
	void print();
	~BinaryTree();
};

#endif