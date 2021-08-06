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
/**
 * @brief Construct a new Menu object
 * 
 */
    Menu();
    /**
     * @brief Construct a new Menu object
     * 
     * @param title 
     */
    Menu(std::string title);
    /**
     * @brief add_option Donde se agrega la opcion
     * 
     * @param option 
     */
    void add_option(MenuOption option);
    /**
     * @brief remove_option Remover la opcion
     * 
     * @param index 
     */
    void remove_option(int index);
    /**
     * @brief display Es la pantalla de la consola 
     * 
     */
    void display();
    /**
     * @brief stop Donde se para el cursor
     * 
     */
    void stop();
    /**
     * @brief is_running donde empieza a correr el menu dinamico
     * 
     * @return true 
     * @return false 
     */
    bool is_running();

private:
/**
 * @brief string del titulo
 * 
 */
    std::string title;
    /**
     * @brief vestor para el menu de opciones
     * 
     */
    std::vector<MenuOption> options;
    /**
     * @brief consola  
     * 
     */
    HANDLE console;
    /**
     * @brief running correr la consola
     * 
     */
    bool running = false;
};
