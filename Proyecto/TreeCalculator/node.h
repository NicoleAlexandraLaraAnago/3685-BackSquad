/**      
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computacion
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: Convertir notacion infija a postfija, prefija y funcional
 * 
 * @date 05/07/2021
 * @author Diego Jimenez
 */

#pragma once

template <typename A>
class Node{
    private:
        A dat;
        Node<A>* next = nullptr;
        Node<A>* previous = nullptr;
        // Node<A>* next;
        // Node<A>* previous;
    public:
        Node();
        Node(A dat);
        A getDat();
        void setDat(A dat);
        Node<A>* getNext();
        void setNext(Node<A>* next);
        Node<A>* getPrevious();
        void setPrevious(Node<A>* previous);
};

template <typename A>
Node<A>::Node(){
}

template <typename A>
Node<A>::Node(A dat){
    this->dat = dat;
    // this->next = nullptr;
    // this->previous= nullptr;
}

template <typename A>
A Node<A>::getDat(){
    return this->dat;
}

template <typename A>
void Node<A>::setDat(A dat){
    this->dat = dat;
}

template <typename A>
Node<A>* Node<A>::getNext(){
    return this->next;
}

template <typename A>
void Node<A>::setNext(Node<A>* next){
    this->next = next;
}

template <typename A>
Node<A>* Node<A>::getPrevious(){
    return this->previous;
}

template <typename A>
void Node<A>::setPrevious(Node<A>* previous){
    this->previous = previous;
}