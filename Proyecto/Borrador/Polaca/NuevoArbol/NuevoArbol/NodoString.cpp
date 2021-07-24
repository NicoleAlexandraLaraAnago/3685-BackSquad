#include "NodoString.h"


NodoString::NodoString() { 
	this->next = NULL; 
}


NodoString::NodoString(string d, NodoString* n) {
	this->data = d;
	this->next = n;
}


void NodoString::setData(string d) {
	this->data = d; 
}
void NodoString::setNext(NodoString* n) {
	this->next = n; 
}
void NodoString::setPrevious(NodoString* p) {
	this->previous = p; 
}

string NodoString::getData() {
	return this->data; 
}
NodoString* NodoString::getNext() {
	return this->next; 
}
NodoString* NodoString::getPrevious() {
	return this->previous; 
}