#include "../include/cliente.h"
#include "../include/interface.h"
#include <string.h>
#include <ctype.h>

#define MAX_CLIENTES 100

static Cliente listaClientes[MAX_CLIENTES];
static int totalClientes = 0;

void limpar_documento(const char* origem, char* destino) {
    int j = 0;
    for (int i = 0; origem[i] != '\0'; i++) {
        if (isdigit(origem[i])) {
            destino[j++] = origem[i];
        }
    }
    destino[j] = '\0';
}

int valida_cpf(const char *cpf) {
    char limpo[20];
    limpar_documento(cpf, limpo);
    return (strlen(limpo) == 11);
}

int valida_cnpj(const char *cnpj) {
    char limpo[20];
    limpar_documento(cnpj, limpo);
    return (strlen(limpo) == 14);
}

void cadastrar_cliente(void) {
    if (totalClientes >= MAX_CLIENTES) {
        mostrarMensagem("Erro: Lista cheia!");
        return;
    }
    Cliente novo = obterDadosNovoCliente();
    
    int valido = (novo.tipo == 1) ? valida_cpf(novo.cpf_cnpj) : valida_cnpj(novo.cpf_cnpj);
    if (!valido) {
        mostrarMensagem("Documento invalido!");
        return;
    }

    for (int i = 0; i < totalClientes; i++) {
        if (listaClientes[i].id == novo.id) {
            mostrarMensagem("Erro: ID ja existe!");
            return;
        }
    }

    listaClientes[totalClientes] = novo;
    totalClientes++;
    mostrarMensagem("Cliente salvo!");
}

void listar_clientes(void) {
    if (totalClientes == 0) {
        mostrarMensagem("Nenhum cliente cadastrado.");
        return;
    }
    mostrarListaClientes(listaClientes, totalClientes);
}

void remover_cliente(void) {
    if (totalClientes == 0) {
        mostrarMensagem("Nenhum cliente para remover.");
        return;
    }
    int id = obterIdParaAcao("REMOVER CLIENTE");
    int index = -1;
    
    for(int i=0; i<totalClientes; i++) {
        if(listaClientes[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        mostrarMensagem("Cliente nao encontrado.");
        return;
    }

    for(int i=index; i<totalClientes-1; i++) {
        listaClientes[i] = listaClientes[i+1];
    }
    totalClientes--;
    mostrarMensagem("Cliente removido com sucesso!");
}

Cliente* get_array_clientes(void) { return listaClientes; }
int* get_total_clientes(void) { return &totalClientes; }
int get_max_clientes(void) { return MAX_CLIENTES; }