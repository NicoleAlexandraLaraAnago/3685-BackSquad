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
#include <string>
#include <functional>
#include <vector>
#include <map>
#include <memory>

#ifndef __MENU_CLASSES_
#define __MENU_CLASSES_

class MenuOptionArgumentBase
{
public:
/**
 * @brief Destroy the Menu Option Argument Base object
 * Aqui se encuentra el destructor
 * 
 */
    virtual ~MenuOptionArgumentBase() = 0;
};
/**
 * @brief Destroy the Menu Option Argument Base:: Menu Option Argument Base object
 * 
 */
inline MenuOptionArgumentBase::~MenuOptionArgumentBase() {}

///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Aqui se usa el menu de opciones y los setter de la evaluacion
 * 
 * @tparam T 
 */
template <typename T>
class MenuOptionArgument : public MenuOptionArgumentBase {
public:
    typedef T Type;
    explicit MenuOptionArgument(const Type& value);
    Type get_value();
    void set_value(Type value);
private:
    Type value;
};
/**
 * @brief Construct a new Menu Option Argument< T>:: Menu Option Argument object Aui se usa el constructor de la opcion del argumento
 * 
 * @tparam T 
 * @param value 
 */
template <typename T>
MenuOptionArgument<T>::MenuOptionArgument(const T& value): value(value) {}
/**
 * @brief MenuOptionArgumen Indica la opcion del menu Argumento
 * 
 * @tparam T 
 * @return T 
 */
template <typename T>
T MenuOptionArgument<T>::get_value() {
    return value;
}
/**
 * @brief Indica los setter del valor
 * 
 * @tparam T 
 * @param value 
 */
template <typename T>
void MenuOptionArgument<T>::set_value(T value) {
    this->value = value;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

class MenuOptionArguments {
public:
/**
 * @brief Construct a new Menu Option Arguments object
 * 
 */
    MenuOptionArguments();
/**
 * @brief Se usa las llaves par el arbol
 * 
 * @tparam T 
 * @param key 
 * @param argument 
 */
    template <typename T>
    void add(std::string key, MenuOptionArgument<T> *argument);
/**
 * @brief Se usa las llaves y el valor con una pantilla
 * 
 * @tparam T 
 * @param key 
 * @param value 
 */
    template <typename T>
    void add(std::string key, T value);
/**
 * @brief Setter y getter de la llave
 * 
 * @tparam T 
 * @param key 
 * @return T 
 */
    template <typename T>
    T get(std::string key);
/**
 * @brief llave y valor
 * 
 * @tparam T 
 * @param key 
 * @param value 
 */
    template <typename T>
    void set(std::string key, T value);
/**
 * @brief tiene una llave
 * 
 * @param key 
 * @return true 
 * @return false 
 */
    bool has(std::string key);
private:
/**
 * @brief map Indica el Argumento
 * 
 */
    std::map<std::string, std::unique_ptr<MenuOptionArgumentBase>> *arguments;
};
/**
 * @brief Construct a new Menu Option Arguments:: Menu Option Arguments object
 * 
 */
inline MenuOptionArguments::MenuOptionArguments() {
    arguments = new std::map<std::string, std::unique_ptr<MenuOptionArgumentBase>>();
}
/**
 * @brief Aqui va el menu del agregar 
 * 
 * @tparam T 
 * @param key 
 * @param argument 
 */
template <typename T>
void MenuOptionArguments::add(std::string key, MenuOptionArgument<T> *argument) {
    (*arguments)[key] = std::unique_ptr<MenuOptionArgumentBase>(argument);
}
/**
 * @brief add Aqui se agrega
 * 
 * @tparam T 
 * @param key 
 * @param value 
 */
template <typename T>
void MenuOptionArguments::add(std::string key, T value) {
    add(key, new MenuOptionArgument<T>(value));
}
/**
 * @brief get Aqui va los getter 
 * 
 * @tparam T 
 * @param key 
 * @return T 
 */
template <typename T>
T MenuOptionArguments::get(std::string key) {
    auto arg = dynamic_cast<MenuOptionArgument<T>&>(*((*arguments)[key]));
    return arg.get_value();
}
/**
 * @brief setter de menu de opciones
 * 
 * @tparam T 
 * @param key 
 * @param value 
 */
template <typename T>
void MenuOptionArguments::set(std::string key, T value) {
    auto arg = dynamic_cast<MenuOptionArgument<T>&>(*((*arguments)[key]));
    arg.set_value(value);
}
/**
 * @brief find Es para encontrar 
 * 
 * @param key 
 * @return true 
 * @return false 
 */
inline bool MenuOptionArguments::has(std::string key) {
    return !(arguments->find(key) == arguments->end());
}

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief funtion con la opcion callback
 * 
 */
typedef std::function<void(MenuOptionArguments args)> MenuOptionCallback;

class MenuOption {
public:
/**
 * @brief Construct a new Menu Option object
 * 
 * @param label 
 * @param callback 
 */
    MenuOption(std::string label, MenuOptionCallback callback);
    /**
     * @brief Construct a new Menu Option object
     * 
     * @param label 
     * @param callback 
     * @param wait_after_exec 
     */
    MenuOption(std::string label, MenuOptionCallback callback, bool wait_after_exec);
    /**
     * @brief Construct a new Menu Option object
     * 
     * @param label 
     * @param callback 
     * @param arguments 
     */
    MenuOption(std::string label, MenuOptionCallback callback, MenuOptionArguments arguments);
    /**
     * @brief Construct a new Menu Option object
     * 
     * @param label 
     * @param callback 
     * @param arguments 
     * @param wait_after_exec 
     */
    MenuOption(std::string label, MenuOptionCallback callback, MenuOptionArguments arguments, bool wait_after_exec);
    /**
     * @brief Get the label object
     * 
     * @return std::string 
     */
    std::string get_label();
    /**
     * @brief Ejecutable
     * 
     */
    void execute();
    /**
     * @brief Controlador de Estado
     * 
     * @return true 
     * @return false 
     */
    bool should_wait();
    /**
     * @brief Get the args object
     * 
     * @return MenuOptionArguments& 
     */
    MenuOptionArguments &get_args();

private:
/**
 * @brief 
 * 
 */
    std::string label;
    /**
     * @brief 
     * 
     */
    MenuOptionCallback callback;
    /**
     * @brief 
     * 
     */
    bool wait_after_exec = true;
    /**
     * @brief 
     * 
     */
    MenuOptionArguments arguments;
};
