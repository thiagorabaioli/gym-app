#include <stdio.h>
#include "cliente.h"
#include <unistd.h>
#include "leitura_dados.c"

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
    fflush(arquivo);

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

    clientes[num_clientes].ativo=1; //Cliente é sempre iniciado como ativo.

    // Escrever os dados do novo cliente no arquivo
    fprintf(arquivo, "%d,%s,%d,%c,%s,%d\n", clientes[num_clientes].id, clientes[num_clientes].nome, clientes[num_clientes].idade,
            clientes[num_clientes].genero, clientes[num_clientes].plano, clientes[num_clientes].ativo);

    // Incrementar o número de clientes após adicionar um novo cliente
    num_clientes++;


    printf("Novo cliente adicionado com sucesso!\n");

    fclose(arquivo); // Fecha o arquivo após a escrita
}

int verificarArquivoExiste(const char *path) {
    if (access(path, F_OK) == 0) {
        printf("existe \n");
        return 1; // O arquivo existe
    } else {
        printf("Nao existe \n");
        return 0; // O arquivo não existe
    }
}
 void  ler_clientes_do_arquivo(const char* nome_arquivo){
  num_clientes=0;
    FILE *arquivo = fopen(nome_arquivo, "r");

     if(arquivo==NULL){
         perror("Erro ao abrir o arquivo");
         return;
     }

     char buffer[256];
     while(fgets(buffer, sizeof (buffer), arquivo)){


         sscanf(buffer, "%d,%[^,],%d,%c,%[^,], %d", &clientes[num_clientes].id, clientes[num_clientes].nome, &clientes[num_clientes].idade,
                &clientes[num_clientes].genero, clientes[num_clientes].plano, &clientes[num_clientes].ativo);
         num_clientes++;
     }

     fflush(arquivo);

     fclose(arquivo);


   }

   void exibir_clientes(){
       printf("Clientes: \n");
       for (int i=0; i<num_clientes; i++){
           printf("ID: %d, Nome: %s, Idade: %d, Genero %c, plano de treino: %s, Ativo: %d \n",
                  clientes[i].id, clientes[i].nome, clientes[i].idade, clientes[i].genero, clientes[i].plano, clientes[i].ativo);
       }
}

int recebe_id_cliente(){
    exibir_clientes();
    int id_cliente=0;
    printf("Digite o ID do cliente: \n");
    scanf("%d", &id_cliente);
    return id_cliente;
}

void remover_cliente_id(int id){
    int encontrou=0;
    for(int i=0; i<num_clientes; i++){
        if(clientes[i].id == id){
            clientes[i].ativo=0;
            encontrou=1;
            break;
        }
    }
    if(!encontrou) printf("Cliente com o ID: %d, não econtrado: \n", id);
}

void escrever_clientes_no_arquivo(const char* nome_arquivo){
    if(nome_arquivo==NULL){
        perror("arquivo nao encontrado \n");
        return;
    }
    FILE *arquivo = fopen(nome_arquivo, "w");

    for(int i=0; i<num_clientes; i++){
            if(clientes[i].ativo==1){
                fprintf(arquivo, "%d,%s,%d,%c,%s,%d\n",
                        clientes[i].id, clientes[i].nome, clientes[i].idade, clientes[i].genero, clientes[i].plano, clientes[i].ativo=1);
            }
    }
    fclose(arquivo); //Fecha o arquivo.
}

void alterar_cliente_id(){
     int id_cliente = recebe_id_cliente();
    printf("Clientes: \n");
    printf("ID: %d, Nome: %s, Idade: %d, Genero %c, plano de treino: %s, Ativo: %d \n",
               clientes[id_cliente].id, clientes[id_cliente].nome, clientes[id_cliente].idade, clientes[id_cliente].genero, clientes[id_cliente].plano, clientes[id_cliente].ativo);


}








