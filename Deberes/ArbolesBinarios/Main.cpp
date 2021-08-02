/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebastián Jiménez, Lizzete Zapata, Nicole Lara y Dalton Arevalo 
Fecha de creación: 16/07/2021
Fecha de modificación:22/07/2021
Ingeniería de Software
Estructura de Datos*/
#include "Arbol.h" // incluimos la libreria Arbol, la cual ya tiene incluida Nodo
Nodo* arbol = NULL; 

void subMenu(){

    Arbol objArbol; //objeto del arbol
    int subOpcion = 0; //opcion para los rocorridos del arbol

    while (subOpcion != 4){
    
        cout << "\n 1. Preorden";
        cout << "\n 2. Inorden";
        cout << "\n 3. Postorden";
        cout << "\n 4. Regresar";
        cout << "\n\nDigite una opcion: ";        
        cin >> subOpcion;

        system("cls");
        if( subOpcion == 1 ){
            
            objArbol.preOrden(arbol);

            cout << endl;
            system("pause");
            system("cls");
        }
        else if(subOpcion == 2){

            objArbol.inOrden(arbol);

            cout << endl;
            system("pause");
            system("cls");
        }
        else if(subOpcion == 3){

            objArbol.postOrden(arbol);

            cout << endl;
            system("pause");
            system("cls");
        }
    }
}


void menu(){


    Arbol objArbol;
    int contador = 0, opcion = 0, dato = 0;

    while(opcion != 5){

        cout << "\n 1. Insertar nodo";
        cout << "\n 2. Mostrar arbol";
        cout << "\n 3. Buscar en el arbol";
        cout << "\n 4. Recorridos de un arbol";
        cout << "\n 5. Salir";
        cout << "\n\nDigite una opcion: ";
        cin >> opcion;

        system("cls");

        if(opcion == 1){

            cout << "Ingrese un dato: ";
            cin >> dato;

            objArbol.insertarNodo(arbol, dato); // llamando al metodo gracias al objeto

            cout << endl;
            system("pause");
            system("cls");
        }
        else if(opcion == 2){

            cout << "A R B O L" << endl;

            objArbol.mostrar(arbol, contador); // llamndo al metodo mostrar
            
            cout << endl;
            system("pause");
            system("cls");
        }
        else if(opcion == 3){

            cout << "Digite un elemento a buscar: ";
            cin >> dato;

            if(objArbol.buscar(arbol, dato) == true){ // comprobando si el metodo mostrar es verdader o falso
                cout << "Elemento " << dato << " encontrado dentro del arbol" << endl; 
            }
            else{
                cout << "Elemento no pertenese al arbol";
            }

            cout << endl;
            system("pause");
            system("cls"); 
        }
        else if(opcion == 4){

            subMenu(); // llamando a la funcion sub menu para tener los recorridos del arbol

            cout << endl;
            system("pause");
            system("cls");
        }

    }

}

int main(){

    menu(); // llamando a la funcion menu 

    cout << endl;
    return 0;
}

