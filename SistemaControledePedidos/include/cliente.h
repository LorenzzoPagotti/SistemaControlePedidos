#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ====================
// Estrutura do Cliente
// ====================

typedef struct
{
    int id;
    int tipo;
    char nome[100];
    char endereco[200];
    char telefone[20];
    char cpf_cnpj[20];
    char razao_social[100];
    char nome_contato[100];
    char email[100];
} Cliente;

// ====================
// Funções
// ====================

int valida_cpf(const char *cpf);
int valida_cnpj(const char *cnpj);
void cadastrar_cliente();
void listar_clientes();

#endif
