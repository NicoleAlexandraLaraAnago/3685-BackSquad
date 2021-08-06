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
class TNode{
    /**
     * @brief 
     * 
     */
        A dat;
        /**
         * @brief 
         * 
         */
        TNode<A>* right = nullptr;
        /**
         * @brief 
         * 
         */
        TNode<A>* left = nullptr;
        /**
         * @brief 
         * 
         */
        TNode<A>* up = nullptr;
    public:
    /**
     * @brief Construct a new TNode object
     * 
     */
        TNode();
        /**
         * @brief Construct a new TNode object
         * 
         * @param dat 
         */
        TNode(A dat);
        /**
         * @brief Construct a new TNode object
         * 
         * @param tnode 
         */
        TNode(const TNode<A> &tnode);
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
         * @brief Get the Right object
         * 
         * @return TNode<A>* 
         */
        TNode<A>* getRight();
        /**
         * @brief Set the Right object
         * 
         * @param right 
         */
        void setRight(TNode<A>* right);
        /**
         * @brief Get the Left object
         * 
         * @return TNode<A>* 
         */
        TNode<A>* getLeft();
        /**
         * @brief Set the Left object
         * 
         * @param left 
         */
        void setLeft(TNode<A>* left);
        /**
         * @brief Get the Up object
         * 
         * @return TNode<A>* 
         */
        TNode<A>* getUp();
        /**
         * @brief Set the Up object
         * 
         * @param up 
         */
        void setUp(TNode<A>* up);
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
        bool isLeaf();
};
/**
 * @brief Construct a new TNode<A>::TNode object
 * 
 * @tparam A 
 */
template <typename A>
TNode<A>::TNode(){
}
/**
 * @brief Construct a new TNode<A>::TNode object
 * 
 * @tparam A 
 * @param dat 
 */
template <typename A>
TNode<A>::TNode(A dat){
    this->dat = dat;
}
/**
 * @brief Construct a new TNode<A>::TNode object
 * 
 * @tparam A 
 * @param tnode 
 */
template <typename A>
TNode<A>::TNode(const TNode<A> &tnode){
    dat = tnode.dat;
    right = new TNode<A>;

    if(tnode.right != nullptr)
        *right = *tnode.right;
    else 
        right = nullptr;
    left = new TNode<A>;
    if(tnode.left != nullptr)
        *left = *tnode.left; 
    else 
        left = nullptr;
    up = new TNode<A>;
    if(tnode.up != nullptr)
        *up = *tnode.left;
    else 
        up = nullptr;
}
/**
 * @brief getter de los datos 
 * 
 * @tparam A 
 * @return A 
 */
template <typename A>
A TNode<A>::getDat(){
    return this->dat;
}
/**
 * @brief setter de los datos 
 * 
 * @tparam A 
 * @param dat 
 */
template <typename A>
void TNode<A>::setDat(A dat){
    this->dat = dat;
}
/**
 * @brief getter del nodo de la dereha
 * 
 * @tparam A 
 * @return TNode<A>* 
 */
template <typename A>
TNode<A>* TNode<A>::getRight(){
    return right;
}
/**
 * @brief setter del nodo de la derecha
 * 
 * @tparam A 
 * @param right 
 */
template <typename A>
void TNode<A>::setRight(TNode<A>* right){
    this->right = right;
}
/**
 * @brief getter de la izquierda
 * 
 * @tparam A 
 * @return TNode<A>* 
 */
template <typename A>
TNode<A>* TNode<A>::getLeft(){
    return left;
}
/**
 * @brief setter de la izquierda
 * 
 * @tparam A 
 * @param left 
 */
template <typename A>
void TNode<A>::setLeft(TNode<A>* left){
    this->left = left;
}
/**
 * @brief TNode Indica la plantilla del nodo
 * 
 * @tparam A 
 * @return TNode<A>* 
 */
template <typename A>
TNode<A>* TNode<A>::getUp(){
    return up;
}
/**
 * @brief 
 * 
 * @tparam A 
 * @param up 
 */
template <typename A>
void TNode<A>::setUp(TNode<A>* up){
    this->up = up;
}
/**
 * @brief isLeaf es la hoja derecha del nodo
 * 
 * @tparam A 
 * @return true 
 * @return false 
 */
template <typename A>
bool TNode<A>::isLeaf(){
    if(right == nullptr && left == nullptr)
        return true;
    else
        return false;
}