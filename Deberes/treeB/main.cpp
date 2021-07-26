#include <iostream>
#include "Btree.h"

int main(int, char**) {
    std::cout << "Programa para probar arboles!\n";
    BTree<int> t(3);
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    // t.insert(1);
    // t.insert(8);
    // t.insert(12);
    // t.insert(24);
    // t.insert(19);
    // t.insert(35);
    // t.insert(71);
    // t.insert(23);
    std::cout<<"Atravesando el arbol construido "<<std::endl;
    t.iterateTree();
    int k = 6;
    (t.search(k)!=NULL)? std::cout<<"\nPresent" : std::cout<< "\nNot Present";
    k = 1;
    (t.search(k)!=NULL)? std::cout<<"\nPresent" : std::cout<< "\nNot Present";
    return 0;
}
