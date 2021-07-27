/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebastián Jiménez, Lizzete Zapata,Nicole Lara y Dalton Arevalo 
Fecha de creación: 16/07/2021
Fecha de modificación:22/07/2021
Ingeniería de Software
Estructura de Datos*/
#include "Nodo.h"
#include <iostream>

template<class T>
Nodo<T>::Nodo(T k)
{
    this->height = 1;
    this->key = k;
    this->left = NULL;
    this->right = NULL;
}

template<class T>
T Nodo<T>::getKey(){
	return this->key;
}

template<class T>
int Nodo<T>::getHeigth()
{
	return this->height;
}

template<class T>
Nodo<T>* Nodo<T>::getLeft(){
	return this->left;
}

template<class T>
Nodo<T>* Nodo<T>::getRigth(){
	return this->right;
}

template<class T>
void Nodo<T>::setKey(T key){
	this->key = key;
}

template<class T>
void Nodo<T>::setHeigth(int h)
{
	this->height = h;
}

template<class T>
void Nodo<T>::setLeft(Nodo<T>* L){
	this->left = L;	
}
template<class T>
void Nodo<T>::setRigth(Nodo<T> * R){
	this->right = R;
}
template class Nodo<int>; 
