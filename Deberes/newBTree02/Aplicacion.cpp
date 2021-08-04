#include "Aplicacion.h"
#include "Menu.h"
#include "Menu_option.h"
#include "ArbolB+.h"

Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}

void Application::run() {
    int numero,grado;
    Menu menu("Arbol B+");
    std::cout << "Ingrese el grado del arbol: ";
    std::cin >> grado; 
    BTree <int> tree(grado);

    menu.add_option(MenuOption("Insertar", [&](MenuOptionArguments args) {
        std::cout << "Ingrese el numero: ";
        std::cin >> numero;
        tree.Insert(numero);
        std::cout << "\n Datos Ingresados!!!";
    }));

    menu.add_option(MenuOption("Buscar", [&](MenuOptionArguments args) {
        std::cout << "Ingrese el numero a buscar: ";
        std::cin >> numero;
        tree.Search(numero);
    }));

    menu.add_option(MenuOption("Eliminar", [&](MenuOptionArguments args) {
        std::cout << "Ingrese el numero para eliminar: ";
        std::cin >> numero;
        tree.Remove(numero);
    }));

    menu.add_option(MenuOption("Imprimir arbol", [&](MenuOptionArguments args) {
        tree.Print();
    }));

    menu.add_option(MenuOption("Salir", [&](MenuOptionArguments args) {
        std::cout << "Salio con exito del programa..." << std::endl;
        menu.stop();
    }, false));


    menu.display(); 
}