#pragma once
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "Arbol.h"
#include"Pila_Tree.h"

using namespace std;

class ArbolBinario :public Arbol {
public:
    ArbolBinario() : Arbol() {};
    void _add(string);
    void imprimirInorden(Tree_Node*);
    void imprimirPreorden(Tree_Node*);
    
};

#endif

