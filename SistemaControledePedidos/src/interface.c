#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "../include/interface.h"

void inicializarInterface(void) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void finalizarInterface(void) {
    endwin();
}

void limparTela(void) {
    clear();
}

void mostrarMensagem(const char* mensagem) {
    clear();
    mvprintw(10, 5, "%s", mensagem);
    mvprintw(12, 5, "Pressione qualquer tecla...");
    getch();
}

int mostrarMenuPrincipal(void) {
    clear();
    mvprintw(2, 20, "=== SISTEMA PEDIDOS ===");
    mvprintw(4, 20, "1. Clientes");
    mvprintw(5, 20, "2. Produtos");
    mvprintw(6, 20, "3. Pedidos");
    mvprintw(7, 20, "4. Sair");
    mvprintw(9, 20, "Opcao: ");
    
    echo();
    char buf[10];
    getstr(buf);
    noecho();
    return atoi(buf);
}

int mostrarMenuClientes(void) {
    clear();
    mvprintw(2, 20, "--- CLIENTES ---");
    mvprintw(4, 20, "1. Cadastrar");
    mvprintw(5, 20, "2. Listar");
    mvprintw(6, 20, "0. Voltar");
    mvprintw(8, 20, "Opcao: ");
    
    echo();
    char buf[10];
    getstr(buf);
    noecho();
    return atoi(buf);
}

int mostrarMenuProdutos(void) {
    clear();
    mvprintw(2, 20, "--- PRODUTOS ---");
    mvprintw(4, 20, "1. Cadastrar");
    mvprintw(5, 20, "2. Listar");
    mvprintw(8, 20, "Opcao: ");
    echo(); char buf[10]; getstr(buf); noecho();
    return atoi(buf);
}

int mostrarMenuPedidos(void) {
    clear();
    mvprintw(2, 20, "--- PEDIDOS ---");
    mvprintw(4, 20, "1. Cadastrar");
    mvprintw(5, 20, "2. Listar");
    mvprintw(8, 20, "Opcao: ");
    echo(); char buf[10]; getstr(buf); noecho();
    return atoi(buf);
}

// Formulários
Cliente obterDadosNovoCliente(void) {
    Cliente c;
    clear();
    echo(); curs_set(1);
    
    mvprintw(2, 2, "NOVO CLIENTE");
    
    mvprintw(4, 2, "ID: ");
    char buf[20]; getstr(buf); c.id = atoi(buf);
    
    mvprintw(5, 2, "Tipo (1-Fisica, 2-Juridica): ");
    getstr(buf); c.tipo = atoi(buf);
    
    mvprintw(6, 2, "CPF/CNPJ: ");
    getstr(c.cpf_cnpj);
    
    mvprintw(7, 2, "Nome: ");
    getstr(c.nome);
    
    noecho(); curs_set(0);
    return c;
}

Produto obterDadosNovoProduto(void) {
    Produto p;
    clear(); echo(); curs_set(1);
    
    mvprintw(2, 2, "NOVO PRODUTO");
    
    mvprintw(4, 2, "ID: ");
    char buf[20]; getstr(buf); p.id = atoi(buf);
    
    mvprintw(5, 2, "Descricao: ");
    getstr(p.descricao);
    
    mvprintw(6, 2, "Preco: ");
    getstr(buf); p.preco = atof(buf);
    
    mvprintw(7, 2, "Estoque: ");
    getstr(buf); p.estoque = atoi(buf);
    
    noecho(); curs_set(0);
    return p;
}

void mostrarListaClientes(Cliente* array, int qtd) {
    clear();
    mvprintw(1, 2, "LISTAGEM DE CLIENTES");
    for(int i=0; i<qtd; i++) {
        mvprintw(3+i, 2, "#%d | %s | %s", array[i].id, array[i].nome, array[i].cpf_cnpj);
    }
    mvprintw(3+qtd+2, 2, "Tecla para voltar...");
    getch();
}

void mostrarListaProdutos(Produto* array, int qtd) {
    clear();
    mvprintw(1, 2, "LISTAGEM DE PRODUTOS");
    for(int i=0; i<qtd; i++) {
        mvprintw(3+i, 2, "#%d | %s | R$ %.2f | Qt: %d", array[i].id, array[i].descricao, array[i].preco, array[i].estoque);
    }
    mvprintw(3+qtd+2, 2, "Tecla para voltar...");
    getch();
}