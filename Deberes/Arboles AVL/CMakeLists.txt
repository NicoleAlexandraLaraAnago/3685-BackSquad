cmake_minimum_required(VERSION 3.0.0)
project(treesAVL VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(treesAVL main.cpp ArbolAVL.h ArbolAVL.cpp Color.h Consola.h Consola.cpp 
Menu.h Menu.cpp Nodo.h Nodo.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
