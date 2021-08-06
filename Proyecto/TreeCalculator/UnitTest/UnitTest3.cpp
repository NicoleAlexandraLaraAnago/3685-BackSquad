/**      
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computacion
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: Convertir notacion infija a postfija, prefija y funcional
 * 
 * @date 30/07/2021
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "../TreeCalculator/opstr.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest{
    TEST_CLASS(UnitTest1){
    public:
        TEST_METHOD(TestMethod1){
            void strToList(Tree<char> &lst, std::string str){
                char* cadena = new cadena('1', '0', '+', '5','*', '8', '/', '2');
                Assert::IsNotNull(cadena);
            }
        }
    };

    TEST_CLASS(UnitTest2){
    public:
        TEST_METHOD(TestMethod1){
            std::string infijoToPostfijo(std::string str){
                char* cadena = new cadena('s', 'i', 'n', '(','8', ')', '/', '2');
                Assert::IsNotNull(cadena->infijoToFuncional("sin(8)/2"));
            }
        };
    }

    TEST_CLASS(UnitTest3){
    public:
        TEST_METHOD(TestMethod1){
            std::string infijoToPrefijo(std::string str){
                char* cadena = new cadena('2');
                Assert::IsNotNull(cadena->infijoToFuncional("2"));
            }
        };
    }
}