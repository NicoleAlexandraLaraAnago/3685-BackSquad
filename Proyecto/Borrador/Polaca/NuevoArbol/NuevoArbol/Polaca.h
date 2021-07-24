#pragma once
#include"Pila.h"
#include "PilaString.h"
#include"ArbolBinario.h"
#include <string>
#include <iostream>

class Polaca
{ 
public:
	bool jerarquia(char,char);
	void resolverEcuacion(string[], int);
	void separar(string);
	string doOperation(string, string, string);
	string stringPost(string[], int);
	Pila pil1;
	ArbolBinario _tree;
	string respuesta;
};

