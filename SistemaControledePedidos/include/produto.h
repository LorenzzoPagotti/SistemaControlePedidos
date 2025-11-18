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

// ====================
// Funções
// ====================

// cadastra um produto e grava no arquivo

int cadastrar_produto();
int listar_produto();
int consultar_produto(int id);

#endif
