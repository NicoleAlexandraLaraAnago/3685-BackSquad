#include "Pila_Tree.h"

Pila_Tree::Pila_Tree()
{
    this->next = NULL;
}

void Pila_Tree::push(Tree_Node* d) {
    if (this->isEmpty()) {
        this->next = new NodoArbol(d, NULL);
    }
    else {
        NodoArbol* aux = new NodoArbol(d, this->next);
        this->next = aux;
    }
}

bool Pila_Tree::isEmpty() {
    return (this->next == NULL) ? true : false;
}

Tree_Node* Pila_Tree::toEmpty() {
    NodoArbol* aux = new NodoArbol();
    while (!this->isEmpty()) {
        aux = this->next;
        this->next = this->next->getNext();
        return aux->getData();
    }
}

Tree_Node* Pila_Tree::pop() {
    if (!isEmpty()) {
        NodoArbol* aux = this->next->getNext();
        Tree_Node* d = this->next->getData();
        delete this->next;
        this->next = aux;
        return  d;
    }
    else {
        cout << "Pila vacia" << endl;
        return 0;
    }
}

void Pila_Tree::clean_pila()
{
    while (!isEmpty()) {
        pop();
    }
}

Tree_Node* Pila_Tree::getFirst() {
    if (!isEmpty()) {
        Tree_Node* d = this->next->getData();
        return  d;
    }
    else {
        cout << "Pila vacia" << endl;
        return 0;
    }
}

int Pila_Tree::size() {
    int contador = 0;
    NodoArbol* aux = new NodoArbol();
    aux = this->next;
    while (aux != NULL) {
        contador++;
        aux = aux->getNext();
    }
    return contador;
}