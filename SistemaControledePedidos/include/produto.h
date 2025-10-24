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

int cadastrar_produto(void)
{
}

int analisa_produto(void)
{
}

// consulta produto do arquivo
int consultar_produto(int id)
{
}

// remove produto do arquivo
int remover_produto(int id)
{
}

// lista prrodutos do arquivo
int listar_produto(void)
{
}

#endif
