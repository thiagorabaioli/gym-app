// menu_principal.c
#include <stdio.h>
#include "menu_principal.h"

void exibir_menu_principal() {
    printf("\n=== Menu Principal ===\n");
    printf("1. Adicionar novo cliente\n");
    printf("2.Mostrar clientes do ficheiro\n");
    printf("3. Remover cliente\n");
    printf("4. Editar cliente\n");
    printf("5. Pesquisar cliente por ID: \n");
    printf("6. Mostrar Frequencias\n");
    printf("7. Adicionar Frequencia\n");
    printf("8. Calcular pagamento\n");
    printf("9. Gerar relatorios\n");
    printf("0. Sair do programa\n");
    printf("Opcao: ");
}

int obter_opcao_principal() {
    int opcao;
    printf("Aguardando entrada do usuario...\n"); // Mensagem de depuração
    scanf("%d", &opcao);
    while(getchar() != '\n'); // Limpa o buffer de entrada
    return opcao;
}

