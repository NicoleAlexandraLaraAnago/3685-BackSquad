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
#include "tree.h"
#include "opstr.h"
#include <math.h>
#include <string>
#include <cstring>
#include <iostream>

// bool isOperator(char c){
//     return (c == '+' || c == '-' || c == '*' || c == '/');
// }

bool isReal(char c){
    return (c == '0' || c == '1' || c == '2' || c == '3' || c == '4'
    || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '.');
}

bool isReal(std::string c){
    return (c == "0" || c == "1" || c == "2" || c == "3" || c == "4"
    || c == "5" || c == "6" || c == "7" || c == "8" || c == "9" || c == ".");
}

int precedencia(std::string c){
    return (c == "+" || c == "-") ? 1 :
    (c == "*") ? 2 :
    (c == "/") ? 3 :
    (c == "^") ? 4 : 0;
}

bool isFuntion(std::string c){
    return (c == "sin" || c == "cos" || c == "tan" || c == "exp" || c == "log");
}

Tree<std::string> inToStack(std::string chain){
    char* str = new char;
    std::strcpy(str,chain.c_str());
    Tree<std::string> outcome;
    int i = 0;
    while(*(str + i) != '\0'){
        if(!isReal(*(str+i))){
            if(isOperator(*(str+i))){
                outcome.insert(chain.substr(i,1));
            }else if(*(str+i) !='(' && *(str+i) !=')'){
                int j = i;
                while(!isReal(*(str+i)) && *(str+i) != '('){
                    i++;
                }
                outcome.insert(chain.substr(j,i-j));
                i--;
            }else if(*(str+i) =='(' || *(str+i) ==')'){
                outcome.insert(chain.substr(i,1));
            }
            else{
                i++;
                continue;
            }
        }else{
            int k = i;
            while (isReal(*(str+i))){
                i++;
            }
            outcome.insert(chain.substr(k,i-k));
            i--;
        }
        i++;
    }
    return outcome;
}

Tree<std::string> inToPost(Tree<std::string> str){
    Tree<std::string> operators;
    Tree<std::string> outcome;
    Node<std::string>* tmp = str.getRoot();
    while(tmp->getNext() != nullptr){
        if(isOperator(tmp->getDat()) || isFuntion(tmp->getDat())){
            int current = precedencia(tmp->getDat());
            int st = 0;
            operators.isEmpty()? st =0 : st= precedencia(operators.search());
            bool aux;
            operators.isEmpty()? aux = false : aux = !isFuntion(operators.search());
            while( !operators.isEmpty() &&
            st > current && !isFuntion(tmp->getDat())){
                outcome.insert(operators.search());
                operators.eraser();
                operators.isEmpty()? st =0 : st= precedencia(operators.search());
            }
            operators.insert(tmp->getDat());
        }else if (tmp->getDat() =="("){
            operators.insert(tmp->getDat());
        }else if (tmp->getDat() == ")"){
            while(operators.search() != "("){
                outcome.insert(operators.search());
                operators.eraser();
            }
            operators.eraser();
            if(!operators.isEmpty() && isFuntion(operators.search())){
                outcome.insert(operators.search());
                operators.eraser();
            }
        }else{
            outcome.insert(tmp->getDat());
            if(!operators.isEmpty() && isFuntion(operators.search())){
                outcome.insert(operators.search());
                operators.eraser();
            }
        }
        tmp = tmp->getNext();
    }
////////////////////////////////////////
    if(isOperator(tmp->getDat()) || isFuntion(tmp->getDat())){
        int current = precedencia(tmp->getDat());
        int st = 0;
        operators.isEmpty()? st =0 : st= precedencia(operators.search());
        while( !operators.isEmpty() &&
        st > current && !isFuntion(operators.search())){
            outcome.insert(operators.search());
            operators.eraser();
            operators.isEmpty()? st =0 : st= precedencia(operators.search());
        }
        operators.insert(tmp->getDat());
    }else if (tmp->getDat() =="("){
        operators.insert(tmp->getDat());
    }else if (tmp->getDat() == ")"){
        while(operators.search() != "("){
            outcome.insert(operators.search());
            operators.eraser();
        }
        operators.eraser();
    }else{
        outcome.insert(tmp->getDat());
        if(!operators.isEmpty() && isFuntion(operators.search())){
            outcome.insert(operators.search());
            operators.eraser();
        }
    }
/////////////////////////////////////////
    while (!operators.isEmpty())
    {
        outcome.insert(operators.search());
        operators.eraser();
    }
    return outcome;
}

