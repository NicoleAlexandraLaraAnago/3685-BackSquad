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
#include <iostream>
#include <SFML/Graphics.hpp>
#include "stack.h"
#include <string>
#include "opstr.h"
#include "opstack.h"
#include "tnode.h"
#include "opstree.h"

int main(int, char**) {
    std::cout << "Programa para cambiar notacion prefija, postfija y funcional\n";
    std::cout << "Ingrese una expresion matematica" <<std::endl;
    std::string str;
    std::getline(std::cin, str);
    Stack<std::string> st;
    st = inToStack(str);
    // st.forEach([&](Node<std::string>* nod, int index){
    //     std::string aux = nod->getDat();
    //     std::cout<< aux<<std::endl;
    // });
    std::cout<<"Orden postfijo: ";
    Stack<std::string> pf;
    Stack<std::string> pre;
    Stack<std::string> fun;
    Stack<std::string> tree;
    fun = inToPost(st);
    pf = inToPost(st);
    pre = inToPost(st);
    tree = inToPost(st);
    pf.forEach([&](Node<std::string>* nod, int index){
        std::cout<<nod->getDat()<<" ";
    });
    std::cout<<"\n";
    std::cout<<"Notacion prefija: " << inToPre(pre)<<std::endl;
    std::cout<<"Notacion funcional: "<< postToFuntional(fun)<< std::endl;
    std::cout<<"Resultado: "<< calculateReversePolac(pf) <<std::endl;
    
    std::cout<<" "<<std::endl;

    auto test = generateTree(tree);
    
    
    system("pause");
}
