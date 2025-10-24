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

// cadastra um cliente e grava no arquivo

int cadastrar_produto(void)
{
}

int analisa_produto(void)
{
}

int consultar_produto(int id)
{
}

int remover_produto(int id)
{
}

int listar_produto(void)
{
}

#endif
