#include "Arbol.h"

Arbol::Arbol() {
	this->_root = NULL;
}


void Arbol::set_root(Tree_Node* _root)
{
	this->_root = _root;
}

Tree_Node* Arbol::get_root()
{
	return this->_root;
}
