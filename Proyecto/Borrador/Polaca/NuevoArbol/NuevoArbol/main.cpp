#include "Validar.h"
int main() {
	Validar v;
	string exp;
	cout << "Ingrese la expresion matematica: " << endl;
	cin >> exp;
	if (v.validarExpresion(exp))
		;
	else
		cout << "Epresion no valida" << endl;
	v.separarExpresion(exp);
}
