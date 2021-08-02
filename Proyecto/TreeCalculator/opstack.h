/**      
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computacion
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: Convertir notacion infija a postfija, prefija y funcional
 * 
 * @date 05/07/2021
 * @author Diego Jimenez
 */
#pragma once 
#include "stack.h"
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

Stack<std::string> inToStack(std::string chain){
    char* str = new char;
    std::strcpy(str,chain.c_str());
    Stack<std::string> outcome;
    int i = 0;
    while(*(str + i) != '\0'){
        if(!isReal(*(str+i))){
            if(isOperator(*(str+i))){
                outcome.push_(chain.substr(i,1));
            }else if(*(str+i) !='(' && *(str+i) !=')'){
                int j = i;
                while(!isReal(*(str+i)) && *(str+i) != '('){
                    i++;
                }
                outcome.push_(chain.substr(j,i-j));
                i--;
            }else if(*(str+i) =='(' || *(str+i) ==')'){
                outcome.push_(chain.substr(i,1));
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
            outcome.push_(chain.substr(k,i-k));
            i--;
        }
        i++;
    }
    return outcome;
}

Stack<std::string> inToPost(Stack<std::string> str){
    Stack<std::string> operators;
    Stack<std::string> outcome;
    Node<std::string>* tmp = str.getCursor();
    while(tmp->getNext() != nullptr){
        if(isOperator(tmp->getDat()) || isFuntion(tmp->getDat())){
            int current = precedencia(tmp->getDat());
            int st = 0;
            operators.isEmpty()? st =0 : st= precedencia(operators.peak());
            bool aux;
            operators.isEmpty()? aux = false : aux = !isFuntion(operators.peak());
            while( !operators.isEmpty() &&
            st > current && !isFuntion(tmp->getDat())){
                outcome.push_(operators.peak());
                operators.pop();
                operators.isEmpty()? st =0 : st= precedencia(operators.peak());
            }
            operators.push_(tmp->getDat());
        }else if (tmp->getDat() =="("){
            operators.push_(tmp->getDat());
        }else if (tmp->getDat() == ")"){
            while(operators.peak() != "("){
                outcome.push_(operators.peak());
                operators.pop();
            }
            operators.pop();
            if(!operators.isEmpty() && isFuntion(operators.peak())){
                outcome.push_(operators.peak());
                operators.pop();
            }
        }else{
            outcome.push_(tmp->getDat());
            if(!operators.isEmpty() && isFuntion(operators.peak())){
                outcome.push_(operators.peak());
                operators.pop();
            }
        }
        tmp = tmp->getNext();
    }
////////////////////////////////////////
    if(isOperator(tmp->getDat()) || isFuntion(tmp->getDat())){
        int current = precedencia(tmp->getDat());
        int st = 0;
        operators.isEmpty()? st =0 : st= precedencia(operators.peak());
        while( !operators.isEmpty() &&
        st > current && !isFuntion(operators.peak())){
            outcome.push_(operators.peak());
            operators.pop();
            operators.isEmpty()? st =0 : st= precedencia(operators.peak());
        }
        operators.push_(tmp->getDat());
    }else if (tmp->getDat() =="("){
        operators.push_(tmp->getDat());
    }else if (tmp->getDat() == ")"){
        while(operators.peak() != "("){
            outcome.push_(operators.peak());
            operators.pop();
        }
        operators.pop();
    }else{
        outcome.push_(tmp->getDat());
        if(!operators.isEmpty() && isFuntion(operators.peak())){
            outcome.push_(operators.peak());
            operators.pop();
        }
    }
/////////////////////////////////////////
    while (!operators.isEmpty())
    {
        outcome.push_(operators.peak());
        operators.pop();
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

double calculateReversePolac(Stack<std::string> str){
    Stack<double> operands;
    Node<std::string>* tmp = str.getCursor();
    do{
        if(!isOperator(tmp->getDat()) && !isFuntion(tmp->getDat())){
            operands.push_(std::stod(tmp->getDat()));
        }
        else if(isOperator(tmp->getDat())){
            double right = operands.peak();
            operands.pop();
            double left = operands.peak();
            operands.pop();
            operands.push_(operateBinary(left, right,tmp->getDat()));
        }else if(isFuntion(tmp->getDat())){
            double operand = operands.peak();
            operands.pop();
            operands.push_(operateUnary(operand,tmp->getDat()));
        }
        tmp = tmp->getNext();
    }while(tmp->getNext() != nullptr);
    if(isOperator(tmp->getDat())){
        double right = operands.peak();
        operands.pop();
        double left = operands.peak();
        operands.pop();
        operands.push_(operateBinary(left, right,tmp->getDat()));
    }else if(isFuntion(tmp->getDat())){
        double operand = operands.peak();
        operands.pop();
        operands.push_(operateUnary(operand,tmp->getDat()));
    }
    return operands.peak();
}

std::string inToPre(Stack<std::string> str){
    if( str.getSize() == 0 )  // end condtion to stop recursion
        return "";

    Node<std::string>* tmp = str.getLast();
    std::string tmpString = tmp->getDat();
    str.pop();
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

std::string postToFuntional(Stack<std::string> str){
    Stack<std::string> operands;
    Node<std::string>* tmp = str.getCursor();
    std::string outcome = "";
    do{
        if(!isOperator(tmp->getDat()) && !isFuntion(tmp->getDat())){
            operands.push_(tmp->getDat());
        }
        else if(isOperator(tmp->getDat())){
            std::string right;
            operands.peak() == outcome ? right = outcome : right = operands.peak();
            operands.pop();
            std::string left;
            operands.peak() == outcome ? left = outcome : left = operands.peak();
            operands.pop();
            // operands.push_(operateBinary(left, right,tmp->getDat()));
            outcome = getStringOperator(tmp->getDat()) + "(" + left + ", " + right + ")";
            operands.push_(outcome);
        }else if(isFuntion(tmp->getDat())){
            std::string operand;
            operands.peak() == outcome ? operand = outcome : operand = operands.peak();
            operands.pop();
            // operands.push_(operateUnary(operand,tmp->getDat()));
            outcome = tmp->getDat() + "(" + operand + ")";
            operands.push_(outcome);
        }
        tmp = tmp->getNext();
    }while(tmp->getNext() != nullptr);
    if(isOperator(tmp->getDat())){
        std::string right;
        operands.peak() == outcome ? right = outcome : right = operands.peak();
        operands.pop();
        std::string left;
        operands.peak() == outcome ? left = outcome : left = operands.peak();
        operands.pop();
        // operands.push_(operateBinary(left, right,tmp->getDat()));
        outcome = getStringOperator(tmp->getDat()) + "(" + left + ", " + right + ")";
        operands.push_(outcome);
    }else if(isFuntion(tmp->getDat())){
        std::string operand;
        operands.peak() == outcome ? operand = outcome : operand = operands.peak();
        operands.pop();
        // operands.push_(operateUnary(operand,tmp->getDat()));
        outcome = tmp->getDat() + "(" + operand + ")";
        operands.push_(outcome);
    }
    return outcome;
}