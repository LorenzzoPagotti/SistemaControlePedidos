#include "../include/cliente.h"
#include "../include/interface.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CLIENTES 100

static Cliente listaClientes[MAX_CLIENTES];
static int totalClientes = 0;

void limpar_documento(const char* origem, char* destino) 
{
    int j = 0;
    for (int i = 0; origem[i] != '\0'; i++) 
    {
        if (isdigit(origem[i])) 
        {
            destino[j] = origem[i];
            j++;
        }
    }
    destino[j] = '\0';
}

int valida_cpf(const char *cpf)
{
    char limpo[20];
    limpar_documento(cpf, limpo);
    if (strlen(limpo) == 11) return 1;
    return 0;
}

int valida_cnpj(const char *cnpj)
{
    char limpo[20];
    limpar_documento(cnpj, limpo);
    if (strlen(limpo) == 14) return 1;
    return 0;
}

void cadastrar_cliente(void) 
{
    if (totalClientes >= MAX_CLIENTES) 
    {
        mostrarMensagem("Erro: Lista cheia!");
        return;
    }

    Cliente novo = obterDadosNovoCliente();

    int valido = 0;
    if (novo.tipo == 1) valido = valida_cpf(novo.cpf_cnpj);
    else valido = valida_cnpj(novo.cpf_cnpj);

    if (valido == 0) 
    {
        mostrarMensagem("Erro: Documento invalido!");
        return;
    }

    for (int i = 0; i < totalClientes; i++) 
    {
        if (listaClientes[i].id == novo.id) 
        {
            mostrarMensagem("Erro: ID ja existe!");
            return;
        }
    }

    listaClientes[totalClientes] = novo;
    totalClientes++;
    
    mostrarMensagem("Cliente salvo com sucesso!");
}

void listar_clientes(void) 
{
    if (totalClientes == 0) 
    {
        mostrarMensagem("Nenhum cliente cadastrado.");
        return;
    }
    mostrarListaClientes(listaClientes, totalClientes);
}

Cliente* get_array_clientes() { return listaClientes; }
int* get_total_clientes() { return &totalClientes; }
int get_max_clientes() { return MAX_CLIENTES; }