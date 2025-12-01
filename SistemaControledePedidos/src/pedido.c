#include "../include/pedido.h"
#include "../include/interface.h"
#include <stdio.h>

#define MAX_PEDIDOS 100

static Pedido listaPedidos[MAX_PEDIDOS];
static int totalPedidos = 0;

int cadastrar_pedido(void)
{
    if (totalPedidos >= MAX_PEDIDOS) {
        mostrarMensagem("Erro: Lista de pedidos cheia!");
        return 0;
    }

    // Lógica futura: Pedir ID cliente, validar, pedir produtos...
    // Por enquanto, apenas um placeholder
    mostrarMensagem("Funcionalidade de Cadastrar Pedido em desenvolvimento.");
    return 1;
}

int listar_pedidos(void)
{
    mostrarMensagem("Listagem de pedidos em desenvolvimento.");
    return 1;
}

Pedido* get_array_pedidos() { return listaPedidos; }
int* get_total_pedidos() { return &totalPedidos; }
int get_max_pedidos() { return MAX_PEDIDOS; }