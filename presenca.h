#ifndef EFOLIOA_PRESENCA_H
#define EFOLIOA_PRESENCA_H

typedef struct {
    int id_cliente;
    int num_sessoes;
    int id_plano_treino;
    float pagamento;
}Presenca;

float pagamento(int num_sessoes);

void p_ler_clientes_presenca();

void p_exibir_presencas();

void printTestePresenca();

#endif

