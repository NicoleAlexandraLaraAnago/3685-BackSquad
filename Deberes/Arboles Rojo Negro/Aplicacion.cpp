#include "Aplicacion.h"
#include "Menu.h"
#include "Menu_option.h"
#include "RBTree.h"

Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}

void Application::run() {
    RBTree tree;
    int numero;
    Menu menu("Arbol Rojo/Negro");

    menu.add_option(MenuOption("Insertar", [&](MenuOptionArguments args) {
        std::cout << "Ingrese el numero: ";
        cin >> numero;
        tree.insert(numero);
        std::cout << "\nNumero ingresado con exito!!!";
    }));

    menu.add_option(MenuOption("Buscar", [&](MenuOptionArguments args) {
        std::cout << "Ingrese el numero para buscar: ";
        cin >> numero;
        tree.buscar(numero);
    }));

    menu.add_option(MenuOption("Eliminar", [&](MenuOptionArguments args) {
        std::cout << "Ingrese el numero a eliminar: ";
        cin >> numero;
        tree.deleteByVal(numero);
    }));

    menu.add_option(MenuOption("Imprimir por orden", [&](MenuOptionArguments args) {
        tree.printInOrder();
    }));

    menu.add_option(MenuOption("Imprimir por nivel", [&](MenuOptionArguments args) {
       tree.printLevelOrder();
    }));

    menu.add_option(MenuOption("Salir", [&](MenuOptionArguments args) {
        std::cout << "Salio con exito del programa..." << std::endl;
        menu.stop();
    }, false));


    menu.display(); 
}