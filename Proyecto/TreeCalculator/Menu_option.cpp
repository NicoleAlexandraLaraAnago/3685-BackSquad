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

#include "Menu_option.h"

MenuOption::MenuOption(std::string label, MenuOptionCallback callback) {
    this->label = label;
    this->callback = callback;
}

MenuOption::MenuOption(std::string label, MenuOptionCallback callback, bool wait_after_exec) {
    this->label = label;
    this->callback = callback;
    this->wait_after_exec = wait_after_exec;
}

MenuOption::MenuOption(std::string label, MenuOptionCallback callback, MenuOptionArguments arguments) {
    this->label = label;
    this->callback = callback;
    this->arguments = arguments;
}

MenuOption::MenuOption(std::string label, MenuOptionCallback callback, MenuOptionArguments arguments, bool wait_after_exec) {
    this->label = label;
    this->callback = callback;
    this->arguments = arguments;
    this->wait_after_exec = wait_after_exec;
}

std::string MenuOption::get_label() {
    return label;
}

void MenuOption::execute() {
    callback(arguments);
}

bool MenuOption::should_wait() {
    return wait_after_exec;
}

MenuOptionArguments &MenuOption::get_args() {
    return arguments;
}