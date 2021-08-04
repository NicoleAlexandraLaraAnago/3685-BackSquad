#pragma once

template <typename A>
class TNode{
    
        A dat;
        TNode<A>* right = nullptr;
        TNode<A>* left = nullptr;
        TNode<A>* up = nullptr;
    public:
        TNode();
        TNode(A dat);
        TNode(const TNode<A> &tnode);
        A getDat();
        void setDat(A dat);
        TNode<A>* getRight();
        void setRight(TNode<A>* right);
        TNode<A>* getLeft();
        void setLeft(TNode<A>* left);
        TNode<A>* getUp();
        void setUp(TNode<A>* up);

        bool isLeaf();
};

template <typename A>
TNode<A>::TNode(){
}

template <typename A>
TNode<A>::TNode(A dat){
    this->dat = dat;
}

template <typename A>
TNode<A>::TNode(const TNode<A> &tnode){
    dat = tnode.dat;
    right = new TNode<A>;

    if(tnode.right != nullptr)
        *right = *tnode.right;
    else 
        right = nullptr;
    left = new TNode<A>;
    if(tnode.left != nullptr)
        *left = *tnode.left; 
    else 
        left = nullptr;
    up = new TNode<A>;
    if(tnode.up != nullptr)
        *up = *tnode.left;
    else 
        up = nullptr;
}

template <typename A>
A TNode<A>::getDat(){
    return this->dat;
}

template <typename A>
void TNode<A>::setDat(A dat){
    this->dat = dat;
}

template <typename A>
TNode<A>* TNode<A>::getRight(){
    return right;
}

template <typename A>
void TNode<A>::setRight(TNode<A>* right){
    this->right = right;
}

template <typename A>
TNode<A>* TNode<A>::getLeft(){
    return left;
}

template <typename A>
void TNode<A>::setLeft(TNode<A>* left){
    this->left = left;
}

template <typename A>
TNode<A>* TNode<A>::getUp(){
    return up;
}

template <typename A>
void TNode<A>::setUp(TNode<A>* up){
    this->up = up;
}

template <typename A>
bool TNode<A>::isLeaf(){
    if(right == nullptr && left == nullptr)
        return true;
    else
        return false;
}