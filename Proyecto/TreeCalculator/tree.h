#pragma once
#include "tnode.h"

template <typename A>
class Tree{
    private:
        TNode<A>* root = nullptr;
        // int size = 0;
    public:
        Tree() = default;
        void insert(A dat);
        TNode<A>* search(A dat);
        void eraser(A dat);
        TNode<A>* getRoot();
        
};

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