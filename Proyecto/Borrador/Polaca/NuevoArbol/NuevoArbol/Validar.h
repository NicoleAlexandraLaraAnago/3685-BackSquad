#pragma once
#include <string>
#include<iostream>
#include <stdlib.h>
#include "ArbolBinario.h"
#include "Polaca.h"

using namespace std;


class Validar
{
public:
	bool validarExpresion(string);
	bool validarCaracteres(string);
	void separarExpresion(string);
public:
	ArbolBinario _tree;
};
