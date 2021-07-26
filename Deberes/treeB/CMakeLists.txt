cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main main.cpp Btree.h node.h Menu_option.h Menu_Option.cpp Menu.h Menu.cpp Aplicacion.h Aplicacion.cpp )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
