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

void remover_pedido(void) {
    if (totalPedidos == 0) {
        mostrarMensagem("Nenhum pedido para remover.");
        return;
    }
    int id = obterIdParaAcao("REMOVER PEDIDO");
    int index = -1;
    
    for(int i=0; i<totalPedidos; i++) {
        if(listaPedidos[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        mostrarMensagem("Pedido nao encontrado.");
        return;
    }

    for(int i=index; i<totalPedidos-1; i++) {
        listaPedidos[i] = listaPedidos[i+1];
    }
    totalPedidos--;
    mostrarMensagem("Pedido removido com sucesso!");
}

void consultar_pedido(void) {
    if (totalPedidos == 0) {
        mostrarMensagem("Nenhum pedido cadastrado.");
        return;
    }
    int id = obterIdParaAcao("CONSULTAR PEDIDO");
    for(int i=0; i<totalPedidos; i++) {
        if(listaPedidos[i].id == id) {
            mostrarDetalhesPedido(&listaPedidos[i]);
            return;
        }
    }
    mostrarMensagem("Pedido nao encontrado.");
}

Pedido* get_array_pedidos(void) { return listaPedidos; }
int* get_total_pedidos(void) { return &totalPedidos; }
int get_max_pedidos(void) { return MAX_PEDIDOS; }