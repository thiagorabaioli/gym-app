#include <stdio.h>
#include "cliente.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define MAX_CLIENTES 100 // Define o número máximo de clientes que o programa pode armazenar
int num_clientes = 0; // Variável para rastrear o número atual de clientes

Cliente clientes[MAX_CLIENTES]; // Array para armazenar os clientes
// Variável para rastrear o número atual de clientes

void adicionar_cliente() {
    // Verifica se o limite máximo de clientes foi atingido
    if (num_clientes >= MAX_CLIENTES) {
        printf("Limite máximo de clientes atingido!\n");
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


    // Incrementar o número de clientes após adicionar um novo cliente
    num_clientes++;

    printf("Novo cliente adicionado com sucesso!\n");
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


    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256]; // Buffer para armazenar cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Extrai os dados de cada linha usando sscanf()
        sscanf(linha, "%[^,],%d,%c,%[^,\n]", clientes[num_clientes].nome, &clientes[num_clientes].idade,
               &clientes[num_clientes].genero, clientes[num_clientes].plano);
        num_clientes++; // Incrementa o número de clientes
    }

    fclose(arquivo); // Fecha o arquivo após a leitura
}

void exibir_clientes() {
    printf("Clientes:\n");
    for (int i = 0; i < num_clientes; i++) {
        printf("Nome: %s, Idade: %d, Gênero: %c, Plano de Treino: %s\n",
               clientes[i].nome, clientes[i].idade, clientes[i].genero, clientes[i].plano);
    }
}