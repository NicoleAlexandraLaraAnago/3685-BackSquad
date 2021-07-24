#pragma once
#include <iostream>
#include"Tree_Node.h"

using namespace std;

class NodoArbol
{
public:
	NodoArbol();
	NodoArbol(Tree_Node* d, NodoArbol* n);

	void setData(Tree_Node* d);
	void setNext(NodoArbol* n);
	void setPrevious(NodoArbol* p);

	Tree_Node* getData();
	NodoArbol* getNext();
	NodoArbol* getPrevious();
private:
	Tree_Node* data;
	NodoArbol* next;
	NodoArbol* previous;
};

