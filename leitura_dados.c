// leitura_dados.h
#ifndef LEITURA_DADOS_H
#define LEITURA_DADOS_H

#include "cliente.h"
#include "presenca.h"

char *str_path_leitura="C:\\Users\\tfrab\\Downloads\\LP21178\\gym-app\\clientes.csv";

char *str_path_presenca="C:\\Users\\tfrab\\Downloads\\LP21178\\gym-app\\frequencias.csv";

void ld_ler_clientes_do_arquivo(){ler_clientes_do_arquivo(str_path_leitura);}

void ld_exibir_clientes(){exibir_clientes();}

void ld_pesquisa_cliente_id() {pesquisa_cliente_id();}

void ld_ler_clientes_presenca() {ler_clientes_presenca(str_path_presenca);}

void ld_exibir_presencas(){exibir_presencas();}



#endif
