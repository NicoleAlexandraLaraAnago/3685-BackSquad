#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    float area, lado1, altura;

    do {
    cout << "Ingrese el valor de la base en (m): ";
    cin >> lado1;
    if (lado1 < 1) {
            cout << "Error!!!... Ingrese solo valores mayores a 0!!!\n";
        }
    } while (lado1 < 1);

    do {
    cout << "Ingrese el valor de la altura en (m): ";
    cin >> altura;
    if (altura < 1) {
            cout << "Error!!!... Ingrese solo valores mayores a 0!!!\n";
        }
    } while (altura < 1);
    area = (lado1 * altura)/2;
    cout << "El area del triangulo es de: " << area << " m\n";
    system("pause");
    return 0;
}
