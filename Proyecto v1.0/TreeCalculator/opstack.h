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
#include "tree.h"
#include "opstr.h"
#include <math.h>
#include <string>
#include <cstring>
#include <iostream>

// bool isOperator(char c){
//     return (c == '+' || c == '-' || c == '*' || c == '/');
// }
/**
 * @brief isReal Indica para saber si es real el numero
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool isReal(char c){
    return (c == '0' || c == '1' || c == '2' || c == '3' || c == '4'
    || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '.');
}
/**
 * @brief isReal Indica para saber si es real el numero
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool isReal(std::string c){
    return (c == "0" || c == "1" || c == "2" || c == "3" || c == "4"
    || c == "5" || c == "6" || c == "7" || c == "8" || c == "9" || c == ".");
}
/**
 * @brief precedencia Indica la jerarquia de los operadores  
 * 
 * @param c 
 * @return int 
 */
int precedencia(std::string c){
    return (c == "+" || c == "-") ? 1 :
    (c == "*") ? 2 :
    (c == "/") ? 3 :
    (c == "^") ? 4 : 0;
}
/**
 * @brief is Funtion Es la funcion para la jerarquia de las funciones trigonometricas  
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool isFuntion(std::string c){
    return (c == "sin" || c == "cos" || c == "tan" || c == "exp" || c == "log");
}
/**
 * @brief inToStack Es para ingresar a la pila 
 * 
 * @param chain 
 * @return Tree<std::string> 
 */
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
/**
 * @brief inToPost Esta ubicado en post orden
 * 
 * @param str 
 * @return Tree<std::string> 
 */
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
/**
 * @brief operateBinary Indica la operacion binaria de los operadores matematicos 
 * 
 * @param left 
 * @param right 
 * @param operators 
 * @return double 
 */
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
/**
 * @brief operateUnary Inidca los operadores como el exponencial y exponencial 
 * 
 * @param operand 
 * @param fun 
 * @return double 
 */
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
/**
 * @brief calculateReversePolac Calcula la calculadora polaca  
 * 
 * @param str 
 * @return double 
 */
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
/**
 * @brief inToPre Indica en preorden 
 * 
 * @param str 
 * @return std::string 
 */
std::string inToPre(Tree<std::string> str){
    if( str.getSize() == 0 )  // end condtion to stop recursion
        return "";

    Node<std::string>* tmp = str.getLast();
    std::string tmpString = tmp->getDat();
    str.eraser();
    return tmpString + " " + inToPre(str);
}
/**
 * @brief Get the String Operator object
 * 
 * @param op 
 * @return std::string 
 */
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
/**
 * @brief postToFuntional Indica la post Funcional
 * 
 * @param str 
 * @return std::string 
 */
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
/**
 * @brief validate Indica la validacion de la expresion matematica 
 * 
 * @param str 
 * @return true 
 * @return false 
 */
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
/**
 * @brief Get the Numeros object
 * 
 * @param chain 
 * @return Tree<std::string> 
 */
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