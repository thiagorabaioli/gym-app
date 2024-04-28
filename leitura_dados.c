// leitura_dados.h
#ifndef LEITURA_DADOS_H
#define LEITURA_DADOS_H

#include "cliente.h"


char *str_path_leitura="C:\\Users\\tfrab\\Downloads\\LP21178\\gym-app\\clientes.csv";

void ld_ler_clientes_do_arquivo(){ler_clientes_do_arquivo(str_path_leitura);}

void ld_exibir_clientes(){exibir_clientes();}

void ld_pesquisa_cliente_id() {pesquisa_cliente_id();}
#endif
