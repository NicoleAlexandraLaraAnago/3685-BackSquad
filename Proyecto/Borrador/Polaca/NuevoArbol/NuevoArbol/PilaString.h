#pragma once
#include <iostream>
#include "NodoString.h"
#include <string>
using namespace std;
class PilaString
{
public:
    PilaString();
    //Metodos para agregar
    void push(string);
    //Metodos para eleiminar
    string pop();
    string getFirst();
    //Lista vacia
    bool isEmpty();
    //Metodo de impresion
    void print();
private:
    NodoString* next;
};


