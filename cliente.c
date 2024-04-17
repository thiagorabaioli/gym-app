#include <stdio.h>
#include "cliente.h"
#include <unistd.h>


#define MAX_CLIENTES 100 // Define o número máximo de clientes que o programa pode armazenar
int num_clientes = 0; // Variável para rastrear o número atual de clientes
int proximo_id = 5; // Inicialize o próximo ID com 1

Cliente clientes[MAX_CLIENTES]; // Array para armazenar os clientes
// Variável para rastrear o número atual de clientes

void adicionar_cliente(const char* nome_arquivo) {
    // Verifica se o limite máximo de clientes foi atingido
    if (num_clientes >= MAX_CLIENTES) {
        printf("Limite máximo de clientes atingido!\n");
        return;
    }

    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    printf("Adicionar novo cliente:\n");

    // Solicitar ao usuário que insira os detalhes do novo cliente
    printf("Nome: ");
    scanf("%s", clientes[num_clientes].nome);
    printf("Idade: ");
    scanf("%d", &clientes[num_clientes].idade);
    printf("Gênero (M/F): ");
    scanf(" %c", &clientes[num_clientes].genero);
    printf("Plano de treino: ");
    scanf("%s", clientes[num_clientes].plano);
    // Atribuir o próximo ID ao novo cliente e incrementar o próximo ID para o próximo cliente
    clientes[num_clientes].id = proximo_id++;

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

void ler_clientes_do_arquivo(const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linha[256]; // Buffer para armazenar cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Extrai os dados de cada linha usando sscanf()
        sscanf(linha, "%d,%[^,],%d,%c,%[^,\n]", &clientes[num_clientes].id, clientes[num_clientes].nome, &clientes[num_clientes].idade,
               &clientes[num_clientes].genero, clientes[num_clientes].plano);
        num_clientes++; // Incrementa o número de clientes
    }

    fclose(arquivo); // Fecha o arquivo após a leitura
}


void exibir_clientes() {
    printf("Clientes:\n");
    for (int i = 1; i < num_clientes; i++) {
        printf("ID: %d, Nome: %s, Idade: %d, Genero: %c, Plano de Treino: %s\n",
               clientes[i].id,clientes[i].nome, clientes[i].idade, clientes[i].genero, clientes[i].plano);
    }
}