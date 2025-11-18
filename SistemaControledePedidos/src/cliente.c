
#include "\SistemaControledePedidos\include\cliente.h"
#include "\SistemaControledePedidos\include\interface.h"
#include <string.h>
#include <ctype.h>

// o olegario pediu para definir a quantidade máxima de clientes na memoria.
#define MAX_CLIENTES 100

// isso aqui é um array de struct de clientes, ele vai armazenar os dados do cliente enquanto o programa roda
static Cliente listaClientes[MAX_CLIENTES];
static int totalClientes = 0; // quantos clientes tem armazenados no programa

// ====================
// Funções de Validação
// ====================

void limpar_documento(const char* origem, char* destino) 
{
    int j = 0;
    for (int i = 0; origem[i] != '\0'; i++) 
    {
        if (isdigit(origem[i])) 
        {
            destino[j++] = origem[i];
        }
    }
    destino[j] = '\0';
}

int valida_cpf(const char *cpf)
{
    if (cpf == NULL) // seguranca
        return 0;

    if (strlen(cpf) != 11) // seguranca
        return 0;

    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(cpf[i]))
            return 0;
    }
    
    return 1; // CPF é valido
}

int valida_cnpj(const char *cnpj)
{
    if (cnpj == NULL)
        return 0; // seguranca

    if (strlen(cnpj) != 14)
        return 0; // seguranca

    for (int i = 0; i < 14; i++)
    {
        if (!isdigit(cnpj[i]))
            return 0;
    }
    
    return 1; // CNPJ é válido
}

void cadastrar_cliente(void) 
{
    if (totalClientes >= MAX_CLIENTES) 
    {
        mostrarMensagem("Erro: Memoria cheia para novos clientes!");
        return;
    }

    Cliente novoCliente = obterDadosNovoCliente();

    int valido = 0;
    if (novoCliente.tipo == 1) // tipo 1 pode ser de pessoa fisica
    { 
        valido = valida_cpf(novoCliente.cpf_cnpj);
    }
    else // aqui e pra pessoa juridica
    { 
        valido = valida_cnpj(novoCliente.cpf_cnpj);
    }

    if (!valido) 
    {
        mostrarMensagem("Erro: CPF ou CNPJ invalido! Cadastro cancelado.");
        return;
    }
    // aqui ele verifica se o cliente (id) ja existe antes de adicionar!
    for (int i = 0; i < totalClientes; i++) 
    {
        if (listaClientes[i].id == novoCliente.id) 
        {
            mostrarMensagem("Erro: ID ja existente!");
            return;
        }
    }

    listaClientes[totalClientes] = novoCliente;
    totalClientes++;
    mostrarMensagem("Cliente cadastrado com sucesso!"); // e adiciona na memoria
}

// funcoes getter para pegar as informacoes do cliente.c e poder ser acessadas por outros lugares

Cliente* get_array_clientes() 
{
    return listaClientes;
}

int* get_total_clientes() 
{
    return &totalClientes;
}

int get_max_clientes()
{
    return MAX_CLIENTES;
}