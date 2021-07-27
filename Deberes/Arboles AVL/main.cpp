/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebasti�n Jim�nez, Lizzete Zapata, Nicole Lara y Dalton Arevalo 
Fecha de creaci�n: 16/07/2021
Fecha de modificaci�n:22/07/2021
Ingenier�a de Software
Estructura de Datos*/
#include<iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "ArbolAVL.h"
#include "Menu.h"
#include "Color.h"

using namespace std;

int main(int argc, char** argv){
    ArbolAVL<int> t;
    Menu menu;
    int opcion = 0, value = 0;
    
    string mainMenu[] = { "Ingresar dato","Eliminar","Ver Arbol","Salir" };
    
    
    do{ 
    	opcion = menu.makeMenu("Programa para ArbolesAVL",mainMenu,4);
    	switch (opcion)
    	
        {
        	
        	case 1:
			{
				//Insertar
        		system("cls");
        		std::cout<<ansi::reset<<"\n\n"<<std::right<<std::setw(40)<<" Ingrese un numero entero: ";
        		std::cin>>value;
        		t.insert(value);
        		system("pause");
				break;
			}
        	case 2:
			{
				//Eliminar
				system("cls");
        		std::cout<<std::right<<std::setw(20)<<" Ingrese un numero entero...\n"<<std::endl;
        		std::cin>>value;
        		t.remove(value);
        		system("pause");
				break;	
			}
			case 3:
			{
				//Mostrar
				system("cls");
				
				std::cout<<ansi::reset<<std::left<<std::setw(40)<<" \nMostrando en inorder ... \n"<<std::endl;
		
    			t.inorder();
				system("pause");
				break;	
			}
			default:
				break;	
        }
    	
    	
	} while (opcion > 0 && opcion < 4);
    
    
    return EXIT_SUCCESS;
}

