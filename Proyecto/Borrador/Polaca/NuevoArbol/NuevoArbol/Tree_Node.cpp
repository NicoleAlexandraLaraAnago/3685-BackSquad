#include <iostream>
#include <sstream>

#include "Tree_Node.h"

using namespace std;


Tree_Node::Tree_Node() {
	this->_left = NULL;
	this->_right = NULL;
}

Tree_Node::Tree_Node(string _data, Tree_Node* _left, Tree_Node* _right) {
	this->_left = _left;
	this->_right = _right;
	this->_data = _data;
}

void Tree_Node::set_data(string _data) {
	this->_data = _data;
}

void Tree_Node::set_left_node(Tree_Node* _left) {
	this->_left = _left;
}

void Tree_Node::set_right_node(Tree_Node* _right) {
	this->_right = _right;
}

string Tree_Node ::get_data() {
	return this->_data;
}

Tree_Node* Tree_Node::get_right_node() {
	return this->_right;

}

Tree_Node* Tree_Node::get_left_node() {
	return this->_left;
}

