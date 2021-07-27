/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebastián Jiménez, Lizzete Zapata, Nicole Lara y Dalton Arevalo 
Fecha de creación: 16/07/2021
Fecha de modificación:22/07/2021
Ingeniería de Software
Estructura de Datos*/
#include <string>

#define UP    72
#define LEFT  75
#define RIGTH    77
#define DOWN      80
#define ESC        27
#define ENTER      13

enum colors{
	BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GRAY = 7,
    GRAY = 8,
    LIGHT_GREEN = 9,
    LIGHT_CYAN = 10,
    LIGHT_RED = 11,
    LIGHT_MAGENTA = 12,
    LIGHT_YELLOW = 13,
    YELLOW = 14,
    WHITE = 15,
};

class Console
{
public:
   void hideCursor(bool);
   void changeSize(int,int);
   void gotoXY(int,int);
   void changeColor(int texto, int fondo);
   Console();
protected:
private:
   int cursor;
   


};

