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
    char nome[100];
    char endereco[200];
    char telefone[20];
    char CPF[12];  
    char CNPJ[15];
    char razao_social[100];
    char nome_contato[100];
    char email[100];
} Cliente;

// ====================
// Funções
// ====================

// valida se CPF tem 11 dígitos e é numérico
int valida_cpf(const char *cpf);

// valida se CNPJ tem 14 dígitos e é numérico
int valida_cnpj(const char *cnpj);

// cadastra um cliente e grava no arquivo
int cadastrar_cliente(void);

// consulta cliente no arquivo
int consultar_cliente(int id);

// remove cliente (por id)
int remover_cliente(int id);

// lista todos os clientes
int listar_clientes(void);

#endif
