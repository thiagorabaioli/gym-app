// escrita_dados.c
#include "escrita_dados.h"
#include "cliente.h"
#include "presenca.h"

char *str_path="C:\\Users\\tfrab\\Downloads\\LP21178\\gym-app\\clientes.csv";
char *str_path_presenca2="C:\\Users\\tfrab\\Downloads\\LP21178\\gym-app\\frequencias.csv";

void ed_escrever_clientes() {

    adicionar_cliente(str_path);
}

void ed_remover_clientes(){
    remover_cliente_id(recebe_id_cliente());
}

void ed_escrever_clientes_no_arquivo(){
    escrever_clientes_no_arquivo(str_path);
}

void ed_inserir_frequencia_id(){
   p_inserir_frequencia_id(str_path_presenca2);
}

float ed_pagamento_id(){
    p_pagamento(str_path_presenca2);
}