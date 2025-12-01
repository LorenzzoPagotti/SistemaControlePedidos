#ifndef INTERFACE_H
#define INTERFACE_H

#include <ncurses.h> // precisa disso daqui

#include "../include/cliente.h"
#include "produto.h"
#include "pedido.h"

// funcoes de controle de UI:

// inicia a tela do ncurses (chama na main)
void inicializarInterface(void);

// fecha a tela do ncurses e restaura o terminal (chama no final do codigo, na main)
void finalizarInterface(void);

void limparTela(void);

// mostra uma mensagem simples na tela
void mostrarMensagem(const char* mensagem);

// Pausa a execução (espera o usuario apertar uma tecla, por exemplo)
void pausarInterface(void);

// funcoes de menu em baixo:

// mostra o menu principal e devolve a escolha do usuário (1, 2, 3...)
int mostrarMenuPrincipal(void);

// mostra o menu de clientes e devolve a escolha
int mostrarMenuClientes(void);

// mostra o menu de produtos e devolve a escolha
int mostrarMenuProdutos(void);

// mostra o menu de pedidos e devolve a escolha
int mostrarMenuPedidos(void);

// funcao de exibicao (mostrar)

// mostra a lista de clientes formatada na tela da interface
void mostrarListaClientes(Cliente* arrayClientes, int totalClientes);

// funcao de dados

Cliente obterDadosNovoCliente(void);

#endif