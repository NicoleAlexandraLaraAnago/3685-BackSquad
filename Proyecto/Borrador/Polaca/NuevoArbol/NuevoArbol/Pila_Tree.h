#pragma once
#include"NodoArbol.h"
class Pila_Tree
{
public:
    Pila_Tree();
    //Metodos para agregar
    void push(Tree_Node*);
    //Metodos para eleiminar
    Tree_Node* pop();
    void clean_pila();
    Tree_Node* getFirst();
    //Longitud de lista
    int size();
    //Lista vacia
    bool isEmpty();
    Tree_Node* toEmpty();
    NodoArbol* next;
};

