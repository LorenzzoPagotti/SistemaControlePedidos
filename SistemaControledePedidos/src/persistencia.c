#include <stdio.h>
#include <stdlib.h>
#include "../include/persistencia.h"

void carregarClientesCSV(Cliente* arrayClientes, int* totalClientes, int maxClientes) {
    FILE* f = fopen("../data/Clientes.csv", "r");
    if (!f) return; // sem arquivo

    *totalClientes = 0;
    char linha[512];
    
  

    while (fgets(linha, sizeof(linha), f) && *totalClientes < maxClientes) {
        Cliente c;
        // Formato: id;tipo;nome;doc
        sscanf(linha, "%d;%d;%[^;];%s", &c.id, &c.tipo, c.nome, c.cpf_cnpj);
        arrayClientes[*totalClientes] = c;
        (*totalClientes)++;
    }
    fclose(f);
}

void salvarClientesCSV(Cliente* arrayClientes, int totalClientes) {
    FILE* f = fopen("../data/Clientes.csv", "w");
    if (!f) return;

    for (int i = 0; i < totalClientes; i++) {
        fprintf(f, "%d;%d;%s;%s\n", 
            arrayClientes[i].id, 
            arrayClientes[i].tipo, 
            arrayClientes[i].nome, 
            arrayClientes[i].cpf_cnpj);
    }
    fclose(f);
}

// === PRODUTOS ===
void carregarProdutosCSV(Produto* arrayProdutos, int* totalProdutos, int maxProdutos) {
    FILE* f = fopen("../data/Produtos.csv", "r");
    if (!f) return;

    *totalProdutos = 0;
    char linha[512];
    while (fgets(linha, sizeof(linha), f) && *totalProdutos < maxProdutos) {
        Produto p;
        // id;descricao;preco;estoque
        sscanf(linha, "%d;%[^;];%lf;%d", &p.id, p.descricao, &p.preco, &p.estoque);
        arrayProdutos[*totalProdutos] = p;
        (*totalProdutos)++;
    }
    fclose(f);
}

void salvarProdutosCSV(Produto* arrayProdutos, int totalProdutos) {
    FILE* f = fopen("../data/Produtos.csv", "w");
    if (!f) return;

    for (int i = 0; i < totalProdutos; i++) {
        fprintf(f, "%d;%s;%.2f;%d\n", 
            arrayProdutos[i].id, 
            arrayProdutos[i].descricao, 
            arrayProdutos[i].preco, 
            arrayProdutos[i].estoque);
    }
    fclose(f);
}