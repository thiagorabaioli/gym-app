// main.c
#include <stdio.h>
#include "leitura_dados.h"
#include "escrita_dados.h"
#include "menu_principal.h"
#include "cliente.c"
#include "controle_presenca.h"


int main() {

    char *str_path="C:\\Users\\tfrab\\Downloads\\LP21178\\gym-app\\clientes.csv";
    char *str_frequencias="C:\\Users\\tfrab\\Downloads\\LP21178\\gym-app\\frequencias.csv";
    int opcao;

    do {

        exibir_menu_principal();
        opcao = obter_opcao_principal();
        ler_clientes_do_arquivo(str_path); //Carrega os dados na memória de clientes.csv
        ld_ler_clientes_presenca(); //Carrega os dados na meméria de frequencias.csv

        switch (opcao) {
            case 1:
               ed_escrever_clientes(str_path);

                break;
            case 2:
                ld_exibir_clientes();
                break;
            case 3:
                ed_remover_clientes();
                ed_escrever_clientes_no_arquivo();
                break;
            case 4:

                break;
            case 5:
                ld_pesquisa_cliente_id();
                break;
            case 6:
                ld_exibir_presencas();
                break;
            case 7:
                p_inserir_frequencia_id(str_frequencias);
                break;
            case 8:
                printf("Calcular pagamento \n");

                ed_pagamento_id();
                break;
            case 9:
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
