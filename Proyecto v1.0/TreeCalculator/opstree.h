/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
**Docente: Fernando Solis
*AUTORES : Diejo Jiminez
*Dalton Arevalo
*Lizzette Zapata
*Stalin Rivera 
*Nicol Lara
*ENUNCIADO: CREACION DE UN PROGRAMA QUE SIMULE UNA CALCULADORA POLACA INVERSA
*FECHA DE CREACION : 15 DE JULIO DE 2021
*FECHA DE MODIFICACION:  06 DE JULIO DE 2021
*/
#pragma once
#include "tnode.h"
#include "tree.h"
#include <string>
#include "opstack.h"
/**
 * @brief generateTree Es para la generacion del arbol 
 * 
 * @param str 
 * @return TNode<std::string> 
 */
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