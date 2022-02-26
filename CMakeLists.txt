cmake_minimum_required(VERSION 3.10)
project(SFML_EventManager VERSION 1.0)

set(SFML_DIR "" CACHE PATH "Where to look for SFML modules")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${SFML_DIR}/include)
add_definitions(-DSFML_STATIC)
add_definitions(/MP)

FILE(
    GLOB SFML_EventManagerFiles
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${SFML_DIR}/include/*
)

add_executable(SFML_EventManager ${SFML_EventManagerFiles})

set(LINKLIBS
    ${SFML_DIR}/lib/sfml-graphics-s.lib
    ${SFML_DIR}/lib/sfml-window-s.lib
    ${SFML_DIR}/lib/sfml-system-s.lib
    ${SFML_DIR}/lib/sfml-main.lib
    opengl32.lib
    ${SFML_DIR}/lib/freetype.lib
    winmm.lib
    gdi32.lib
)

target_link_libraries(SFML_EventManager ${LINKLIBS})