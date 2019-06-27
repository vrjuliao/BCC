#ifndef BINARY_TREE_TP3
#define BINARY_TREE_TP3

#include <string>
#include <iostream>
#include"pair.hpp"

typedef {
	Pair reg;
	Node *left, *right;
} Node;

/*typedef {
	char reg;
	Node *left, *right;
} Node;*/

class BinaryTree {
private:
	static const char SCORE = '-';
	static const char DOT = '.';
	Node *root;
	char _find(std::string key, Node *node, int string_position);
	void _add(const Pair &p, Node *sub_root, int string_position);
	Node *create_empty_node();
public:
	BinaryTree();
	char find(std::string key);
	void add(Pair p);
	void print();
	~BinaryTree();
};

#endif