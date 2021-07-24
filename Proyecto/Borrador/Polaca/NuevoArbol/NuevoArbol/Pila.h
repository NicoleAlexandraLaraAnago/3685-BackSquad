#if !defined(__Pila_h)
#define __Pila_h

#include "Nodo.h"

class Pila {
public:
    Pila();
    //Metodos para agregar
    void push(char);
    //Metodos para eleiminar
    char pop();
    char getFirst();
    //Longitud de pila
    int size();
    //pila vacia
    bool isEmpty();
    char toEmpty();
    //Metodo de impresion
    void print();
private:
    Nodo* next;
};

#endif