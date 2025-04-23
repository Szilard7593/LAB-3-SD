cmake_minimum_required(VERSION 3.30)
project(Lab3SD)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab3SD main.cpp Colection.tpp
        Tranzactie.cpp
        Tranzactie.h
        UI.cpp
        UI.h
        Iterator.h
        Iterator.tpp
        Multime.h
        Multime.tpp
        Bancnote.in
)
