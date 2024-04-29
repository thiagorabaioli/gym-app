#ifndef EFOLIOA_PRESENCA_H
#define EFOLIOA_PRESENCA_H

typedef struct {
    int id_cliente;
    int num_sessoes;
    int id_plano_treino;
    int pagamento;
}Presenca;

float pagamento(int num_sessoes);

void p_ler_clientes_presenca();

void p_exibir_presencas();

void  p_inserir_frequencia_id(const char* nome_arquivo);

float p_pagamento(const char* nome_arquivo);

#endif

