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

#define BACKSPACE 8
#define USUARIO "user1"
#define PASSWORD "500"
#define SUPER "BackSquad"
#define PASS "SOFTWARE"
#define ENTER 13

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <iostream>

#include "tree.h"
#include "opstr.h"
#include "opstack.h"
#include "tnode.h"
#include "opstree.h"
#include "Aplicacion.h"
#include "Menu.h"
#include "Menu_option.h"

using namespace std;

struct usuario{
    string nombre;
    string contrasenia;
} personas[100];

void ingresar();
int mostrar();
int quitar_usuario(int);

Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}

void Application::run() {
    ingresar();

    Menu menu("App Calculadora - AB");

    std::cout << "Ingrese una expresion matematica: ";
        std::string str;
        std::getline(std::cin, str);
        Tree<std::string> st;
        st = inToStack(str);

    menu.add_option(MenuOption("Mostrar Expresion", [&](MenuOptionArguments args) {
        if(validate(st)){
            std::cout << "La funcion es correcta" << std::endl;
            std::cout<<"Orden postfijo (Posorden): ";
            Tree<std::string> pf;
            Tree<std::string> pre;
            Tree<std::string> fun;
            Tree<std::string> tree;
            fun = inToPost(st);
            pf = inToPost(st);
            pre = inToPost(st);
            tree = inToPost(st);
            pf.forEach([&](Node<std::string>* nod, int index){
                std::cout<<nod->getDat()<<" ";
            });
            std::cout<<"\n";
            std::cout<<"Notacion prefija: " << inToPre(pre)<<std::endl;
            std::cout<<"Notacion prefija: " << str <<std::endl;
            std::cout<<"Notacion funcional: "<< postToFuntional(fun)<< std::endl;
            std::cout<<"Resultado: "<< calculateReversePolac(pf) <<std::endl;
            std::cout<<" "<<std::endl;
            auto test = generateTree(tree);
        }else{
            std::cout << "La funcion no es correcta!!!" << std::endl;
        }
    }));

    menu.add_option(MenuOption("Imprimir arbol", [&](MenuOptionArguments args) {
        Tree<std::string> aux;
        aux = getNumeros(str);
        std::cout << "Recorrido: ";
        aux.forEach([&](Node<std::string>* nod, int index){
            std::cout<<nod->getDat()<<" -> ";
        });

    }));

    menu.add_option(MenuOption("Salir", [&](MenuOptionArguments args) {
        std::cout << "Salio con exito del programa..." << std::endl;
        menu.stop();
    }, false));

    menu.display(); 
}

void ingresar(){
    string usuario, password;
    int cont = 0;
    bool ingresa = false;
    do{
        system("cls");
      
	    cout<<"\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	    cout<<"\n||||                                                                               ||||\n";
	    cout<<  "||||              UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                          ||||";
	    cout<<"\n||||                       ESTRUCTURA DE DATOS                                     ||||";
	    cout<<"\n||||  INTEGRANTES: DALTON AREVALO, STALIN RIVERA, DIEGO JIMENEZ, LIZZETE ZAPATA    ||||";
        cout<<"\n||||                          NICOLE LARA                                          ||||";
	    cout<<"\n||||                            NRC: 3685                                          ||||";
	    cout<<"\n||||                                                                               ||||";
	    cout<<"\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n\n\n";
        cout << "\n\n\tIngrese el Usuario: ";
        getline(cin, usuario);
        char caracter;
        cout << "\tClave: ";
        caracter = getch();
        password = "";
        while (caracter != ENTER){
            if (caracter != BACKSPACE){
                password.push_back(caracter);
                cout << "*";
            }
            caracter = getch();
        }

        if (usuario == SUPER && password == PASS){
            ingresa = true;
        }
    } while (ingresa == false && cont < 3);

    if (ingresa == false){
        cout << "\n\tPor varios errores, el sistema se cerrara en cualquier momento \n";
    }
    else if (usuario == "BackSquad" && password == "SOFTWARE"){
        cout << "\n\n\tSea Bienvenido\n\n";
        system("pause");
    }else{
        cout << "\n\n\tError!!!\n\n";
        system("pause");
    }
}

int mostrar(){
    for (int i = 0; i < 100; i++)
    {
        if (personas[i].contrasenia != "")
        {
            cout << personas[i].nombre << endl;
            cout << personas[i].contrasenia << endl;
        }
    }
}

int quitar_usuario(int usuario1){
    for (int i = 0; i < 100; i++)
    {
        if (usuario1 == i)
        {
            personas[usuario1].nombre = " ";
            personas[usuario1].contrasenia = " ";
        }
    }
}