
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
//#include <filesystem>
#include "B+Tree.h"

#define _CRT_SECURE_NO_DEPRECATE  //for VS 2019

void insertionMethod(BPTree** bPTree) {
    int rollNo;
    int age, marks;
    string name;

    cout << "Proporcione un numero para guardar los datos: ";
    cin >> rollNo;

    cout << "\nNombre, edad, clave?: ";
    cin >> name >> age >> marks;

    string fileName = "DBFiles/";
    fileName += to_string(rollNo) + ".txt";
    FILE* filePtr = fopen(fileName.c_str(), "w");
    string userTuple = name + " " + to_string(age) + " " + to_string(marks) + "\n";
    fprintf(filePtr, userTuple.c_str());
    fclose(filePtr);

    (*bPTree)->insert(rollNo, filePtr);
    fclose(filePtr);
    cout << "Insertado en el roll No: " << rollNo << " Exitosa"<<endl;
}

void searchMethod(BPTree* bPTree) {
    int rollNo;
    cout << "Que roll desea buscar? ";
    cin >> rollNo;

    bPTree->search(rollNo);
}

void printMethod(BPTree* bPTree) {
    int opt;
    cout << "\n\t1.Mostrar por jerarquia \n\t2.Mostrar secuencial\n";
    cin >> opt;

    cout << "\nAquí está su estructura de archivos" << endl;
    if (opt == 1)
        bPTree->display(bPTree->getRoot());
    else
        bPTree->seqDisplay(bPTree->getRoot());
}

void deleteMethod(BPTree* bPTree) {
    cout << "Mostrándote el arbol, elige una clave de aquí: " << endl;
    bPTree->display(bPTree->getRoot());
 
    int tmp;
    cout << "Ingrese una clave para eliminar: " << endl;
    cin >> tmp;
    bPTree->removeKey(tmp);

    //Displaying
    bPTree->display(bPTree->getRoot());
}

int main() {
    bool flag = true;
    int option;

    int maxChildInt = 4, maxNodeLeaf = 3;
    cout << "Proporcione el valor para limitar el numero maximo de nodos internos secundarios que pueden tener: ";
    cin >> maxChildInt;
    cout << "\nLimite el valor para limitar el número máximo de nodos que pueden tener los nodos hoja: ";
    cin >> maxNodeLeaf;

    BPTree* bPTree = new BPTree(maxChildInt, maxNodeLeaf);

    do {
        cout << "\nProporcione las consultas con las claves respectivas : " << endl;
        cout << "\t1: Inserción \n\t2: Buscar \n\t3: Imprimir Arbol\n\t4: Eliminar clave del arbol\n\t5: Salir" << endl;
        cin >> option;

        switch (option) {
            case 1:
                insertionMethod(&bPTree);
                break;
            case 2:
                searchMethod(bPTree);
                break;
            case 3:
                printMethod(bPTree);
                break;
            case 4:
                deleteMethod(bPTree);
                break;
            default:
                flag = false;
                break;
        }
    }while (flag);

    return 0;
}