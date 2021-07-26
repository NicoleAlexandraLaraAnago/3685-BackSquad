cmake_minimum_required(VERSION 3.0.0)
project(treeB VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(treeB main.cpp
node.h Btree.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
