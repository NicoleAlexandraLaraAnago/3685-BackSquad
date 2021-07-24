#pragma once
#ifndef TREE_H
#define TREE_H


#include "Tree_Node.h"
class Arbol
{
public:
    Arbol();
    void set_root(Tree_Node* _root);
    Tree_Node* get_root();
    
protected:
    Tree_Node* _root;

};

#endif

