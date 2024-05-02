#include <stdio.h>
#include "presenca.h"
#include "leitura_dados.h"
#define MAX_SIZE2 100 // Define o número máximo de clientes que o programa pode armazenar
int num_frequencias2=0;

Presenca presenca[MAX_SIZE2];


void  p_ler_clientes_presenca(const char* nome_arquivo){
    num_frequencias2=0;
    FILE *arquivo2 = fopen(nome_arquivo, "r");

    if(arquivo2==NULL){
        perror("Erro ao abrir o arquivo");
        return;
    }

    char buffer[256];
    while(fgets(buffer, sizeof (buffer), arquivo2)){


        sscanf(buffer, "%d,%d,%d,%d", &presenca[num_frequencias2].id_cliente,
               &presenca[num_frequencias2].num_sessoes,
               &presenca[num_frequencias2].id_plano_treino,
               &presenca[num_frequencias2].pagamento);
        num_frequencias2++;
    }

    fflush(arquivo2);

    fclose(arquivo2);


}

void p_exibir_presencas(){

    printf("Frequencias: \n");
    for (int i=1; i<num_frequencias2; i++){
        printf("ID Cliente Frequencia: %d, Numero sessoes: %d, ID plano de treino: %d preco plano pagamento: %d \n",
               presenca[i].id_cliente, presenca[i].num_sessoes, presenca[i].id_plano_treino, presenca[i].pagamento);
    }
}

void p_inserir_frequencia_id(const char* nome_arquivo) {
    int id_cliente;
    printf("Digite o ID do cliente\n");
    scanf("%d", &id_cliente);
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo\n");
        return;
    }
    printf("Digite o numero de sessoes \n");
    scanf("%d", &presenca[id_cliente].num_sessoes);
    fprintf(arquivo, "%d,%d\n", presenca[id_cliente].id_cliente = id_cliente, presenca[id_cliente].num_sessoes);
    printf("Presenca adicionada com sucesso!\n");
    fclose(arquivo);

}
    float p_pagamento(const char* nome_arquivo){
    int id_cliente;
           printf("Digite o ID do cliente para calculo do pagamento: ");
           scanf("%d", &id_cliente);

        FILE *arquivo = fopen(nome_arquivo, "a");
        if (arquivo == NULL) {
            perror("Erro ao abrir o arquivo\n");
        }
        printf("numero de sessoes: %d \n",presenca[id_cliente].num_sessoes );
            int pagamento2 = presenca[id_cliente].num_sessoes * presenca[id_cliente].pagamento;
         printf("Valor do pagamento dentro da classe presenca %d: ", pagamento2);
           return pagamento2;
        fclose(arquivo);
    }