double operateBinary(double left, double right, std::string operators){
    if(operators == "+"){
        return left + right;
    }else if(operators == "-"){
        return left - right;
    }else if(operators == "*"){
        return left * right;
    }else if(operators == "/"){
        return left / right;
    }else if(operators == "^"){
        return pow(left,right);
    }else
        return 0;
}

double operateUnary(double operand, std::string fun){
    if(fun == "sin"){
        return sin(operand);
    }else if(fun == "cos"){
        return cos(operand);
    }else if(fun == "tan"){
        return tan(operand);
    }else if(fun == "exp"){
        return exp(operand);
    }else if(fun == "log"){
        return log(operand);
    }else
        return 0;
}

double calculateReversePolac(Tree<std::string> str){
    Tree<double> operands;
    Node<std::string>* tmp = str.getRoot();
    do{
        if(!isOperator(tmp->getDat()) && !isFuntion(tmp->getDat())){
            operands.insert(std::stod(tmp->getDat()));
        }
        else if(isOperator(tmp->getDat())){
            double right = operands.search();
            operands.eraser();
            double left = operands.search();
            operands.eraser();
            operands.insert(operateBinary(left, right,tmp->getDat()));
        }else if(isFuntion(tmp->getDat())){
            double operand = operands.search();
            operands.eraser();
            operands.insert(operateUnary(operand,tmp->getDat()));
        }
        tmp = tmp->getNext();
    }while(tmp->getNext() != nullptr);
    if(isOperator(tmp->getDat())){
        double right = operands.search();
        operands.eraser();
        double left = operands.search();
        operands.eraser();
        operands.insert(operateBinary(left, right,tmp->getDat()));
    }else if(isFuntion(tmp->getDat())){
        double operand = operands.search();
        operands.eraser();
        operands.insert(operateUnary(operand,tmp->getDat()));
    }
    return operands.search();
}

std::string inToPre(Tree<std::string> str){
    if( str.getSize() == 0 )  // end condtion to stop recursion
        return "";

    Node<std::string>* tmp = str.getLast();
    std::string tmpString = tmp->getDat();
    str.eraser();
    return tmpString + " " + inToPre(str);
}

std::string getStringOperator(std::string op){
    if(op == "+"){
        return "suma";
    }else if(op == "-"){
        return "resta";
    }else if(op == "*"){
        return "multiplicacion";
    }else if(op == "/"){
        return "division";
    }else if(op == "^"){
        return "potenciacion";
    }else
        return "";
}

std::string postToFuntional(Tree<std::string> str){
    Tree<std::string> operands;
    Node<std::string>* tmp = str.getRoot();
    std::string outcome = "";
    do{
        if(!isOperator(tmp->getDat()) && !isFuntion(tmp->getDat())){
            operands.insert(tmp->getDat());
        }
        else if(isOperator(tmp->getDat())){
            std::string right;
            operands.search() == outcome ? right = outcome : right = operands.search();
            operands.eraser();
            std::string left;
            operands.search() == outcome ? left = outcome : left = operands.search();
            operands.eraser();
            // operands.push_(operateBinary(left, right,tmp->getDat()));
            outcome = getStringOperator(tmp->getDat()) + "(" + left + ", " + right + ")";
            operands.insert(outcome);
        }else if(isFuntion(tmp->getDat())){
            std::string operand;
            operands.search() == outcome ? operand = outcome : operand = operands.search();
            operands.eraser();
            // operands.push_(operateUnary(operand,tmp->getDat()));
            outcome = tmp->getDat() + "(" + operand + ")";
            operands.insert(outcome);
        }
        tmp = tmp->getNext();
    }while(tmp->getNext() != nullptr);
    if(isOperator(tmp->getDat())){
        std::string right;
        operands.search() == outcome ? right = outcome : right = operands.search();
        operands.eraser();
        std::string left;
        operands.search() == outcome ? left = outcome : left = operands.search();
        operands.eraser();
        // operands.push_(operateBinary(left, right,tmp->getDat()));
        outcome = getStringOperator(tmp->getDat()) + "(" + left + ", " + right + ")";
        operands.insert(outcome);
    }else if(isFuntion(tmp->getDat())){
        std::string operand;
        operands.search() == outcome ? operand = outcome : operand = operands.search();
        operands.eraser();
        // operands.push_(operateUnary(operand,tmp->getDat()));
        outcome = tmp->getDat() + "(" + operand + ")";
        operands.insert(outcome);
    }
    return outcome;
}

