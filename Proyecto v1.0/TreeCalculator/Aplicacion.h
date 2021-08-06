/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
**Docente: Fernando Solis
*AUTORES : Diejo Jiminez
*Dalton Arevalo
*Lizzette Zapata
*Stalin Rivera 
*Nicol Lara
*ENUNCIADO: CREACION DE UN PROGRAMA QUE SIMULE UNA CALCULADORA POLACA INVERSA
*FECHA DE CREACION : 15 DE JULIO DE 2021
*FECHA DE MODIFICACION:  06 DE JULIO DE 2021
*/
#pragma once

class Application {
    /**
     * @brief Application Atributo
     * 
     */
    public:
    /**
     * @brief Get the instance object
     * 
     * @return Application& 
     */
        static Application &get_instance();
    /**
     * @brief run es una funcion que no retorna nada 
     * 
     */
        void run();
    
    private:
    /**
     * @brief Construct a new Application object
     * Se usa el constructor por default
     * 
     */
        Application() = default;
        /**
         * @brief Construct a new Application object
         * 
         */
        Application(const Application &) = default;
        void operator=(const Application &) = delete;
        /**
         * @brief Construct a new Application object
         * 
         */
        Application(Application &&) noexcept = default;
        /**
         * @brief &operator
         * 
         * @return Application& 
         */
        Application &operator=(Application &&) noexcept = default;

        static Application *instance;
};