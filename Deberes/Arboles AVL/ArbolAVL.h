/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebasti�n Jim�nez, Lizzete Zapata, Nicole Lara y Dalton Arevalo 
Fecha de creaci�n: 16/07/2021
Fecha de modificaci�n:22/07/2021
Ingenier�a de Software
Estructura de Datos*/

#include <iostream>
#include "Nodo.h"

template <typename T>
class ArbolAVL{
    public:    
        Nodo<T>* getRaiz();
        int getN();
        void setN(int n);
        void setRaiz(Nodo<T>* raiz);
        void insert(T x);
        void inorder();
        void remove(T x);
		Nodo<T>* RotacionCompuestaID(Nodo<T>*, Nodo<T>*);
		Nodo<T>* RotacionCompuestaDI(Nodo<T>*, Nodo<T>*);
        Nodo<T>* removeUtil(Nodo<T>* head, T x);

    private:
    	Nodo<T> * raiz = NULL;
        int n;
        int height(Nodo<T> * head);      
        
        Nodo<T> * rightRotation(Nodo<T> * head);
		
        Nodo<T> * leftRotation(Nodo<T> * head);
	
        void inorderUtil(Nodo<T> * head);

        Nodo<T> * insertUtil(Nodo<T>*,T);
       
};


