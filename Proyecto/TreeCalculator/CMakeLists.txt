cmake_minimum_required(VERSION 3.0.0)
project(tcalculator VERSION 0.1.0)

include(FetchContent)

set(CMAKE_CXX_STANDARD 14)
set(SFML_STATIC 1)
set(SFML_DIR "${PROJECT_SOURCE_DIR}/external/SFML")
set(IMGUI_SFML_DIR "${PROJECT_SOURCE_DIR}/external/imgui-sfml")

add_compile_definitions(SFML_STATIC)

include_directories(${SFML_DIR}/include)
include_directories(${IMGUI_SFML_DIR}/include)

include(CTest)
enable_testing()

add_executable(tcalculator main.cpp node.h stack.h opstr.h opstack.h tnode.h tree.h opstree.h)

target_link_directories(tcalculator PUBLIC "${SFML_DIR}/lib")
target_link_directories(tcalculator PUBLIC "${IMGUI_SFML_DIR}/lib")

target_link_libraries(tcalculator
    PUBLIC 
    ImGui-SFML
    sfml-window-s
    sfml-system-s
    sfml-graphics-s
    opengl32
    winmm
    gdi32
    imm32
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
