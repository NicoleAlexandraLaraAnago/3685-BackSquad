/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebastián Jiménez, Lizzete Zapata y Dalton Arevalo 
Fecha de creación: 16/07/2021
Fecha de modificación:22/07/2021
Ingeniería de Software
Estructura de Datos*/
#include "Menu.h"
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;


int Menu::makeMenu(std::string message, std::string options[], int index)
{
  	
  	
  	int selection=1;
  	int key;
  	bool flag = true;
	screen.hideCursor(FALSE);
	
	do{
		system ("cls");
		screen.gotoXY(2,2);
		cout<<message<<endl;
		system("cls");
		screen.gotoXY(6,8);
		screen.changeColor(BLUE,BLACK);
		cout<<message<<endl;
		for (int i = 0; i < index; i++) {
            if (selection == i + 1) {
                
                screen.gotoXY(6, 10 + i);
				screen.changeColor(WHITE,BLACK);
                cout <<" "<<*(options+i)<<endl;
            }
            else {
                
                screen.gotoXY(7, 10 + i);
                screen.changeColor(GRAY,BLACK);
                cout << *(options + i);
            }
        }
        
        do {
            key = _getch();
        } while (key != UP && key != DOWN && key != ENTER);
        
        switch (key) {
        case UP:
            selection--;
            if (selection <= 0) {
                selection = index;
            }
            break;
        case DOWN:
            selection++;
            if (selection > index) {
                selection = 1;
            }
            break;
        case ENTER:
            flag = false;
            break;
        }
		
	}while(flag);   
  	
  	return selection;
}
