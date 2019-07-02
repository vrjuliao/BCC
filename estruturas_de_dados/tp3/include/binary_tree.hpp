#ifndef BINARY_TREE_TP3
#define BINARY_TREE_TP3

#include <string>
#include <iostream>
#include"pair.hpp"

typedef struct Node {
	Pair reg;
	struct Node *left;
	struct Node *right;
} Node;

/*typedef {
	char reg;
	Node *left, *right;
} Node;*/

class BinaryTree {
private:
	static const char SCORE = '-';
	static const char DOT = '.';
	static const char EMPTY_CHAR = NULL;
	Node *root;
	char _find(std::string key, struct Node *node, int string_position);
	void _add(const Pair &p, struct Node *sub_root, int string_position);
	Node *create_empty_node();
	void delete_node_pos_order(Node *node);
public:
	BinaryTree();
	char find(std::string key);
	void add(const Pair &p);
	void print();
	~BinaryTree();
};

#endif