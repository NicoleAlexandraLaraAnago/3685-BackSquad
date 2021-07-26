cmake_minimum_required(VERSION 3.0.0)
project(TreeB+ VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE PROJECT_SOURCES "DBFiles/*.txt")

include_directories("${PROJECT_SOURCE_DIR}/DBFiles")

add_executable(
    TreeB+ 
    B+Tree.h B+Tree.cpp 
    display.cpp 
    insertion.cpp 
    remove_.cpp 
    search.cpp 
    utilFunc.cpp 
    )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
