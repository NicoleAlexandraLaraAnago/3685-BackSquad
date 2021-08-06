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
#include <string>
#include <cstring>
#include <iostream>
/**
 * @brief strToLis Se usa para la lista  de los arboles 
 * 
 * @param lst 
 * @param str 
 */
void strToList(Tree<char> &lst, std::string str){
    //char* cadena = new char[str.length() + 1];
    char* cadena = new char;
    std::strcpy(cadena,str.c_str());
    int i =0;
    while(*(cadena+i) != '\0'){
        if(*(cadena+i) != ' '){
            lst.insert(*(cadena+i));
        }
        i++;
    }
}
/**
 * @brief operatorToLis Indica los operadores basicos 
 * 
 * @param lst 
 * @param str 
 */
void operatorToList(Tree<char> &lst, std::string str){
    //char* cadena = new char[str.length() + 1];
    char* cadena = new char;
    std::strcpy(cadena,str.c_str());
    int i =0;
    while(*(cadena+i) != '\0'){
        if(*(cadena+i) != ' ' &&
        (*(cadena+i) == '+' || *(cadena+i) =='-' ||
        *(cadena+i) == '*' || *(cadena+i) == '/')){
            lst.insert(*(cadena+i));
        }
        i++;
    }
}
/**
 * @brief isOperator Para saber si es operador  
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
/**
 * @brief isOperator Para saber si es operador 
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool isOperator(std::string c){
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^");
}
/**
 * @brief precdencia Jerarquia de los operadores 
 * 
 * @param c 
 * @return int 
 */
int precedencia(char c){
    return (c == '+' || c == '-') ? 1 :
    (c == '*' || c == '/') ? 2 :
    (c == '^') ? 3 : 0;
}
/**
 * @brief infijoToPostfijo Recorre de infijo a postfijo
 * 
 * @param str 
 * @return std::string 
 */
std::string infijoToPostfijo(std::string str){
    std::string resultado;
    char *cadena = new char;
    std::strcpy(cadena,str.c_str());
    Tree<char> operadores;
    int i =0;
    while(*(cadena + i) != '\0'){
        if (isOperator(*(cadena + i))){
            char aux = *(cadena+i);
            int current = precedencia(aux);
            int st = 0;
            operadores.isEmpty()? st =0 : st= precedencia(operadores.search());
            while( !operadores.isEmpty() &&
            st > current){
                resultado += operadores.search();
                operadores.eraser();
            }
            operadores.insert(*(cadena+i));
        }else if(*(cadena+i) == '('){
            operadores.insert(*(cadena+i));
        }else if (*(cadena+i) == ')'){
            while(operadores.search() != '('){
                resultado += operadores.search();
                operadores.eraser();
            }
            operadores.eraser();
        }else{
            resultado += *(cadena +i);
        }
        i++;
    }
    while (!operadores.isEmpty())
    {
        resultado += operadores.search();
        operadores.eraser();
    }
    return resultado;
}
/**
 * @brief operatorToFunction Operador para la funcional
 * 
 * @param c 
 * @return std::string 
 */
std::string operatorToFunction(char c){
    if (c == '+')
        return "suma";
    if (c == '-')
        return "resta";
    if (c == '*')
        return "multiplicacion";
    if (c == '/')
        return "division";
    else
        return " ";
}
/**
 * @brief infijoToFuncional Infijo para la funcional 
 * 
 * @param str 
 * @return std::string 
 */

std::string infijoToFuncional(std::string str){
    std::string resultado;
    std::string util = "";
    char *cadena = new char;
    std::strcpy(cadena,str.c_str());
    Tree<char> operadores;
    int i =0;
    int j = 0;
    int x = 0;
    char *z = new char;
    while(*(cadena + i) != '\0'){
        if (isOperator(*(cadena + i))){
            char aux = *(cadena+i);
            int current = precedencia(aux);
            int st = 0;
            operadores.isEmpty()? st =0 : st= precedencia(operadores.search());
            while( !operadores.isEmpty() &&
            st > current){
                util += operatorToFunction(operadores.search()) + "(" + *(z+x) + ", ";
                //util += operadores.peak();
                operadores.eraser();
                x++;
            }
            operadores.insert(*(cadena+i));
            j++;
        }else if(*(cadena+i) == '('){
            operadores.insert(*(cadena+i));
        }else if (*(cadena+i) == ')'){
            while(operadores.search() != '('){
                util += operatorToFunction(operadores.search()) + "(" + *(z+x) + ", ";
                
                operadores.eraser();
                x++;
            }
            operadores.eraser();
        }else{
            resultado += *(cadena +i);
            std::strcpy(z,resultado.c_str());
        }
        i++;
    }
    int w = j;
    //int found = resultado.find_last_of("+-*/");
    //std::string res =resultado.substr(found+1);
    char* var = new char;
    std::strcpy(var, resultado.c_str());
    //util += operatorToFunction(operadores.peak()) + "(" + *(var +j-1) + ", " + *(var +j) +")";
    while (!operadores.isEmpty() && *(var + w) != '\0')
    {
        util = operatorToFunction(operadores.search()) + "(" + *(var +w-1) + ", "+ util;
        //resultado += operadores.peak();
        operadores.eraser();
        w--;
        j++;
    }
    util += *(var +resultado.length()-1);
    for(int k =0; k<j; k++){
        util += ')';
    }
    return util;
}
/**
 * @brief infijoToPrefijo Se recorre de infijo a prefijo
 * 
 * @param str 
 * @return std::string 
 */
std::string infijoToPrefijo(std::string str){
    if( str.length() == 0 )  // end condtion to stop recursion
        return "";

    std::string last(1,str[str.length()-1]);  // create string with last character
    std::string reversed = infijoToPrefijo(str.substr(0,str.length()-1));
    return last+reversed; // Make he last character first
}