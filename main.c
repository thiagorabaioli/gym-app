// main.c
#include <stdio.h>
#include "cliente.h"
#include "leitura_dados.h"
#include "escrita_dados.h"
#include "controle_presenca.h"
#include "relatorios.h"
#include "menu_principal.h"
#include "cliente.c"
#include "controle_presenca.c"


int main() {

    char *str_path="C:\\Users\\tfrab\\Downloads\\LP\\gym-app\\clientes.csv";
    char *str_frequencias="C:\\Users\\tfrab\\Downloads\\LP\\gym-app\\frequencias.csv";
    int opcao;

    do {
        exibir_menu_principal();
        opcao = obter_opcao_principal();

        switch (opcao) {
            case 1:
               adicionar_cliente(str_path);

                break;
            case 2:
                ler_clientes_do_arquivo(str_path);
               exibir_clientes();
                break;
            case 3:
                ler_clientes_do_arquivo(str_path);
                remover_cliente_id( recebe_id_cliente());
                escrever_clientes_no_arquivo(str_path);
                break;
            case 4:

                break;
            case 5:
                ler_clientes_do_arquivo(str_path);
                pesquisa_cliente_id();
                break;
            case 6:
                ler_presensas_do_arquivo(str_frequencias);
                exibir_frequencias();
                break;
            case 7:
                //calcular_pagamento_id();
                printf("Calcular pagamento \n");
                break;
            case 8:
                printf("Gerar relatorio \n");
               break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
