cmake_minimum_required(VERSION 3.26)
project(lez1910 C)

set(CMAKE_C_STANDARD 99)

add_executable(lez1910 main.c
        calx.c
        esercizi/eses.c
        esercizi/es8lez4.c
        esercizi/es1.c
        esercizi/es2.c
        esercizi/es3.c
        es4.c
        esercizi/es9.c)

target_link_libraries(lez1910 m)