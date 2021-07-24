#pragma once
#include <iostream>
using namespace std;
class NodoString
{
public:
	NodoString();
	NodoString(string d, NodoString* n);

	void setData(string d);
	void setNext(NodoString* n);
	void setPrevious(NodoString* p);

	string getData();
	NodoString* getNext();
	NodoString* getPrevious();
private:
	string data;
	NodoString* next;
	NodoString* previous;
};

