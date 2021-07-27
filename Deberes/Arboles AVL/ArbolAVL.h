/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebastián Jiménez, Lizzete Zapata, Nicole Lara y Dalton Arevalo 
Fecha de creación: 16/07/2021
Fecha de modificación:22/07/2021
Ingeniería de Software
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


