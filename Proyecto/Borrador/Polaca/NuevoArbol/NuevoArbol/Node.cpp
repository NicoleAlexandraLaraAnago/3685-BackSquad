#include"Nodo.h"

Nodo::Nodo() { this->next = NULL; }


Nodo::Nodo(char d, Nodo* n) {
	this->data = d;
	this->next = n;
}

void Nodo::setData(char d) { 
	this->data = d; 
}

void Nodo::setNext(Nodo* n) { 
	this->next = n; 
}
void Nodo::setPrevious(Nodo* p) { 
	this->previous = p; 
}

char Nodo::getData() { 
	return this->data; 
}
Nodo* Nodo::getNext() { 
	return this->next; 
}
Nodo* Nodo::getPrevious() { 
	return this->previous; 
}
