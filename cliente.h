// cliente.h
#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    int id;
    char nome[100];
    int idade;
    char genero;
    char plano[100];
    int ativo;
} Cliente;

#endif
