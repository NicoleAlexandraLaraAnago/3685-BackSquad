/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*Docente: Fernando Solis
*AUTORES : Diejo Jiminez
*Dalton Arevalo
*Lizzette Zapata
*Stalin Rivera 
*Nicol Lara
*ENUNCIADO: CREACION DE UN PROGRAMA QUE SIMULE UNA CALCULADORA POLACA INVERSA
*FECHA DE CREACION : 15 DE JULIO DE 2021
*FECHA DE MODIFICACION:  06 DE JULIO DE 2021
*/

#pragma once 
#include "node.h"
#include <functional>

template <typename A>
class Tree{
    private:
    /**
     * @brief Muestra ek cursor el desplazamiento y muestra nulo
     * 
     */
        Node<A>* cursor = nullptr;
        /**
         * @brief 
         * 
         */
        int size = 0;
    public:
    /**
     * @brief Construct a new Tree object
     * 
     */
        Tree() = default;
        /**
         * @brief insert Sirve para insertar
         * 
         * @param dat 
         */
        void insert(A dat);
        /**
         * @brief 
         * 
         */
        void eraser();
        /**
         * @brief Get the Last object
         * 
         * @return Node<A>* 
         */
        Node<A>* getLast();
        /**
         * @brief Get the Root object
         * 
         * @return Node<A>* 
         */
        Node<A>* getRoot();
        /**
         * @brief Get the At object
         * 
         * @param index 
         * @return Node<A>* 
         */
        Node<A>* getAt(int index);
        /**
         * @brief search Busca el metodo de buscar 
         * 
         * @return A 
         */
        A search();
        /**
         * @brief Get the Size object
         * 
         * @return int 
         */
        int getSize();
        /**
         * @brief isEmpty Busca el metodo de emparejar
         * 
         * @return true 
         * @return false 
         */
        bool isEmpty();
        /**
         * @brief forEach Indica el acceso de los elementos 
         * 
         * @param callback 
         */
        void forEach(std::function<void(Node<A>*, int)> callback);
        /**
         * @brief forEach Indica el acceso de los elemento
         * 
         * @param callback 
         */
        void forEach(std::function<void(Node<A>*)> callback);
        /**
         * @brief forEach Indica el acceso de los elemento
         * 
         * @param callback 
         */
        void forEach(std::function<void(A)> callback);
        /**
         * @brief forEach Indica el acceso de los elemento
         * 
         * @param callback 
         */
        void forEach(std::function<void(A,int)> callback);
        /**
         * @brief forEach Indica el acceso de los elemento de atras
         * 
         * @param callback 
         */
        void forEachBack(std::function<void(Node<A>*, int)> callback);
        /**
         * @brief find Sirva para encontrar
         * 
         * @param callback 
         * @return Node<A>* 
         */
        Node<A>* find(std::function<bool(Node<A>*, int)> callback);
        /**
         * @brief find Sirva para encontrar
         * 
         * @param callback 
         * @return Node<A>* 
         */
        Node<A>* find(std::function<bool(Node<A>*)> callback);
        /**
         * @brief find Sirva para encontrar
         * 
         * @param callback 
         * @return Node<A>* 
         */
        Node<A>* find(std::function<bool(A)> callback);
        /**
         * @brief find Sirva para encontrar
         * 
         * @param callback 
         * @return Node<A>* 
         */
        Node<A>* find(std::function<bool(A, int)> callback);
};
/**
 * @brief isEmpty Busca el metodo de emparejar
 * 
 * @tparam A 
 * @return true 
 * @return false 
 */
template <typename A>
bool Tree<A>::isEmpty(){
    return (cursor == nullptr);
}
/**
 * @brief getter para saber el tamanio
 * 
 * @tparam A 
 * @return int 
 */
template <typename A>
int Tree<A>::getSize(){
    return this->size;
}
/**
 * @brief getter del pasado 
 * 
 * @tparam A 
 * @return Node<A>* 
 */
template <typename A>
Node<A>* Tree<A>::getLast(){
    Node<A>* tmp = cursor;
    while (tmp->getNext() != nullptr)
    {
        tmp = tmp->getNext();
    }
    return tmp;
}
/**
 * @brief getter de la raiz  
 * 
 * @tparam A 
 * @return Node<A>* 
 */
