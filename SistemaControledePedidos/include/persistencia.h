#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "../include/cliente.h"
#include "../include/produto.h"
#include "../include/pedido.h"

void carregarClientesCSV(Cliente* array, int* total, int max);
void salvarClientesCSV(Cliente* array, int total);

void carregarProdutosCSV(Produto* array, int* total, int max);
void salvarProdutosCSV(Produto* array, int total);

void carregarPedidosCSV(Pedido* array, int* total, int max);
void salvarPedidosCSV(Pedido* array, int total);

#endif