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
#include "node.h"
#include <functional>

template <typename A>
class Stack{
    private:
        Node<A>* cursor = nullptr;
        int size = 0;
    public:
        Stack() = default;
        void push_(A dat);
        void pop();
        Node<A>* getLast();
        Node<A>* getCursor();
        Node<A>* getAt(int index);
        A peak();
        int getSize();
        bool isEmpty();
        void forEach(std::function<void(Node<A>*, int)> callback);
        void forEach(std::function<void(Node<A>*)> callback);
        void forEach(std::function<void(A)> callback);
        void forEach(std::function<void(A,int)> callback);

        void forEachBack(std::function<void(Node<A>*, int)> callback);

        Node<A>* find(std::function<bool(Node<A>*, int)> callback);
        Node<A>* find(std::function<bool(Node<A>*)> callback);
        Node<A>* find(std::function<bool(A)> callback);
        Node<A>* find(std::function<bool(A, int)> callback);
};

template <typename A>
bool Stack<A>::isEmpty(){
    return (cursor == nullptr);
}

template <typename A>
int Stack<A>::getSize(){
    return this->size;
}

template <typename A>
Node<A>* Stack<A>::getLast(){
    Node<A>* tmp = cursor;
    while (tmp->getNext() != nullptr)
    {
        tmp = tmp->getNext();
    }
    return tmp;
}

template <typename A>
Node<A>* Stack<A>::getCursor(){
    return cursor;
}

template<typename A>
Node<A>* Stack<A>::getAt(int index){
    Node<A>* tmp = cursor;
    int i = 0;
    while (tmp->getNext() != nullptr && index != i)
    {
        tmp = tmp->getNext();
        i++;
    }
    return tmp;
}

template <typename A>
void Stack<A>::push_(A dat){
    size ++;
    Node<A>* recent = new Node<A>(dat);
    if(isEmpty()){
        this->cursor = recent;
        return;
    }else{
        Node<A>* last = getLast();
        recent->setPrevious(last);
        last->setNext(recent);
    }
}

template <typename A>
void Stack<A>::pop(){
    if(getSize() ==1){
        Node<A>* aux = cursor;
        cursor =nullptr;
    }else{
        Node<A>* last = getLast();
        Node<A>* pseudoLast = getAt(size-2);
        pseudoLast->setNext(nullptr);
        delete last;
    }
    size --;
}

template <typename A>
A Stack<A>::peak(){
    Node<A>* last = getLast();
    return last->getDat();
}

template <typename A>
void Stack<A>::forEach(std::function<void(Node<A>*, int)> callback) {
    Node<A>* tmp = cursor;
    int index = 0;
    while (tmp != nullptr)
    {
        callback(tmp,index);
        tmp = tmp->getNext();
        index++;
    }
}

template <typename A>
void Stack<A>::forEachBack(std::function<void(Node<A>*, int)> callback) {
    Node<A>* tmp = getLast();
    int index = size;
    while (tmp != nullptr)
    {
        callback(tmp,index);
        tmp = tmp->getPrevious();
        index--;
    }
}

template <typename A>
void Stack<A>::forEach(std::function<void(Node<A>*)> callback){
    forEach([&](Node<A>* tmp, int index){
        callback(tmp);
        //callback(tmp->getDat());
    });
}

template <typename A>
void Stack<A>::forEach(std::function<void(A)> callback){
    forEach([&](Node<A>* tmp, int index){
        callback(tmp->getDat());
    });
}
        
template <typename A>        
void Stack<A>::forEach(std::function<void(A,int)> callback){
    forEach([&](Node<A>* tmp, int index){
        callback(tmp->getDat(), index);
    });
}

template <typename A>
Node<A>* Stack<A>::find(std::function<bool(Node<A>*, int)> callback){
    Node<A>* node = cursor;
    int index = 0;

    while(node != nullptr){
        if (callback(node, index++)){
            return node;
        }
        node = node->getNext();
    }
    return nullptr;
}
template <typename A>        
Node<A>* Stack<A>::find(std::function<bool(Node<A>*)> callback){
    return find([&] (Node<A>* node, int index) -> bool{
        return callback(node);
    });
}

template <typename A>        
Node<A>* Stack<A>::find(std::function<bool(A)> callback){
    return find([&] (Node<A>* node, int index) -> bool {
        return callback(node->getDat());
    });
}

template <typename A>        
Node<A>* Stack<A>::find(std::function<bool(A, int)> callback){
    return find([&](Node<A>* node, int index) -> bool{
        return callback(node->getDat(), index);
    });
}