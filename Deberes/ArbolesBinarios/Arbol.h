/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebastián Jiménez, Lizzete Zapata, Nicole Lara y Dalton Arevalo 
Fecha de creación: 16/07/2021
Fecha de modificación:22/07/2021
Ingeniería de Software
Estructura de Datos*/
#include "Nodo.h" //incluimos la librería de la clase nodo


class Arbol{

    private: 
        Nodo* arbol = NULL; // inicializmos el arbol en NULL


    public:

        void setArbol(Nodo*);
        Nodo* getArbol();

        Nodo* crearNodo(int); // metodo para crear el nodo
        void insertarNodo(Nodo*&, int); // metodo para inserar el nodo
        void mostrar(Nodo*, int); // metodo para mostrar el arbol
        bool buscar(Nodo*, int); // metodo para buscar un elemento del arbol

        void preOrden(Nodo*); // recorrido del arbol en preorden
        void inOrden(Nodo*); // recorrido del arbol en inorden
        void postOrden(Nodo*); // recorrido del arbol en postorden

};
//Arbol.cpp
void Arbol::setArbol(Nodo* _arbol){
    arbol = _arbol;
}

Nodo* Arbol::getArbol(){
    return arbol;
}

Nodo* Arbol::crearNodo(int dato){

    Nodo* nuevoNodo = new Nodo();

    nuevoNodo->setDato(dato);
    nuevoNodo->setDerecha(NULL);
    nuevoNodo->setIzquierda(NULL);

    return nuevoNodo;
}

void Arbol::insertarNodo(Nodo*& arbol, int dato){

    if(arbol == NULL){
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
    }
    else{

        int raiz = arbol->getDato();
        if(dato < raiz){
            insertarNodo(arbol->getIzquierda(), dato);
        }
        else{
            insertarNodo(arbol->getDerecha(), dato);
        }
    }
}

void Arbol::mostrar(Nodo* arbol, int contador){

    if(arbol == NULL){
        return;
    }
    else{

        mostrar(arbol->getDerecha(), contador+1);

        for(int i = 0; i < contador; i++){
            cout << "     ";
        }
        cout<<arbol->getDato() << endl;

        mostrar(arbol->getIzquierda(), contador +1);
    }
}

bool Arbol::buscar(Nodo* arbol, int dato){

    if(arbol == NULL){
        return false;
    }
    else if(arbol->getDato() == dato){
        return true;
    }
    else if(dato < arbol->getDato()){
        buscar(arbol->getIzquierda(), dato);
    }
    else{
        buscar(arbol->getDerecha(), dato);
    }

}

////////////////////////////////////////


void Arbol::preOrden(Nodo* arbol){

    if(arbol == NULL){
        return;
    }
    else{

        cout << arbol->getDato() << "   ";
        preOrden(arbol->getIzquierda());
        preOrden(arbol->getDerecha());
    }
}

void Arbol::inOrden(Nodo* arbol){

    if(arbol == NULL){
        return;
    }
    else{

        inOrden(arbol->getIzquierda());
        cout << arbol->getDato() << "   ";
        inOrden(arbol->getDerecha());
    }
}

void Arbol::postOrden(Nodo* arbol){

    if(arbol == NULL){
        return;
    }
    else{

        postOrden(arbol->getIzquierda());
        postOrden(arbol->getDerecha());
        cout << arbol->getDato() << "   ";
    }
}

