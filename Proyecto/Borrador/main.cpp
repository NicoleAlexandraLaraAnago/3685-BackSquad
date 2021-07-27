#define BACKSPACE 8
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <fstream>
#define USUARIO "user1"
#define PASSWORD "500"
#define SUPER "BackSquad"
#define PASS "SOFTWARE"
#define ENTER 13

using namespace std;
struct usuario
{
    string nombre;
    string contrasenia;
} personas[100];

int main()
{
    string usuario, password;

    int cont = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\t\t\t*******BIENVENIDO AL SISTEMA********";
        cout << "\n\n\tIngrese el Usuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tClave: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            caracter = getch();
        }

        if (usuario == SUPER && password == PASS)
        {
            ingresa = true;
        }
        else
        {

        }
    } while (ingresa == false && cont < 3);

    if (ingresa == false)
    {
        cout << "\n\tPor varios errores, el sistema se cerrara en cualquier momento \n";
    }
    else if (usuario == "BackSquad" && password == "SOFTWARE")
    {
        cout << "\n\n\tSea Bienvenido\n\n";
        system("pause");
    }
    cin.get();
    return 0;
}

int mostrar()
{
    for (int i = 0; i < 100; i++)
    {
        if (personas[i].contrasenia != "")
        {
            cout << personas[i].nombre << endl;
            cout << personas[i].contrasenia << endl;
        }
    }
}

int quitar_usuario(int usuario1)
{
    for (int i = 0; i < 100; i++)
    {
        if (usuario1 == i)
        {
            personas[usuario1].nombre = " ";
            personas[usuario1].contrasenia = " ";
        }
    }
}


