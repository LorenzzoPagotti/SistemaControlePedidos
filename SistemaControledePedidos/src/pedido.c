#include "../include/pedido.h"
#include "../include/interface.h"
#include "../include/cliente.h"
#include "../include/produto.h"

#define MAX_PEDIDOS 100

static Pedido listaPedidos[MAX_PEDIDOS];
static int totalPedidos = 0;

int cadastrar_pedido(void) {
    if (totalPedidos >= MAX_PEDIDOS) {
        mostrarMensagem("Erro: Lista cheia!");
        return 0;
    }

    Pedido p = obterDadosNovoPedido();

    listaPedidos[totalPedidos] = p;
    totalPedidos++;
    mostrarMensagem("Pedido registrado com sucesso!");
    return 1;
}

int listar_pedidos(void) {
    if (totalPedidos == 0) {
        mostrarMensagem("Nenhum pedido registrado.");
        return 0;
    }
    mostrarListaPedidos(listaPedidos, totalPedidos);
    return 1;
}

Pedido* get_array_pedidos(void) { return listaPedidos; }
int* get_total_pedidos(void) { return &totalPedidos; }
int get_max_pedidos(void) { return MAX_PEDIDOS; }