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
	char _find(std::string key, Node *node, int string_position);
	void _add(const Pair &p, Node *sub_root, int string_position);
	void create_empty_node(Node *node);
	void delete_node_pos_order(Node *node);
	void _print(Node *node);
public:
	BinaryTree();
	char find(std::string key);
	void add(const Pair &p);
	void print();
	~BinaryTree();
};

#endif