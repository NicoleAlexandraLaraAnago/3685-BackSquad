/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebastián Jiménez, Lizzete Zapata y Dalton Arevalo 
Fecha de creación: 16/07/2021
Fecha de modificación:22/07/2021
Ingeniería de Software
Estructura de Datos*/
#include "Consola.h"
#include <windows.h>

Console::Console(){
	SetConsoleTitle("ArbolesAVL");
}
void Console::hideCursor(bool value)
{
   CONSOLE_CURSOR_INFO cci = { 100, value }; 

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
void Console::changeSize(int width ,int heigth)
{
   
   _COORD size;
    _SMALL_RECT rect;
    size.X = width;
    size.Y = heigth;

    rect.Top = 0;
    rect.Left = 0;
    rect.Right = width - 1;
    rect.Bottom = heigth - 1;

    HANDLE _console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(_console, size);
    SetConsoleWindowInfo(_console, TRUE, &rect);
   
}

void Console::gotoXY(int x ,int y)
{
   HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}


void Console::changeColor(int texto, int fondo)
{
   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wColor = ((fondo & 0x0F) << 4) + (texto & 0x0F); 
    SetConsoleTextAttribute(h, wColor);
}
