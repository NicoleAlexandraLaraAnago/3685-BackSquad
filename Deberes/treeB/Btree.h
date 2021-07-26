#pragma once
#include "node.h"

template <typename A>
class BTree{
    private:
        Node<A>* root;
        int degree;
    public:
        BTree(int degree);
        void iterateTree();
        Node<A>* search(A key);
        void insert(A key);

        void setRoot(Node<A>* root);
        Node<A>* getRoot();
        void setDegree(int degree);
        int getDegree();
};

template <typename A>
void BTree<A>::setRoot(Node<A>* root){
    this->root = root;
}

template <typename A>
Node<A>* BTree<A>::getRoot(){
    return root;
}

template <typename A>
void BTree<A>::setDegree(int degree){
    this->degree = degree;
}

template <typename A>
int BTree<A>::getDegree(){
    return degree;
}

template<typename A>
BTree<A>::BTree(int degree){
    root = nullptr;
    this->degree = degree;
}

template<typename A>
void BTree<A>::iterateTree(){
    if(root != nullptr) root->iterateSubNodes();
}

template<typename A>
Node<A>* BTree<A>::search(A key){
    return (root == nullptr) ? nullptr : root->search(key);
}

template<typename A>
void BTree<A>::insert(A key){
    if(root ==nullptr){
        root = new Node<A>(degree,true);
        *(root->getKeys() + 0) = key;
        root->setN(1);
    }else{
        if(root->getN() == 2*degree-1){
            Node<A>* up = new Node<A>(degree, false);
            *(up->getPointers() + 0) = root;
            // up->pointers[0] = root;
            up->splitNode(0, root);
            int i = 0;
            if (*(up->getKeys() + 0) < key)
                i++;
            Node<A>* auxPointers=*(up->getPointers() + i);
            auxPointers->insertNonFull(key);
            // up->getPointers[i]->insertNonFull(key);
            root = up;
        }else
            root->insertNonFull(key);
    }
}