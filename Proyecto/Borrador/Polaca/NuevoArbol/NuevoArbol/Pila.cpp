#include "Pila.h"


Pila::Pila()
{
    this->next = NULL;
}

void Pila::push(char d) {
    if (this->isEmpty()) {
        this->next = new Nodo(d, NULL);
    }
    else {
        Nodo* aux = new Nodo(d, this->next);
        this->next = aux;
    }
}

bool Pila::isEmpty() {
    return (this->next == NULL) ? true : false;
}

void Pila::print() {
    Nodo* aux = new Nodo();
    aux = this->next;
    while (aux != NULL) {
        cout << aux->getData() << "  ";
        aux = aux->getNext();
    }
}

char Pila::toEmpty() {
    Nodo* aux = new Nodo();
    while (!this->isEmpty()) {
        aux = this->next;
        this->next = this->next->getNext();
        return aux->getData();
    }
}

char Pila::pop() {
    if (!isEmpty()) {
        Nodo* aux = this->next->getNext();
        char d = this->next->getData();
        delete this->next;
        this->next = aux;
        return  d;
    }
    else {
        cout << "Pila vacia" << endl;
        return 0;
    }
}

char Pila::getFirst() {
    if (!isEmpty()) {
        char d = this->next->getData();
        return  d;
    }
    else {
        cout << "Pila vacia" << endl;
        return 0;
    }
}

int Pila::size() {
    int contador = 0;
    Nodo* aux = new Nodo();
    aux = this->next;
    while (aux != NULL) {
        contador++;
        aux = aux->getNext();
    }
    return contador;
}

