// escrita_dados.c
#include "escrita_dados.h"
#include "cliente.h"

char *str_path="C:\\Users\\tfrab\\Downloads\\LP21178\\gym-app\\clientes.csv";

void ed_escrever_clientes() {

    adicionar_cliente(str_path);
}

void ed_remover_clientes(){
    remover_cliente_id(recebe_id_cliente());
}

void ed_escrever_clientes_no_arquivo(){
    escrever_clientes_no_arquivo(str_path);
}