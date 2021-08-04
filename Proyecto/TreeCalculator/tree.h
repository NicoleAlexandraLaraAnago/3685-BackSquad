#pragma once
#include "tnode.h"

template <typename A>
class Tree{
    private:
        TNode<A>* root = nullptr;
        ofstream archivo;
        // int size = 0;
    public:
        Tree() = default;
        bool Vacio();
        void imprimirArbol(Nodo<A>*arbol);
        Node<T>* crearNuevoNodo(A);
        void insert(A dat);
        TNode<A>* getArbol();
        void setArbol(Node<A>*);
        void displayArbol();
        void eliminarNodo(Node<A>* nodoElimina);
        void mostrarArbol(Node<A>* arbol, int cont);
        TNode<A>* search(A dat);
        bool buscar(int  valor);
        void eraser(A dat);
        TNode<A>* getRoot();
        void eliminarNodoPri(A, Node<A>*);
        void eliminarCoincidencias();
        Node<A>* getmin(Node<A>*raiz);
        int encontrarMinimo(Node<A>*);
        void removerEntre(Node<A>*,Node<A>*, bool);
        void generarGrafico();
        void graficarArbol(Node<A>*nodo);
        


};
template <typename A>
bool Arbol<A>::Vacio(){
    return (raiz==nullptr);
}
template <typename A>
Node<A>*Arbol<A>::crearNuevoNodo(A valor){
    Node<A>* temp=new Node<A>();
    temp->setValor(valor);
    return temp;
}
template <typename A>
Node<A>* Arbol<A>::getArbol(){
    return this->root;
}
template <typename A>
void Arbol<A>::setArbol(Nodo<A>* _arbol){
    this->root=_arbol;
}
template <typename A>
void Arbol<A>::displayArbol(){
    imprimirArbol(root);
    cout<<endl<<endl;
    cout<<endl<<endl;
    mostrarArbol(root, 0);
}
template <typename A>
void Arbol<A>::imprimirArbol(Node<A>* arbol){
    if(arbol!==NULL){
        imprimirArbol(arbol->getNodoIzquierdo());
        cout<<" "<<arbol->getValor()<<endl" ";
        imprimirArbol(arbol->getNodoDerecho());
    }
}
template<typename A>
Node<A>* arbol<A>::buscar(int Valor, Node<A> *temp){

    if(temp != nullptr)
    {
        if(Valor==temp->getValor())
            return temp;
        if(Valor<temp->getValor())
            return buscar(Valor, temp->getNodoIzquierdo());
        else
            return buscar(Valor, temp->getNodoDerecho());

    }else{
        return nullptr;
    }
}

template<typename A>
bool Arbol<A>::buscar(int valor){
Node<A>* temp = buscar(valor, root);
if(temp==nullptr){
    return false;
}
else if(temp->getValor()==valor){
    return true;
}else{
    return false;
}
}
template<typename A>
void Arbol<A>::eliminar(A dato){
    eliminarNodoPri(dato, root);
}
template <typename A>
void Arbol<A>::eliminarNodoPri(A dato,Node<A>*privado){
    if(root !=nullptr){
        if(root->getValor() == dato)
            eliminarCoincidencias();
        else{
            if(dato < privado->gatValor()&&privado->primero->getNodoIzquierda() !=nullptr){
               privado->getNodoIzquierdo()->getValor()==dato ? removeEntre(privado, getNodoIzquierdo(), true): elominarNodoPri(dato, privado->getNodoIzquierdo());

            }
            else
            if(dato > privado->getValor()&& privado->getNodoDerecha()!=nullptr){
                privado->getNodoDerecho()->getValor() == dato ? removeEntre(privado, privado->getNodoDerecho(),false) : eliminarNodoPri(dato, privado->getNodoDerecho());
            }
            else
                cout<< "No se ha encontrado el dato en el arbol"<<endl;
        }
    }else
    cout<<"El arbol esta vacio"<<endl;
}

template<typename A>
void Arbol<A>::eliminarCoincidencias(){
    if(root !=nullptr){
        Node<A>* datoPrivado = root;
        int datoRoot = root->getValor();
        int datoMinimo;
        if (root ->getNodoIzquierdo()==nullptr&&root->getNodoDerecho()==nullptr){
           delete datoPrivado;
           root = nullptr;
        }
        else
        if(root->getNodoIzquierdo()!=nullptr&&root->getNodoDerecho()==nullptr){
            root=root->getNodoIzquierdo();
            datoPrivado->detNodoIzquierdo(nullptr);
            delete datoPrivado;
        }else
        if(root->getNodoIzquierdo()==nullptr&&root->getNodoDerecho()!=nullptr){
           datoMinimo = encontrarMinimo(root->getNodoDerecho());
            eliminarNodoPri(datoMinimo, root);
            root->setValor(datoMinimo);
        }
    }else
    cout<<"!!ERROR"<<endl;

}

template <typename A>
void Arbol<A>::removeEntre(NNodo<A>* padre, Node<A>*marca,bool izquierdo){
    if(root !=nullptr){
        Node<A>*principal;
        int datoMarcato=marca->getValor();
        int datoMinimo;
        if(marca->getNodoIzquierdo()==nullptr && marca->getNodoDerecho()==nullptr){
            principal=marca;
            izquierdo==true ? padre->setNodoIzquierdo(nullptr): padre->setNodoDerecho(nullptr);
            delete principal;
        }
        else 
        if(marca->getNodoIzquierdo()==nullptr && marca->getNodoDerecho()!=nullptr){
            izquierdo == true ? padre->setNodoIzquierdo(marca->getNodoDerecho(): padre->setNodoDerecho(marca->getNodoDerecho());
            marca->setNodoIzquierdo(nullptr);
            principal=marca;
            delete principal;
        }
        else 
        if(marca->getNodoIzquierdo()!=nullptr && marca->getNodoDerecho()==nullptr){
          izquierdo == true ? padre->setNodoIzquierdo(marca->getNodoIzquierdo()): padre->setNodoDerecho(marca->getNodoIzquierdo());
          marca->setNodoIzquierdo(nullptr);
          principal=marca;
          delete principal;
        }else{
            datoMinimo=encontrarMinimo(marca->getNodoDerecho());
            eliminarNodoPri(datoMinimo, marca);
            marca->setValor(datoMinimo);
        }
    }
    else
    std::cout<<"No coincide"<<endl;
    system("pause");
    getch();
}

template <typename A>
void Tree<A>::insert(A dat){


}

template <typename A>
TNode<A>* Tree<A>::search(A dat){

}

template <typename A>
void Tree<A>::eraser(A dat){

}

template <typename A>
TNode<A>* Tree<A>::getRoot(){
    return this->root;
}
