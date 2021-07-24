/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebastián Jiménez, Lizzete Zapata y Dalton Arevalo 
Fecha de creación: 16/07/2021
Fecha de modificación:22/07/2021
Ingeniería de Software
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
