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
/**
 * @brief usuario Indica la estructura para el login
 * 
 */
struct usuario{
    string nombre;
    string contrasenia;
} personas[100];
/**
 * @brief ingresar Aqui se ingresa el usuario
 * @return No retorna nada por void 
 * 
 */
void ingresar();
/**
 * @brief Mostrar Muestra la funcion del usuario y la contrasenia
 * 
 * @return int 
 */
int mostrar();
/**
 * @brief quitar_usuario Es la funcion donde hay la funcion ingresar del login
 * 
 * @return int 
 */
int quitar_usuario(int);
/**
 * @brief get_instance getter de la instancia 
 * 
 * @return Application& 
 */
Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}
/**
 * @brief run para la aplicacion 
 * @return No Retorna nada por la funcion void 
 * 
 */
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
/**
 * @brief add_option agregar la opcion y los getter de los numeros
 * 
 */
    menu.add_option(MenuOption("Imprimir arbol", [&](MenuOptionArguments args) {
        Tree<std::string> aux;
        aux = getNumeros(str);
        aux.forEach([&](Node<std::string>* nod, int index){
            std::cout<<nod->getDat()<<" ";
        });
    }));
/**
 * @brief add_option sirve para salir del programa  
 * 
 */
    menu.add_option(MenuOption("Salir", [&](MenuOptionArguments args) {
        std::cout << "Salio con exito del programa..." << std::endl;
        menu.stop();
    }, false));

    menu.display(); 
}
/**
 * @brief ingresar Se ingresa el login
 * @return No retorna nada por la funcion void 
 * 
 */
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
/**
 * @brief mostrar El usuario y la contrasenia
 * 
 * @return int 
 */
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
/**
 * @brief quitar_usuario Donde se si ingresa mal el login no ingresa
 * 
 * @param usuario1 
 * @return int 
 */
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