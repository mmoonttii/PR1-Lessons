cmake_minimum_required(VERSION 3.26)
project(lez10_0512 C)

set(CMAKE_C_STANDARD 99)

add_executable(lez10_0512
#[[		Esercizi/es1.c
		Esercizi/es2.c
		Esercizi/es3.c
]]
		tipi.c
		Esercizi/es4.c
)

target_link_libraries(lez10_0512 m)
