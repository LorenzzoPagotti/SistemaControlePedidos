#ifndef PEDIDO_H
#define PEDIDO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ====================
// Estrutura do Pedido
// ====================

typedef struct
{
    int id;
    int clientId;
    int dia, mes, ano;
    double total;

} Pedido;

// ====================
// Funções
// ====================

// cadastra um pedido e grava no arquivo

int cadastrar_pedido(void)
{
}

int analisa_pedido(void)
{
}

int cadastrar_item_pedido(int id)
{
}

#endif
