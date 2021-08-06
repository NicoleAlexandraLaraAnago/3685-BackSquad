/**  
 * @App Calculadora Polaca    
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computacion
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: Convertir notacion infija a postfija, prefija y funcional
 * 
 * @date 05/07/2021
 * @author Dalton Arevalo
 * @author Diego Jimenez
 * @author Stalin Rivera
 * @author Lizzette Zapata
 * @author Nicole Lara
 */

#pragma once

class Application {
    public:
        static Application &get_instance();
        void run();
    
    private:
        Application() = default;
        Application(const Application &) = default;
        void operator=(const Application &) = delete;
        Application(Application &&) noexcept = default;
        Application &operator=(Application &&) noexcept = default;

        static Application *instance;
};