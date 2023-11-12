cmake_minimum_required(VERSION 3.26)
project(lez1710 C)

set(CMAKE_C_STANDARD 99)

add_executable(lez1710 calc.c
        calcswitch.c
        rand.c
        esercizi/es1.c
        esercizi/es2.c)

target_link_libraries(lez1710 m)