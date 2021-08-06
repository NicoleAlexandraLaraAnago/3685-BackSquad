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
#include "Menu_option.h"
/**
 * @brief Construct a new Menu Option:: Menu Option object
 * 
 * @param label 
 * @param callback 
 */
MenuOption::MenuOption(std::string label, MenuOptionCallback callback) {
    this->label = label;
    this->callback = callback;
}
/**
 * @brief Construct a new Menu Option:: Menu Option object
 * 
 * @param label 
 * @param callback 
 * @param wait_after_exec 
 */
MenuOption::MenuOption(std::string label, MenuOptionCallback callback, bool wait_after_exec) {
    this->label = label;
    this->callback = callback;
    this->wait_after_exec = wait_after_exec;
}
/**
 * @brief Construct a new Menu Option:: Menu Option object
 * 
 * @param label 
 * @param callback 
 * @param arguments 
 */
MenuOption::MenuOption(std::string label, MenuOptionCallback callback, MenuOptionArguments arguments) {
    this->label = label;
    this->callback = callback;
    this->arguments = arguments;
}
/**
 * @brief Construct a new Menu Option:: Menu Option object
 * 
 * @param label 
 * @param callback 
 * @param arguments 
 * @param wait_after_exec 
 */
MenuOption::MenuOption(std::string label, MenuOptionCallback callback, MenuOptionArguments arguments, bool wait_after_exec) {
    this->label = label;
    this->callback = callback;
    this->arguments = arguments;
    this->wait_after_exec = wait_after_exec;
}
/**
 * @brief MenuOption Donde se ve el menu de opciones
 * 
 * @return std::string 
 */
std::string MenuOption::get_label() {
    return label;
}

void MenuOption::execute() {
    callback(arguments);
}
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool MenuOption::should_wait() {
    return wait_after_exec;
}
/**
 * @brief &MenuOption
 * 
 * @return MenuOptionArguments& 
 */
MenuOptionArguments &MenuOption::get_args() {
    return arguments;
}