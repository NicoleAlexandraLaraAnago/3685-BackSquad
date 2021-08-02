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
#include <string>
#include <cstring>
#include <iostream>

void strToList(Stack<char> &lst, std::string str){
    //char* cadena = new char[str.length() + 1];
    char* cadena = new char;
    std::strcpy(cadena,str.c_str());
    int i =0;
    while(*(cadena+i) != '\0'){
        if(*(cadena+i) != ' '){
            lst.push_(*(cadena+i));
        }
        i++;
    }
}

void operatorToList(Stack<char> &lst, std::string str){
    //char* cadena = new char[str.length() + 1];
    char* cadena = new char;
    std::strcpy(cadena,str.c_str());
    int i =0;
    while(*(cadena+i) != '\0'){
        if(*(cadena+i) != ' ' &&
        (*(cadena+i) == '+' || *(cadena+i) =='-' ||
        *(cadena+i) == '*' || *(cadena+i) == '/')){
            lst.push_(*(cadena+i));
        }
        i++;
    }
}

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperator(std::string c){
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^");
}

int precedencia(char c){
    return (c == '+' || c == '-') ? 1 :
    (c == '*' || c == '/') ? 2 :
    (c == '^') ? 3 : 0;
}

std::string infijoToPostfijo(std::string str){
    std::string resultado;
    char *cadena = new char;
    std::strcpy(cadena,str.c_str());
    Stack<char> operadores;
    int i =0;
    while(*(cadena + i) != '\0'){
        if (isOperator(*(cadena + i))){
            char aux = *(cadena+i);
            int current = precedencia(aux);
            int st = 0;
            operadores.isEmpty()? st =0 : st= precedencia(operadores.peak());
            while( !operadores.isEmpty() &&
            st > current){
                resultado += operadores.peak();
                operadores.pop();
            }
            operadores.push_(*(cadena+i));
        }else if(*(cadena+i) == '('){
            operadores.push_(*(cadena+i));
        }else if (*(cadena+i) == ')'){
            while(operadores.peak() != '('){
                resultado += operadores.peak();
                operadores.pop();
            }
            operadores.pop();
        }else{
            resultado += *(cadena +i);
        }
        i++;
    }
    while (!operadores.isEmpty())
    {
        resultado += operadores.peak();
        operadores.pop();
    }
    return resultado;
}

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


std::string infijoToFuncional(std::string str){
    std::string resultado;
    std::string util = "";
    char *cadena = new char;
    std::strcpy(cadena,str.c_str());
    Stack<char> operadores;
    int i =0;
    int j = 0;
    int x = 0;
    char *z = new char;
    while(*(cadena + i) != '\0'){
        if (isOperator(*(cadena + i))){
            char aux = *(cadena+i);
            int current = precedencia(aux);
            int st = 0;
            operadores.isEmpty()? st =0 : st= precedencia(operadores.peak());
            while( !operadores.isEmpty() &&
            st > current){
                util += operatorToFunction(operadores.peak()) + "(" + *(z+x) + ", ";
                //util += operadores.peak();
                operadores.pop();
                x++;
            }
            operadores.push_(*(cadena+i));
            j++;
        }else if(*(cadena+i) == '('){
            operadores.push_(*(cadena+i));
        }else if (*(cadena+i) == ')'){
            while(operadores.peak() != '('){
                util += operatorToFunction(operadores.peak()) + "(" + *(z+x) + ", ";
                
                operadores.pop();
                x++;
            }
            operadores.pop();
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
        util = operatorToFunction(operadores.peak()) + "(" + *(var +w-1) + ", "+ util;
        //resultado += operadores.peak();
        operadores.pop();
        w--;
        j++;
    }
    util += *(var +resultado.length()-1);
    for(int k =0; k<j; k++){
        util += ')';
    }
    return util;
}

std::string infijoToPrefijo(std::string str){
    if( str.length() == 0 )  // end condtion to stop recursion
        return "";

    std::string last(1,str[str.length()-1]);  // create string with last character
    std::string reversed = infijoToPrefijo(str.substr(0,str.length()-1));
    return last+reversed; // Make he last character first
}