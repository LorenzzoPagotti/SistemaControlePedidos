#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "cliente.h"
#include "produto.h"
#include "pedido.h"

// ========================
// Funções
// ========================

// Carrega os clientes do "Clientes.csv" para o array
void carregarClientesCSV(Cliente* arrayClientes, int* totalClientes, int maxClientes);

// Salva os clientes do array para o "Clientes.csv"
void salvarClientesCSV(Cliente* arrayClientes, int totalClientes);

// --- Produtos ---

// Carrega os produtos do "Produtos.csv" para o array
void carregarProdutosCSV(Produto* arrayProdutos, int* totalProdutos, int maxProdutos);

// Salva os produtos do array para o "Produtos.csv"
void salvarProdutosCSV(Produto* arrayProdutos, int totalProdutos);

// --- Pedidos ---

// Carrega os pedidos do "Pedidos.csv" para o array
void carregarPedidosCSV(Pedido* arrayPedidos, int* totalPedidos, int maxPedidos);

// Salva os pedidos do array para o "Pedidos.csv"
void salvarPedidosCSV(Pedido* arrayPedidos, int totalPedidos);

#endif