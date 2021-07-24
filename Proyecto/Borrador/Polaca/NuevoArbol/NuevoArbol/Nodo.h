#if !defined(__Node_h)

#include <iostream>

using namespace std;

class Nodo {
public:
	Nodo();
	Nodo(char d, Nodo* n);


	void setData(char d);
	void setNext(Nodo* n);
	void setPrevious(Nodo* p);

	char getData();
	Nodo* getNext();
	Nodo* getPrevious();
private:
	char data;
	Nodo* next;
	Nodo* previous;
};
#endif