bool validate(Tree<std::string> str){
    bool flag = false;
    Tree<std::string> operators;
    Tree<std::string> outcome;
    Node<std::string>* tmp = str.getRoot();
    int pi=0;
    int pj=0;
    int nops=0;
    int nfun=0;
    int nopnd=0;
    while(tmp->getNext() != nullptr){
        if(isOperator(tmp->getDat()) || isFuntion(tmp->getDat())){
            int current = precedencia(tmp->getDat());
            int st = 0;
            operators.isEmpty()? st =0 : st= precedencia(operators.search());
            bool aux;
            operators.isEmpty()? aux = false : aux = !isFuntion(operators.search());
            while( !operators.isEmpty() &&
            st > current && !isFuntion(tmp->getDat())){
                outcome.insert(operators.search());
                operators.eraser();
                operators.isEmpty()? st =0 : st= precedencia(operators.search());
            }
            operators.insert(tmp->getDat());
            isFuntion(tmp->getDat())? nfun++: nops++;//
        }else if (tmp->getDat() =="("){
            operators.insert(tmp->getDat());
            pi++;
        }else if (tmp->getDat() == ")"){
            while(operators.search() != "("){
                outcome.insert(operators.search());
                operators.eraser();
                nops--;
                nopnd--;
            }
            operators.eraser();
            if(!operators.isEmpty() && isFuntion(operators.search())){
                outcome.insert(operators.search());
                operators.eraser();
            }

            pj++;
        }else{
            outcome.insert(tmp->getDat());
            if(!operators.isEmpty() && isFuntion(operators.search())){
                outcome.insert(operators.search());
                operators.eraser();
            }
            nopnd++;
        }
        tmp = tmp->getNext();
    }
////////////////////////////////////////
    if(isOperator(tmp->getDat()) || isFuntion(tmp->getDat())){
        int current = precedencia(tmp->getDat());
        int st = 0;
        operators.isEmpty()? st =0 : st= precedencia(operators.search());
        while( !operators.isEmpty() &&
        st > current && !isFuntion(operators.search())){
            outcome.insert(operators.search());
            operators.eraser();
            operators.isEmpty()? st =0 : st= precedencia(operators.search());
        }
        operators.insert(tmp->getDat());
        isFuntion(tmp->getDat())? nfun++: nops++;//
    }else if (tmp->getDat() =="("){
        operators.insert(tmp->getDat());
        pi++;
    }else if (tmp->getDat() == ")"){
        while(operators.search() != "("){
            outcome.insert(operators.search());
            operators.eraser();
            nops--;
            nopnd--;
        }
        operators.eraser();
        pj++;
    }else{
        outcome.insert(tmp->getDat());
        if(!operators.isEmpty() && isFuntion(operators.search())){
            outcome.insert(operators.search());
            operators.eraser();
        }
        nopnd++;
    }
/////////////////////////////////////////
    while (!operators.isEmpty())
    {
        outcome.insert(operators.search());
        operators.eraser();
    }
    if(pi != pj){
        std::cout<<"\nlos parentesis no estan bien cerrados"<<std::endl;
        flag = false;
    }
    if(nopnd ==( nops+1)){
        std::cout<<"\nLa funcion esta bien ingresada"<<std::endl;
        flag = true;
    }else{
        std::cout<<"\nLa funcion no esta bien balanceada entre operadores unarios y binarios"<<std::endl;
        std::cout<<nops<<" "<<nopnd<<std::endl;
        flag = false;
    }

    return flag;
}

Tree<std::string> getNumeros(std::string chain){
    char* str = new char;
    std::strcpy(str,chain.c_str());
    Tree<std::string> outcome;
    int i = 0;
    while(*(str + i) != '\0'){
        if(!isReal(*(str+i))){
            if(isOperator(*(str+i))){
                // outcome.push_(chain.substr(i,1));
            }else if(*(str+i) !='(' && *(str+i) !=')'){
                int j = i;
                while(!isReal(*(str+i)) && *(str+i) != '('){
                    i++;
                }
                // outcome.push_(chain.substr(j,i-j));
                i--;
            }else if(*(str+i) =='(' || *(str+i) ==')'){
                // outcome.push_(chain.substr(i,1));
            }
            else{
                i++;
                continue;
            }
        }else{
            int k = i;
            while (isReal(*(str+i))){
                i++;
            }
            outcome.insert(chain.substr(k,i-k));
            i--;
        }
        i++;
    }
    return outcome;
}