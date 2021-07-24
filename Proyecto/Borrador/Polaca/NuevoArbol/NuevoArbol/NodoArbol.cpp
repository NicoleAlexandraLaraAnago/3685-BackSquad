#include "NodoArbol.h"

NodoArbol::NodoArbol() { 
	this->next = NULL; 
}

NodoArbol::NodoArbol(Tree_Node* d, NodoArbol* n) {
	this->data = d;
	this->next = n;
}


void NodoArbol::setData(Tree_Node* d) { 
	this->data = d; 
}
void NodoArbol::setNext(NodoArbol* n) { 
	this->next = n; 
}
void NodoArbol::setPrevious(NodoArbol* p) { 
	this->previous = p; 
}

Tree_Node* NodoArbol::getData() { 
	return this->data; 
}
NodoArbol* NodoArbol::getNext() { 
	return this->next; 
}
NodoArbol* NodoArbol::getPrevious() { 
	return this->previous; 
}