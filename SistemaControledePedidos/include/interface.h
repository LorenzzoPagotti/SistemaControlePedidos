#ifndef INTERFACE_H
#define INTERFACE_H

#include <curses.h>

#include "../include/cliente.h"
#include "../include/produto.h"
#include "../include/pedido.h"

void inicializarInterface(void);
void finalizarInterface(void);
void limparTela(void);
void mostrarMensagem(const char* mensagem);

int mostrarMenuPrincipal(void);
int mostrarMenuClientes(void);
int mostrarMenuProdutos(void);
int mostrarMenuPedidos(void);

Cliente obterDadosNovoCliente(void);
Produto obterDadosNovoProduto(void);
Pedido obterDadosNovoPedido(void);
int obterIdParaAcao(const char* titulo);

void mostrarListaClientes(Cliente* array, int total);
void mostrarListaProdutos(Produto* array, int total);
void mostrarListaPedidos(Pedido* array, int total);

#endif