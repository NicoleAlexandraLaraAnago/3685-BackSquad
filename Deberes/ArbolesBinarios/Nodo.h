/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebastián Jiménez, Lizzete Zapata, Nicole Lara y Dalton Arevalo 
Fecha de creación: 16/07/2021
Fecha de modificación:22/07/2021
Ingeniería de Software
Estructura de Datos*/
#include <iostream> //libreria usada para cout y cin 
#include <stdio.h>

using namespace std;

class Nodo{

    private:
        int dato; // informacion
        Nodo* izquierda; // apuntador al lado izquierdo
        Nodo* derecha; //apuntador al lado derecho 
    
    public:
        
        //modifica el apuntador 
        void setDato(int); 
        void setIzquierda(Nodo*); 
        void setDerecha(Nodo*);
        
        //devuelve la informacion del nodo
        int getDato();
        Nodo*& getIzquierda(); 
        Nodo*& getDerecha(); 
};
//Nodo.pp
//Modifican el apuntador del Nodo indicado
void Nodo::setDato(int _dato){
    dato = _dato; 
}

void Nodo::setIzquierda(Nodo* _izquierda){
    izquierda = _izquierda;
}

void Nodo::setDerecha(Nodo* _derecha){
    derecha = _derecha;
}


//Retornar el apuntador del Nodo indicado
int Nodo::getDato(){
    return dato;
}

Nodo*& Nodo::getIzquierda(){
    return izquierda;
} 

Nodo*& Nodo::getDerecha(){
    return derecha;
} 



