#include <stdio.h>
#include <stdlib.h>
#include "../include/persistencia.h"

// --- CLIENTES ---
void carregarClientesCSV(Cliente* array, int* total, int max) {
    FILE* f = fopen("data/Clientes.csv", "r");
    if (!f) return;
    *total = 0;
    char linha[512];
    while (fgets(linha, 512, f) && *total < max) {
        Cliente c;
        sscanf(linha, "%d;%d;%[^;];%s", &c.id, &c.tipo, c.nome, c.cpf_cnpj);
        array[*total] = c;
        (*total)++;
    }
    fclose(f);
}

void salvarClientesCSV(Cliente* array, int total) {
    FILE* f = fopen("data/Clientes.csv", "w");
    if (!f) return;
    for (int i = 0; i < total; i++) {
        fprintf(f, "%d;%d;%s;%s\n", array[i].id, array[i].tipo, array[i].nome, array[i].cpf_cnpj);
    }
    fclose(f);
}

// --- PRODUTOS ---
void carregarProdutosCSV(Produto* array, int* total, int max) {
    FILE* f = fopen("data/Produtos.csv", "r");
    if (!f) return;
    *total = 0;
    char linha[512];
    while (fgets(linha, 512, f) && *total < max) {
        Produto p;
        sscanf(linha, "%d;%[^;];%lf;%d", &p.id, p.descricao, &p.preco, &p.estoque);
        array[*total] = p;
        (*total)++;
    }
    fclose(f);
}

void salvarProdutosCSV(Produto* array, int total) {
    FILE* f = fopen("data/Produtos.csv", "w");
    if (!f) return;
    for (int i = 0; i < total; i++) {
        fprintf(f, "%d;%s;%.2f;%d\n", array[i].id, array[i].descricao, array[i].preco, array[i].estoque);
    }
    fclose(f);
}

void carregarPedidosCSV(Pedido* array, int* total, int max) {
    FILE* f = fopen("data/Pedidos.csv", "r");
    if (!f) return;
    *total = 0;
    char linha[512];
    while (fgets(linha, 512, f) && *total < max) {
        Pedido p;
        sscanf(linha, "%d;%d;%d;%d;%lf", &p.id, &p.clienteId, &p.produtoId, &p.quantidade, &p.total);
        array[*total] = p;
        (*total)++;
    }
    fclose(f);
}

void salvarPedidosCSV(Pedido* array, int total) {
    FILE* f = fopen("data/Pedidos.csv", "w");
    if (!f) return;
    for (int i = 0; i < total; i++) {
        fprintf(f, "%d;%d;%d;%d;%.2f\n", array[i].id, array[i].clienteId, array[i].produtoId, array[i].quantidade, array[i].total);
    }
    fclose(f);
}