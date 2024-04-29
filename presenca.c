#include <stdio.h>
#include "presenca.h"
#define MAX_SIZE2 100 // Define o número máximo de clientes que o programa pode armazenar
int num_frequencias2=0;

Presenca presenca[MAX_SIZE2];


void printTestePresenca(){
    printf("printTestePresenca");
}

void  p_ler_clientes_presenca(const char* nome_arquivo){
    num_frequencias2=0;
    FILE *arquivo2 = fopen(nome_arquivo, "r");

    if(arquivo2==NULL){
        perror("Erro ao abrir o arquivo");
        return;
    }

    char buffer[256];
    while(fgets(buffer, sizeof (buffer), arquivo2)){


        sscanf(buffer, "%d,%d,%d", &presenca[num_frequencias2].id_cliente, &presenca[num_frequencias2].num_sessoes,
               &presenca[num_frequencias2].id_plano_treino);
        num_frequencias2++;
    }

    fflush(arquivo2);

    fclose(arquivo2);


}

void p_exibir_presencas(){

    printf("Frequencias: \n");
    for (int i=1; i<num_frequencias2; i++){
        printf("ID Cliente Frequencia: %d, Numero sessoes: %d, ID plano de treino: %d\n",
               presenca[i].id_cliente, presenca[i].num_sessoes, presenca[i].id_plano_treino);
    }
    getchar();
}