/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebasti�n Jim�nez, Lizzete Zapata y Dalton Arevalo 
Fecha de creaci�n: 16/07/2021
Fecha de modificaci�n:22/07/2021
Ingenier�a de Software
Estructura de Datos*/
#ifndef Nodo_H
#define Nodo_H

template<class T>
class Nodo
{
private:

	T key;
    int height;
    Nodo<T> * left;
    Nodo<T> * right;
	    
public:
    	
    Nodo<T>(T k);
    T getKey();
    int getHeigth();
    Nodo<T>* getLeft();
    Nodo<T>* getRigth();
    void setKey(T);
    void setHeigth(int);
	void setLeft(Nodo<T>*);
	void setRigth(Nodo<T> *);		
};

#endif
