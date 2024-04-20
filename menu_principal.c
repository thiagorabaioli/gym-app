// menu_principal.c
#include <stdio.h>
#include "menu_principal.h"

void exibir_menu_principal() {
    printf("\n=== Menu Principal ===\n");
    printf("1. Adicionar novo cliente\n");
    printf("2. Remover cliente\n");
    printf("3. Editar informacao do cliente\n");
    printf("4. Pesquisar cliente\n");
    printf("5. Registrar presença e calcular pagamento\n");
    printf("6. Gerar relatorios\n");
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
