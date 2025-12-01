#include "../include/produto.h"
#include "../include/interface.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUTOS 100

static Produto listaProdutos[MAX_PRODUTOS];
static int totalProdutos = 0;

int cadastrar_produto(void)
{
    if (totalProdutos >= MAX_PRODUTOS) 
    {
        mostrarMensagem("Erro: Estoque cheio!");
        return 0;
    }

    // Pega dados da tela (precisa adicionar obterDadosNovoProduto no interface.c/.h)
    // Vou deixar simplificado simulando que a função existe na interface
    Produto p = obterDadosNovoProduto(); 

    for(int i = 0; i < totalProdutos; i++)
    {
        if(listaProdutos[i].id == p.id)
        {
            mostrarMensagem("Erro: ID de produto ja existe.");
            return 0;
        }
    }

    listaProdutos[totalProdutos] = p;
    totalProdutos++;
    mostrarMensagem("Produto cadastrado!");
    return 1;
}

int listar_produto(void)
{
    if (totalProdutos == 0)
    {
        mostrarMensagem("Nenhum produto cadastrado.");
        return 0;
    }
    mostrarListaProdutos(listaProdutos, totalProdutos);
    return 1;
}

int consultar_produto(int id)
{
    for(int i = 0; i < totalProdutos; i++)
    {
        if(listaProdutos[i].id == id) return i;
    }
    return -1; 
}


Produto* get_array_produtos() { return listaProdutos; }
int* get_total_produtos() { return &totalProdutos; }
int get_max_produtos() { return MAX_PRODUTOS; }