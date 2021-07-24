/**      
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computacion
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: Validar entrada de enteros
 * 
 * @date 07/07/2021
 * @author Diego Jimenez
 */

#include "isNumeric.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <limits>
#include <conio.h>

using namespace std;

int checkInteger(const char* str){
    string store;
    int show;
    cout << endl << str;
    while(true){
        
        int get = _getch();
        // if( get == 224){
        //     get = _getch();
        // }
        if(get == 8 && !store.empty()){
            cout << "\b \b";
            store.pop_back();
        }
        if(get == 13 && !store.empty()){
            break;
        }
        if(get < 48 || get > 57){
            continue;
        }
        
        char c = static_cast<char>(get);
        store.push_back(c);
        cout <<c;
    }
    show = std::stoi(store);
    return show;
}

int main(int, char**) {
    std::cout << "Programa para validar la entrada de numeros enteros \n";
    std::cout << "Ingrese un numero entero: ";
    // std::string chain_;
    // std::getline(std::cin, chain_);
    // CheckInt check_;
    // check_.setLine_(chain_);
    // if (!check_.isNumeric()){
    //     std::cout << "el valor no es numerico \n";
    // }else{
    //     std::cout << "el valor ingresado es: " << check_.toInteger() <<std::endl;
    // }
    int n = checkInteger("El numero es: ");
    cout << "\n"<< n << endl;

    system("pause");
}
