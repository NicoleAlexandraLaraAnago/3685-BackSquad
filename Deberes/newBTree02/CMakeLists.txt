cmake_minimum_required(VERSION 3.0.0)
project(ArbolB+ VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
    ArbolB+ main.cpp ArbolB+.h 
    Menu.h Menu.cpp 
    Menu_option.h Menu_option.cpp 
    Aplicacion.h Aplicacion.cpp
    )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
