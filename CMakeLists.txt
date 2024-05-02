cmake_minimum_required(VERSION 3.27)
project(efolioA C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(efolioA
        cliente.h
        escrita_dados.c
        escrita_dados.h
        leitura_dados.c
        leitura_dados.h
        main.c
        menu_principal.c
        menu_principal.h
        relatorios.c
        relatorios.h
        controle_presenca.h
        controle_presenca.c)
