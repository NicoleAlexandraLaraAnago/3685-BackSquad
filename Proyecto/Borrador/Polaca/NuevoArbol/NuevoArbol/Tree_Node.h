#pragma once
#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>

using namespace std;


class Tree_Node
{
public:
    Tree_Node();
    Tree_Node(string _data, Tree_Node* _left, Tree_Node* _right);
    void set_data(string _data);
    void set_left_node(Tree_Node* _left);
    void set_right_node(Tree_Node* _right);
    string get_data();
    Tree_Node* get_right_node();
    Tree_Node* get_left_node();


private:
    Tree_Node* _left;
    Tree_Node* _right;
    string _data;
};

#endif


