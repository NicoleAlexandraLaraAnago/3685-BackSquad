#include "Aplicacion.h"
#include "Menu.h"
#include "Menu_option.h"
#include "BTree.h"

Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}

void Application::run() {
    Menu menu("Arboles B - Menu"); 

    BTree<int> t(3);

    menu.add_option(MenuOption("Insertar", [&](MenuOptionArguments args) {
        int num;
        std::cout << "Ingrese un numero: " ;
        std::cin >> num;
        t.insert(num);
    }));

    menu.add_option(MenuOption("Buscar", [&](MenuOptionArguments args) {
        int num;
        std::cout << "Ingrese un numero: " ;
        std::cin >> num; 
        (t.search(num)!=NULL)? std::cout<<"\nPresent" : std::cout<< "\nNot Present";
    }));

    menu.add_option(MenuOption("Imprimir", [&](MenuOptionArguments args) {
        t.iterateTree();
    }));

    menu.add_option(MenuOption("Eliminar", [&](MenuOptionArguments args) {
        
    }));

    menu.add_option(MenuOption("Salir", [&](MenuOptionArguments args) {
        std::cout << "Salio con exito del programa..." << std::endl;
        menu.stop();
    }, false));


    menu.display(); 
}