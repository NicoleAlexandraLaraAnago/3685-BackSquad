/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
**Docente: Fernando Solis
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

template <typename A>
class Node{
    private:
    /**
     * @brief A De los datos 
     * 
     */
        A dat;
        /**
         * @brief next Para pasar al siguiente 
         * 
         */
        Node<A>* next = nullptr;
        /**
         * @brief previous Donde recorre y pasa al nulo
         * 
         */
        Node<A>* previous = nullptr;
        // Node<A>* next;
        // Node<A>* previous;
    public:
    /**
     * @brief Construct a new Node object
     * 
     */
        Node();
        /**
         * @brief Construct a new Node object
         * 
         * @param dat 
         */
        Node(A dat);
        /**
         * @brief Get the Dat object
         * 
         * @return A 
         */
        A getDat();
        /**
         * @brief Set the Dat object
         * 
         * @param dat 
         */
        void setDat(A dat);
        /**
         * @brief Get the Next object
         * 
         * @return Node<A>* 
         */
        Node<A>* getNext();
        /**
         * @brief Set the Next object
         * 
         * @param next 
         */
        void setNext(Node<A>* next);
        /**
         * @brief Get the Previous object
         * 
         * @return Node<A>* 
         */
        Node<A>* getPrevious();
        /**
         * @brief Set the Previous object
         * 
         * @param previous 
         */
        void setPrevious(Node<A>* previous);
};
/**
 * @brief Construct a new Node< A>:: Node object
 * 
 * @tparam A 
 */
template <typename A>
Node<A>::Node(){
}
/**
 * @brief Construct a new Node< A>:: Node object
 * 
 * @tparam A 
 * @param dat 
 */
template <typename A>
Node<A>::Node(A dat){
    this->dat = dat;
    // this->next = nullptr;
    // this->previous= nullptr;
}
/**
 * @brief getter de los datos 
 * 
 * @tparam A 
 * @return A 
 */
template <typename A>
A Node<A>::getDat(){
    return this->dat;
}
/**
 * @brief setter de los datos 
 * 
 * @tparam A 
 * @param dat 
 */
template <typename A>
void Node<A>::setDat(A dat){
    this->dat = dat;
}
/**
 * @brief getter del siguiente 
 * 
 * @tparam A 
 * @return Node<A>* 
 */
template <typename A>
Node<A>* Node<A>::getNext(){
    return this->next;
}
/**
 * @brief setter del siguiente 
 * 
 * @tparam A 
 * @param next 
 */
template <typename A>
void Node<A>::setNext(Node<A>* next){
    this->next = next;
}
/**
 * @brief getter de los previous
 * 
 * @tparam A 
 * @return Node<A>* 
 */
template <typename A>
Node<A>* Node<A>::getPrevious(){
    return this->previous;
}
/**
 * @brief setter de los previous
 * 
 * @tparam A 
 * @param previous 
 */
template <typename A>
void Node<A>::setPrevious(Node<A>* previous){
    this->previous = previous;
}