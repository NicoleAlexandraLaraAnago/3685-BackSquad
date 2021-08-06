/**  
 * @App Calculadora Polaca    
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computacion
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: Convertir notacion infija a postfija, prefija y funcional
 * 
 * @date 05/07/2021
 * @author Dalton Arevalo
 * @author Diego Jimenez
 * @author Stalin Rivera
 * @author Lizzette Zapata
 * @author Nicole Lara
 */

#pragma once
#include "tnode.h"
#include "tree.h"
#include <string>
#include "opstack.h"

TNode<std::string> generateTree(Tree<std::string> str){
    Tree<TNode<std::string>> operands;
    Node<std::string>* tmp = str.getRoot();
    do{
        TNode<std::string> tnode(tmp->getDat());
        if(!isOperator(tmp->getDat()) && !isFuntion(tmp->getDat())){
            operands.insert(tnode);
        }
        else if(isOperator(tmp->getDat())){
            TNode<std::string> rightDat = operands.search();
            TNode<std::string>* right = new TNode<std::string>(rightDat);
            operands.eraser();
            TNode<std::string> leftDat = operands.search();
            TNode<std::string>* left = new TNode<std::string>(leftDat);
            operands.eraser();
            tnode.setRight(right);
            tnode.setLeft(left);
            operands.insert(tnode);
        }else if(isFuntion(tmp->getDat())){
            TNode<std::string> rightDat = operands.search();
            TNode<std::string>* right = new TNode<std::string>(rightDat);
            operands.eraser();
            tnode.setRight(right);
            operands.insert(tnode);
        }
        tmp = tmp->getNext();
    }while(tmp->getNext() != nullptr);
    TNode<std::string> tnode(tmp->getDat());
    if(isOperator(tmp->getDat())){
        TNode<std::string> rightDat = operands.search();
        TNode<std::string>* right = new TNode<std::string>(rightDat);
        operands.eraser();
        TNode<std::string> leftDat = operands.search();
        TNode<std::string>* left = new TNode<std::string>(leftDat);
        operands.eraser();
        tnode.setRight(right);
        tnode.setLeft(left);
        operands.insert(tnode);
    }else if(isFuntion(tmp->getDat())){
        TNode<std::string> rightDat = operands.search();
        TNode<std::string>* right = new TNode<std::string>(rightDat);
        operands.eraser();
        tnode.setRight(right);
        operands.insert(tnode);
    }
    return operands.search();
}