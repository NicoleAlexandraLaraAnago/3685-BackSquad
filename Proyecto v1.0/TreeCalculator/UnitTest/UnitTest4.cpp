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
#include "../TreeCalculator/opstack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest{
    TEST_CLASS(UnitTest1){
    public:
        TEST_METHOD(TestMethod1){
            Stack<std::string> inToStack(std::string chain){
                char* str = new('8', '/', '2');
                Assert::IsNotNull(str);
            }
        }
    };

    TEST_CLASS(UnitTest2){
    public:
        TEST_METHOD(TestMethod1){
            Stack<std::string> inToPost(Stack<std::string> str){
                Node<std::string>* tmp = str.getCursor();
                Assert::IsNotNull(tmp));
            }
        };
    }

    TEST_CLASS(UnitTest3){
    public:
        TEST_METHOD(TestMethod1){
            calculateReversePolac(Stack<std::string> str){
                Node<std::string>* tmp = str.getCursor();
                Assert::IsNotNull(isFuntion(tmp->getDat()));
            }
        };
    }
}