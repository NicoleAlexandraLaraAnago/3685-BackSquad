/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebastián Jiménez, Lizzete Zapata y Dalton Arevalo 
Fecha de creación: 16/07/2021
Fecha de modificación:22/07/2021
Ingeniería de Software
Estructura de Datos*/
#include "ArbolAVL.h"

template <typename T>
Nodo<T>* ArbolAVL<T>::getRaiz(){
	return raiz;
}
template <typename T>
int ArbolAVL<T>::getN(){
	return n;
}
template <typename T>
void ArbolAVL<T>:: setRaiz(Nodo<T> *raiz){
	raiz=raiz;
	
}
template <typename T>
void ArbolAVL<T>:: setN(int n){
	n=n;
}

template <typename T>
void ArbolAVL<T>::insert(T x){
    raiz=insertUtil(raiz, x);
}

template <typename T>
void ArbolAVL<T> ::inorder(){
    inorderUtil(raiz);
}

template <typename T>
void ArbolAVL<T> ::remove(T x){
    raiz=removeUtil(raiz, x);
}

template <typename T>
int ArbolAVL<T>::height(Nodo<T> * head)
{
    if(head==NULL) return 0;
    return head->getHeigth();
}

template <typename T>
Nodo<T>* ArbolAVL<T>::rightRotation(Nodo<T> * head)
{
    Nodo<T> * newhead = head->getLeft();

    head->setLeft( newhead->getRigth() );
    newhead->setRigth( head );
    head->setHeigth( 1+ std::max(height(head->getLeft()), height(head->getRigth())) );
    newhead->setHeigth( 1+ std::max(height(newhead->getLeft()), height(newhead->getRigth())) );
    return newhead;
}
template<typename T>
Nodo<T> * ArbolAVL<T>::leftRotation(Nodo<T> * head)
{
    Nodo<T> * newhead = head->getRigth();
    head->setRigth( newhead->getLeft() );
    newhead->setLeft( head );
    head->setHeigth( 1+ std::max( height(head->getLeft() ) , height(head->getRigth() )) ); 
    newhead->setHeigth( 1+ std::max( height(newhead->getLeft() ) , height(newhead->getRigth() )) );
    return newhead;
}

template <typename T>
void ArbolAVL<T>::inorderUtil(Nodo<T> * head)
{
    if(head==NULL) return ;
    inorderUtil(head->getLeft());
    std::cout<<head->getKey()<<" ";
	inorderUtil(head->getRigth());
}

template <typename T>
Nodo<T>* ArbolAVL<T>::insertUtil(Nodo<T>* head, T x) 
{
    if (head == NULL) {
        n += 1;
        Nodo<T>* temp = new Nodo<T>(x);
        return temp;
    }
    if (x < head->getKey())
        head->setLeft(insertUtil(head->getLeft(), x));
    else if (x > head->getKey())
        head->setRigth(insertUtil(head->getRigth(), x));
    head->setHeigth(1+ std::max(height(head->getLeft()),height(head->getRigth())));
    int bal = height(head->getLeft()) - height(head->getRigth());
    if (bal > 1) {
        if (x < head->getLeft()->getKey()) {
            return rightRotation(head);
        }
        else {
            head->setLeft(leftRotation(head->getLeft()));
            return rightRotation(head);
        }
    }
    else if (bal < -1) {
        if (x > head->getRigth()->getKey()) {
            return leftRotation(head);
        }
        else {
            head->setRigth(rightRotation(head->getRigth()));
            return leftRotation(head);
        }
    }
    return head;
}


template <typename T>

Nodo<T>* ArbolAVL <T> :: removeUtil(Nodo<T>* head, T x) {
    if (head == NULL) return NULL;
    if (x < head->getKey() ) {
        head->setLeft( removeUtil(head->getLeft(), x) ); 
    }
    else if (x > head->getKey() ) {
        head->setRigth( removeUtil(head->getRigth(), x) );
    }
    else {
        Nodo<T>* r = head->getRigth();
        if (head->getRigth() == NULL) {
            Nodo<T>* l = head->getLeft();
            delete(head);
            head = l;
        }
        else if (head->getLeft() == NULL) {
            delete(head);
            head = r;
        }
        else {
            while (r->getLeft() != NULL) r = r->getLeft();
            head->setKey( r->getKey() );
            head->setRigth( removeUtil(head->getRigth(), r->getKey()) );
        }
    }
    if (head == NULL) return head;
    head->setHeigth(1 + std::max(height(head->getLeft()), height(head->getRigth() ))); 
    int bal = height(head->getLeft()) - height(head->getRigth());
    if (bal > 1) {
        if (x > head->getLeft()->getKey()) {
            return rightRotation(head);
        }
        else {
            head->setLeft( leftRotation(head->getLeft()  ) ); 
            return rightRotation(head);
        }
    }
    else if (bal < -1) {
        if (x < head->getRigth()->getKey()) {
            return leftRotation(head);
        }
        else {
            head->setRigth( rightRotation(head->getRigth()) );
            return leftRotation(head);
        }
    }
    return head;
}

template class ArbolAVL<int>;
