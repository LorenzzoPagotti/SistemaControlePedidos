#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ====================
// Estrutura do Produto
// ====================

typedef struct 
{
    int id;
    double preco;
    int estoque;
    char descricao[100];
} Produto;

int cadastrar_produto(void);
int listar_produto(void);
int consultar_produto(int id);

Produto* get_array_produtos(void);
int* get_total_produtos(void);
int get_max_produtos(void);

#endif