#pragma once
#include <cstdlib>

template <typename A>
class Node{
private:
    A *keys;
    int degree;
    Node<A>** pointers;
    int n;
    bool leaf;
public:
    Node(int degree, bool leaf);

    void setKeys(A* keys);
    A* getKeys();
    void setDegree(int degree);
    int getDegree();
    void setPointers(Node<A>** pointers);
    Node<A>** getPointers();
    void setN(int n);
    int getN();
    void setLeaf(bool leaf);
    bool getLeaf();

    void iterateSubNodes();
    Node<A>* search(A key);
    void insertNonFull(A key);
    void splitNode(int i, Node<A>* up);

};

template <typename A>
void Node<A>::setKeys(A* keys){
    this->keys = keys;
}

template <typename A>
A* Node<A>::getKeys(){
    return keys;
}
    
template <typename A>
void Node<A>::setDegree(int degree){
    this->degree = degree;
}

template <typename A>
int Node<A>::getDegree(){
    return degree;
}

template <typename A>
void Node<A>::setPointers(Node<A>** pointers){
    this->pointers = pointers;
}

template <typename A>
Node<A>** Node<A>::getPointers(){
    return pointers;
}

template <typename A>
void Node<A>::setN(int n){
    this->n = n;
}

template <typename A>
int Node<A>::getN(){
    return n;
}

template <typename A>
void Node<A>::setLeaf(bool leaf){
    this->leaf = leaf;
}

template <typename A>
bool Node<A>::getLeaf(){
    return leaf;
}

template <typename A>
Node<A>::Node(int degree, bool leaf){
    this->degree = degree;
    this->leaf = leaf;
    
    // keys = (A *)malloc(degree * sizeof(A));
    ////////////////////////
    // keys = new A[2*degree-1];
    keys = (A *)malloc((2*degree-1) * sizeof(A));
    // pointers = (Node<A> **)malloc((degree+1) * sizeof(Node<A> *));
    // for (int i = 0; i < (degree+1); i++){
    //     *(pointers+i) =(Node<A> *)malloc(sizeof(Node<A>));
    // }
    ////////////////////
    // pointers = new Node<A> *[2*degree];
    pointers = (Node<A> **)malloc((2*degree) * sizeof(Node<A> *));
    for (int i = 0; i < (degree+1); i++){
        *(pointers+i) =(Node<A> *)malloc(sizeof(Node<A>));
    }
    n = 0;
}

template <typename A>
void Node<A>::iterateSubNodes(){
    int i;
    for( i = 0; i < n; i++){
        Node<A> auxPointers = **(pointers + i); 
        if(!leaf)
            auxPointers.iterateSubNodes();
            // pointers[i]->iterateSubNodes();
            // **(pointers + i)->iterateSubNodes();
            
        std::cout<< " " << *(keys + i);
    }
    Node<A> auxPointers = **(pointers + i);
    if(!leaf){
        auxPointers.iterateSubNodes();
        // pointers[i]->iterateSubNodes();
    }
}

template <typename A>
Node<A>* Node<A>::search(A value){
    int i = 0;
    while(i < n && *(keys+i) < value)
        i++;
    if(*(keys+1) == value)
        return this;
    if(leaf)
        return NULL;
    Node<A> auxPointers = **(pointers + i);
    return auxPointers.search(value);
    // return pointers[i]->search(value);
}

template <typename A>
void Node<A>::insertNonFull(A key){
    int i = n-1;
    if (leaf){
        while (i >= 0 && *(keys + i) > key){
            *(keys + i + 1) = *(keys + i);
            i--;
        }
        *(keys + i + 1) = key;
        n = n + 1;
    }else{
        while (i >= 0 && *(keys + i) > key)
            i--;
        Node<A> auxPointers = **(pointers + i + 1);
        // Node<A> auxPointers = pointers[i+1];
        Node<A>* auxP = *(pointers + i + 1);

        if (auxPointers.getN() == (2*degree-1)){
            splitNode(i + 1, auxP);
            if (*(keys + i + 1) < key)
                i++;
        }
        auxPointers.insertNonFull(key);
    }
}

template <typename A>
void Node<A>::splitNode(int i, Node<A>* up){
    Node<A>* newUp = new Node<A>(up->degree, up->leaf);
    newUp->n = degree-1;
    for (int j = 0; j < (degree - 1); j++)
        *(newUp->keys + j) = *(up->keys+j+ degree);
    if (!up->leaf){
        for(int j=0; j< degree; j++)
            *(newUp->pointers + j) = *(up->pointers+j + degree);
    }
    up->n= degree-1;
    for(int j = n; j>= i+1; j--)
        *(pointers+j+1) = *(pointers+j);
    *(pointers+i+1) = newUp;
    for(int j = n-1; j>= i; j--)
        *(keys + j + 1) = *(keys + j);
    *(keys + i) = *(up->keys+degree-1);
    n = n+1;
}