template <typename A>
Node<A>* Tree<A>::getRoot(){
    return cursor;
}
/**
 * @brief getter del At
 * 
 * @tparam A 
 * @param index 
 * @return Node<A>* 
 */
template<typename A>
Node<A>* Tree<A>::getAt(int index){
    Node<A>* tmp = cursor;
    int i = 0;
    while (tmp->getNext() != nullptr && index != i)
    {
        tmp = tmp->getNext();
        i++;
    }
    return tmp;
}
/**
 * @brief insert Sirve para insertar los elementos  
 * 
 * @tparam A 
 * @param dat 
 */
template <typename A>
void Tree<A>::insert(A dat){
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
/**
 * @brief eraser Sirve para borrar lo del arbol binario
 * 
 * @tparam A 
 */
template <typename A>
void Tree<A>::eraser(){
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
/**
 * @brief search Sirve para para buscar dentro del arbol 
 * 
 * @tparam A 
 * @return A 
 */
template <typename A>
A Tree<A>::search(){
    Node<A>* last = getLast();
    return last->getDat();
}
/**
 * @brief forEach Indica el acceso de los elemento 
 * 
 * @tparam A 
 * @param callback 
 */
template <typename A>
void Tree<A>::forEach(std::function<void(Node<A>*, int)> callback) {
    Node<A>* tmp = cursor;
    int index = 0;
    while (tmp != nullptr)
    {
        callback(tmp,index);
        tmp = tmp->getNext();
        index++;
    }
}
/**
 * @brief forEach Indica el acceso de los elemento de la parte de atras 
 * 
 * @tparam A 
 * @param callback 
 */
template <typename A>
void Tree<A>::forEachBack(std::function<void(Node<A>*, int)> callback) {
    Node<A>* tmp = getLast();
    int index = size;
    while (tmp != nullptr)
    {
        callback(tmp,index);
        tmp = tmp->getPrevious();
        index--;
    }
}
/**
 * @brief forEach Indica el acceso de los elemento 
 * 
 * @tparam A 
 * @param callback 
 */
template <typename A>
void Tree<A>::forEach(std::function<void(Node<A>*)> callback){
    forEach([&](Node<A>* tmp, int index){
        callback(tmp);
        //callback(tmp->getDat());
    });
}
/**
 * @brief forEach Indica el acceso de los elemento
 * 
 * @tparam A 
 * @param callback 
 */
template <typename A>
void Tree<A>::forEach(std::function<void(A)> callback){
    forEach([&](Node<A>* tmp, int index){
        callback(tmp->getDat());
    });
}
/**
 * @brief forEach Indica el acceso de los elemento 
 * 
 * @tparam A 
 * @param callback 
 */
template <typename A>        
void Tree<A>::forEach(std::function<void(A,int)> callback){
    forEach([&](Node<A>* tmp, int index){
        callback(tmp->getDat(), index);
    });
}
/**
 * @brief find Sirve para encontar el elmento del arbol
 * 
 * @tparam A 
 * @param callback 
 * @return Node<A>* 
 */
template <typename A>
Node<A>* Tree<A>::find(std::function<bool(Node<A>*, int)> callback){
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
/**
 * @brief find Sirve para encontar el elmento del arbol
 * 
 * @tparam A 
 * @param callback 
 * @return Node<A>* 
 */
template <typename A>        
Node<A>* Tree<A>::find(std::function<bool(Node<A>*)> callback){
    return find([&] (Node<A>* node, int index) -> bool{
        return callback(node);
    });
}
/**
 * @brief find Sirve para encontar el elmento del arbol
 * 
 * @tparam A 
 * @param callback 
 * @return Node<A>* 
 */
template <typename A>        
Node<A>* Tree<A>::find(std::function<bool(A)> callback){
    return find([&] (Node<A>* node, int index) -> bool {
        return callback(node->getDat());
    });
}
/**
 * @brief find Sirve para encontar el elmento del arbol 
 * 
 * @tparam A 
 * @param callback 
 * @return Node<A>* 
 */
template <typename A>        
Node<A>* Tree<A>::find(std::function<bool(A, int)> callback){
    return find([&](Node<A>* node, int index) -> bool{
        return callback(node->getDat(), index);
    });
}