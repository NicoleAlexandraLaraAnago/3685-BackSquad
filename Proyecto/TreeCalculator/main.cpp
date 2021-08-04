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
 #define BACKSPACE 8
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#define USUARIO "user1"
#define PASSWORD "500"
#define SUPER "BackSquad"
#define PASS "SOFTWARE"
#define ENTER 13
#include <iostream>
//#include <SFML/Graphics.hpp>
#include "stack.h"
#include <string>
#include "opstr.h"
#include "opstack.h"
#include "tnode.h"
#include "opstree.h"

using namespace std;
struct usuario
{
    string nombre;
    string contrasenia;
} personas[100];

int main(int, char**) {
	
	    string usuario, password;

    int cont = 0;
    bool ingresa = false;

    do
    {
        system("cls");
      
	cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	cout<<"\n||||                                                                      ||||\n";
	cout<<  "||||              UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                 ||||";
	cout<<"\n||||                       ESTRUCTURA DE DATOS                            ||||";
	cout<<"\n||||INTEGRANTES: STALIN RIVERA,NICOLE LARA,Diego Jimenez                  ||||";
	cout<<"\n||||                            NRC: 3685                                 ||||";
	cout<<"\n||||                                                                      ||||";
	cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n\n\n";
        cout << "\n\n\tIngrese el Usuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tClave: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            caracter = getch();
        }

        if (usuario == SUPER && password == PASS)
        {
            ingresa = true;
        }
        else
        {

        }
    } while (ingresa == false && cont < 3);

    if (ingresa == false)
    {
        cout << "\n\tPor varios errores, el sistema se cerrara en cualquier momento \n";
    }
    else if (usuario == "BackSquad" && password == "SOFTWARE")
    {
        cout << "\n\n\tSea Bienvenido\n\n";
        system("pause");
    }
	
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
    cin.get();
    return 0;
}

int mostrar()
{
    for (int i = 0; i < 100; i++)
    {
        if (personas[i].contrasenia != "")
        {
            cout << personas[i].nombre << endl;
            cout << personas[i].contrasenia << endl;
        }
    }
}

int quitar_usuario(int usuario1)
{
    for (int i = 0; i < 100; i++)
    {
        if (usuario1 == i)
        {
            personas[usuario1].nombre = " ";
            personas[usuario1].contrasenia = " ";
        }
    }
}
