// controle_presenca.h
#ifndef CONTROLE_PRESENCA_H
#define CONTROLE_PRESENCA_H
#include "cliente.h"

typedef struct {
    int idPresenca;
    int numSessoes;
    float pagamento;
    Cliente cliente;
}Contelo_Presenca;

void registrar_presenca(Cliente* cliente);
float calcular_pagamento(Cliente* cliente);

#endif
