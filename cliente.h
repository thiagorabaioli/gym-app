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

//Escrita de clientes

void adicionar_cliente(const char* nome_arquivo);
void remover_cliente_id(int id);
int recebe_id_cliente();
void escrever_clientes_no_arquivo(const char* nome_arquivo);

//Leitura de clientes
void  ler_clientes_do_arquivo(const char* nome_arquivo);

void exibir_clientes();

void pesquisa_cliente_id();

void ler_clientes_presenca();

void exibir_presencas();


#endif
