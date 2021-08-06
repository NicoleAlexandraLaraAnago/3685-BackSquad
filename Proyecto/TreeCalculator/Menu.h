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
#include "Menu_option.h"
#include <iostream>
#include <vector>
#include <windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 77
#define KEY_RIGHT 75
#define KEY_ENTER 13
#define KEY_ESCAPE 27

class Menu {
public:
    Menu();
    Menu(std::string title);
    void add_option(MenuOption option);
    void remove_option(int index);
    void display();
    void stop();
    bool is_running();

private:
    std::string title;
    std::vector<MenuOption> options;
    HANDLE console;
    bool running = false;
};
