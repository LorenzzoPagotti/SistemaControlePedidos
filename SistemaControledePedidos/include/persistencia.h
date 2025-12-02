#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "../include/cliente.h"
#include "../include/produto.h"
#include "../include/pedido.h"

void carregarClientesCSV(Cliente* arrayClientes, int* totalClientes, int maxClientes);
void salvarClientesCSV(Cliente* arrayClientes, int totalClientes);

void carregarProdutosCSV(Produto* arrayProdutos, int* totalProdutos, int maxProdutos);
void salvarProdutosCSV(Produto* arrayProdutos, int totalProdutos);

#endif