#include "binary_tree.hpp"

BinaryTree::BinaryTree(){
	root = new Node();
	root->reg = new Pair("", '\0');
	root->left = nullptr;
	root->right = nullptr;
}

void BinaryTree::add(const Pair &p){
	if(p.get_key().length()){
		if(p.get_key()[0] == DOT){
			if(root->left == nullptr){
				root->left = new Node();
				root->left->reg = new Pair();
				root->left->left = nullptr;
				root->left->right = nullptr;
			}
			this->_add(p, root->left, 1);
		} else if(p.get_key()[0] == SCORE){
			if(root->right == nullptr){
				root->right = new Node();
				root->right->reg = new Pair();
				root->right->left = nullptr;
				root->right->right = nullptr;
			}
			this->_add(p, root->right, 1);
		} else {
			throw std::runtime_error("Error: character not accepted");
;		}
	}
}

void BinaryTree::_add(const Pair &p, Node *sub_root, int string_position){
	if(string_position == p.get_key().length()){
		sub_root->reg->set_data(p.get_data());
		sub_root->reg->set_key(p.get_key());
	} else {
		if(p.get_key()[string_position] == SCORE){
			if(sub_root->right == nullptr){
				sub_root->right = new Node();
				sub_root->right->reg = new Pair();
				sub_root->right->left = nullptr;
				sub_root->right->right = nullptr;
			}
			string_position++;
			_add(p, sub_root->right, string_position);
		} else if (p.get_key()[string_position] == DOT){
			if(sub_root->left == nullptr){
				sub_root->left = new Node();
				sub_root->left->reg = new Pair();
				sub_root->left->left = nullptr;
				sub_root->left->right = nullptr;
			}
			string_position++;
			_add(p, sub_root->left, string_position);
		} else {
			throw std::runtime_error("Error: character not accepted"); 
		}
	}
}

char BinaryTree::find(std::string key){
	if(key.length()){
		if(key[0] == DOT){
			return _find(key, root->left, 1);
		} else if(key[0] == SCORE){
			return _find(key, root->right, 1);
		} else {
			throw std::runtime_error("Error: character not accepted");
		}
	}
	return EMPTY_CHAR;
}

char BinaryTree::_find(std::string key, Node *node, int string_position){
	if(node == nullptr){
		return EMPTY_CHAR;
	}

	if(string_position == key.length()){
		return node->reg->get_data();
	} else {
		if(key[string_position] == SCORE){
			string_position++;
			return _find(key, node->right, string_position);
		} else if(key[string_position] == DOT) {
			string_position++;
			return _find(key, node->left, string_position);
		} else {
			throw std::runtime_error("Error: character not accepted");
		}
	}
}

void BinaryTree::print(){
	_print(root->left);
	_print(root->right);
}

void BinaryTree::_print(Node *node){
	if(node){
		if(node->reg->get_data() != '\0')
			std::cout<< node->reg->get_data() << " " << node->reg->get_key() << std::endl;
		_print(node->left);
		_print(node->right);
	}
}

void BinaryTree::delete_node_pos_order(Node *node){
	if(node){
		delete_node_pos_order(node->left);
		delete_node_pos_order(node->right);
		delete node->reg;
		delete node;
	}
}

BinaryTree::~BinaryTree(){
	delete_node_pos_order(root->left);
	delete_node_pos_order(root->right);
	delete root->reg;
	delete root;
}