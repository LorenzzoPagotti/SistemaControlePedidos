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
    int pedidoId;
    int produtoId;
    int quantidade;
    float subtotal; // isso seria "quantidade X preco"
} ItemPedido;

typedef struct 
{
    int id;
    int clienteId;
    char data[11]; // dia/mes/ano (DD/MM/AAA), com 2 digitos no dia, 2 digitos no mes e 4 digitos para os anos
    double total;
} Pedido;

// ====================
// Funções
// ====================

int cadastrar_pedido();
int listar_pedido();

#endif
