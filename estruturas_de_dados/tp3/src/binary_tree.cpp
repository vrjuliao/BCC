#include"binary_tree.hpp"

Node* BinaryTree::create_empty_node(){
	Node *node = new Node;
	node->reg.set_key("");
	node->reg.set_data('');
	node->left = nullptr;
	node->right = nullptr;
}

BinaryTree::BinaryTree(){
	root = create_empty_node();
}

void BinaryTree::add(const Pair &p){
	if(p.get_key().length()){
		if(p.get_key()[0] == DOT){
			this._add(p, node->left, 1);
		} else {
			this._add(node->right, 1);
		} 
	}
}

void BinaryTree::_add(const Pair &p, Node *sub_root, int string_position){
	if(sub_root == nullptr){
		sub_root = create_empty_node();
	}
	if(string_position == p.get_key().length()){
		sub_root.set_data(p.get_data());
		sub_root.set_key(p.get_key())
	} else {
		if(p.get_key()[string_position] == SCORE){
			string_position++;
			_add(p, sub_root->right, string_position);
		} else {
			string_position++;
			_add(p, sub_root->left, string_position);
		}
	}
}

char BinaryTree::find(std::string key){
	if(key.length()){
		if(key()[0] == DOT){
			return _find(key, root->left, 1);
		} else {
			return _find(key, root->right, 1);
		}
	}
	return '';
}

char BinaryTree::_find(std::string key, Node *node, int string_position){
	if(sub_root == nullptr){
		return '';
	}

	if(string_position == key().length()){
		return node->reg.get_data();
	} else {
		if(key[string_position] == SCORE){
			string_position++;
			_find(key, sub_root->right, string_position);
		} else {
			string_position++;
			_find(key, sub_root->left, string_position);
		}
	}
}
