/*Universidad de las Fuerzas Armadas ESPE
Tpitulo: Arboles AVL en C++
Autor/es: Stalin Rivera, Sebasti�n Jim�nez, Lizzete Zapata, Nicole Lara y Dalton Arevalo 
Fecha de creaci�n: 16/07/2021
Fecha de modificaci�n:22/07/2021
Ingenier�a de Software
Estructura de Datos*/
#pragma once
#include <ostream>

namespace ansi {
    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& reset(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[0m";
    }

    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& foreground_green(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[32m";
    }

    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& foreground_red(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[31m";
    }

    template < class CharT, class Traits >
    constexpr
        std::basic_ostream< CharT, Traits >& foreground_yellow(std::basic_ostream< CharT, Traits >& os)
    {
        return os << "\033[93m";
    }

    
}

