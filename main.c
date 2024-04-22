// main.c
#include <stdio.h>
#include "cliente.h"
#include "leitura_dados.h"
#include "escrita_dados.h"
#include "controle_presenca.h"
#include "relatorios.h"
#include "menu_principal.h"
#include "cliente.c"


int main() {

    char *str_path="C:\\Users\\tfrab\\Downloads\\LP\\gym-app\\clientes.csv";
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
            case 6:
                // Lógica para gerar relatórios
                break;
            case 7:
                // Lógica para gerar relatórios
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
