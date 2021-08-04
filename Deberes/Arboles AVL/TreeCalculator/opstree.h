#pragma once
#include "tnode.h"
#include "stack.h"
#include <string>
#include "opstack.h"

TNode<std::string> generateTree(Stack<std::string> str){
    Stack<TNode<std::string>> operands;
    Node<std::string>* tmp = str.getCursor();
    do{
        TNode<std::string> tnode(tmp->getDat());
        if(!isOperator(tmp->getDat()) && !isFuntion(tmp->getDat())){
            operands.push_(tnode);
        }
        else if(isOperator(tmp->getDat())){
            TNode<std::string> rightDat = operands.peak();
            TNode<std::string>* right = new TNode<std::string>(rightDat);
            operands.pop();
            TNode<std::string> leftDat = operands.peak();
            TNode<std::string>* left = new TNode<std::string>(leftDat);
            operands.pop();
            tnode.setRight(right);
            tnode.setLeft(left);
            operands.push_(tnode);
        }else if(isFuntion(tmp->getDat())){
            TNode<std::string> rightDat = operands.peak();
            TNode<std::string>* right = new TNode<std::string>(rightDat);
            operands.pop();
            tnode.setRight(right);
            operands.push_(tnode);
        }
        tmp = tmp->getNext();
    }while(tmp->getNext() != nullptr);
    TNode<std::string> tnode(tmp->getDat());
    if(isOperator(tmp->getDat())){
        TNode<std::string> rightDat = operands.peak();
        TNode<std::string>* right = new TNode<std::string>(rightDat);
        operands.pop();
        TNode<std::string> leftDat = operands.peak();
        TNode<std::string>* left = new TNode<std::string>(leftDat);
        operands.pop();
        tnode.setRight(right);
        tnode.setLeft(left);
        operands.push_(tnode);
    }else if(isFuntion(tmp->getDat())){
        TNode<std::string> rightDat = operands.peak();
        TNode<std::string>* right = new TNode<std::string>(rightDat);
        operands.pop();
        tnode.setRight(right);
        operands.push_(tnode);
    }
    return operands.peak();
}