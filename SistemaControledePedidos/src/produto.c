#include "../include/produto.h"
#include "../include/interface.h"

#define MAX_PRODUTOS 100

static Produto listaProdutos[MAX_PRODUTOS];
static int totalProdutos = 0;

int cadastrar_produto(void) {
    if (totalProdutos >= MAX_PRODUTOS) {
        mostrarMensagem("Erro: Estoque cheio!");
        return 0;
    }
    Produto p = obterDadosNovoProduto(); 

    for(int i = 0; i < totalProdutos; i++) {
        if(listaProdutos[i].id == p.id) {
            mostrarMensagem("Erro: ID ja existe.");
            return 0;
        }
    }

    listaProdutos[totalProdutos] = p;
    totalProdutos++;
    mostrarMensagem("Produto cadastrado!");
    return 1;
}

int listar_produtos(void) {
    if (totalProdutos == 0) {
        mostrarMensagem("Nenhum produto cadastrado.");
        return 0;
    }
    mostrarListaProdutos(listaProdutos, totalProdutos);
    return 1;
}

void remover_produto(void) {
    if (totalProdutos == 0) {
        mostrarMensagem("Nenhum produto para remover.");
        return;
    }
    int id = obterIdParaAcao("REMOVER PRODUTO");
    int index = -1;
    
    for(int i=0; i<totalProdutos; i++) {
        if(listaProdutos[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        mostrarMensagem("Produto nao encontrado.");
        return;
    }

    for(int i=index; i<totalProdutos-1; i++) {
        listaProdutos[i] = listaProdutos[i+1];
    }
    totalProdutos--;
    mostrarMensagem("Produto removido!");
}

int consultar_produto(int id) {
    for(int i = 0; i < totalProdutos; i++) {
        if(listaProdutos[i].id == id) return i;
    }
    return -1;
}

Produto* get_array_produtos(void) { return listaProdutos; }
int* get_total_produtos(void) { return &totalProdutos; }
int get_max_produtos(void) { return MAX_PRODUTOS; }