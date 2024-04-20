#include <stdio.h>
#include "cliente.h"
#include <unistd.h>


#define MAX_CLIENTES 100 // Define o número máximo de clientes que o programa pode armazenar
int num_clientes = 0; // Variável para rastrear o número atual de clientes
int proximo_id = 5; // Inicialize o próximo ID com 5

Cliente clientes[MAX_CLIENTES]; // Array para armazenar os clientes

void adicionar_cliente(const char* nome_arquivo){

    if(num_clientes >=100){
        printf("Tamanho máximo clientes ultrapassado (max 100 clientes \n");
        return;
    }

    FILE *arquivo = fopen(nome_arquivo, "a");
    if(arquivo==NULL){
        printf("Erro ao abrir o ficheiro. \n");
        return;
    }

    printf("Adicionar novo cliente: \n");

    clientes[num_clientes].id = proximo_id++; // "Id do cliente incrementado"
    printf("Nome: ");
    scanf("%s", clientes[num_clientes].nome);
    printf("Idade: ");
    scanf("%d", &clientes[num_clientes].idade);
    printf("Genero (M/F): ");
    scanf(" %c", &clientes[num_clientes].genero);
    printf("Plano de treino: ");
    scanf("%s", clientes[num_clientes].plano);

    // Escrever os dados do novo cliente no arquivo
    fprintf(arquivo, "%d,%s,%d,%c,%s\n", clientes[num_clientes].id, clientes[num_clientes].nome, clientes[num_clientes].idade,
            clientes[num_clientes].genero, clientes[num_clientes].plano);
    // Incrementar o número de clientes após adicionar um novo cliente
    num_clientes++;

    printf("Novo cliente adicionado com sucesso!\n");

    fclose(arquivo); // Fecha o arquivo após a escrita
}

int verificarArquivoExiste(const char *path) {
    if (access(path, F_OK) == 0) {
        printf("existe");
        return 1; // O arquivo existe
    } else {
        printf("Nao existe");
        return 0; // O arquivo não existe
    }
}
 void  ler_clientes_do_arquivo(const char* nome_arquivo){

    FILE *arquivo = fopen(nome_arquivo, "r");

     if(arquivo==NULL){
         perror("Erro ao abrir o arquivo");
         return;
     }

     char buffer[256];
     while(fgets(buffer, sizeof (buffer), arquivo)){


         sscanf(buffer, "%d,%[^,],%d,%c,%[^,\n]", &clientes[num_clientes].id, clientes[num_clientes].nome, &clientes[num_clientes].idade,
                &clientes[num_clientes].genero, clientes[num_clientes].plano);
         num_clientes++;
     }
     fclose(arquivo);

   }

   void exibir_clientes(){
       printf("Clientes: \n");
       for (int i=1; i<num_clientes; i++){
           printf("ID: %d, Nome: %s, Idade: %d, Genero %c, plano de treino: %s \n",
                  clientes[i].id, clientes[i].nome, clientes[i].idade, clientes[i].genero, clientes[i].plano);
       }
}


