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
    mvprintw(2, 10, "=== SISTEMA DE PEDIDOS ===");
    mvprintw(4, 10, "1. Clientes");
    mvprintw(5, 10, "2. Produtos");
    mvprintw(6, 10, "3. Pedidos");
    mvprintw(7, 10, "4. Sair");
    mvprintw(9, 10, "Escolha: ");
    
    echo(); 
    char buffer[10];
    getstr(buffer);
    noecho();
    
    return atoi(buffer);
}

int mostrarMenuClientes(void) {
    clear();
    mvprintw(2, 10, "--- CLIENTES ---");
    mvprintw(4, 10, "1. Cadastrar");
    mvprintw(5, 10, "2. Listar");
    mvprintw(6, 10, "0. Voltar");
    mvprintw(8, 10, "Opcao: ");
    
    echo(); char buffer[10]; getstr(buffer); noecho();
    return atoi(buffer);
}

int mostrarMenuProdutos(void) {
    clear();
    mvprintw(2, 10, "--- PRODUTOS ---");
    mvprintw(4, 10, "1. Cadastrar");
    mvprintw(5, 10, "2. Listar");
    mvprintw(8, 10, "Opcao: ");
    echo(); char buffer[10]; getstr(buffer); noecho();
    return atoi(buffer);
}

int mostrarMenuPedidos(void) {
    clear();
    mvprintw(2, 10, "--- PEDIDOS ---");
    mvprintw(4, 10, "1. Cadastrar");
    mvprintw(5, 10, "2. Listar");
    mvprintw(8, 10, "Opcao: ");
    echo(); char buffer[10]; getstr(buffer); noecho();
    return atoi(buffer);
}

Cliente obterDadosNovoCliente(void) {
    Cliente c;
    char buffer[100];
    
    clear();
    echo(); 
    curs_set(1);
    
    mvprintw(2, 2, "NOVO CLIENTE");
    
    mvprintw(4, 2, "ID (numero): ");
    getstr(buffer); c.id = atoi(buffer);
    
    mvprintw(5, 2, "Tipo (1-Fisica, 2-Juridica): ");
    getstr(buffer); c.tipo = atoi(buffer);
    
    mvprintw(6, 2, "CPF ou CNPJ (so numeros): ");
    getstr(c.cpf_cnpj);
    
    mvprintw(7, 2, "Nome: ");
    getstr(c.nome);
    
    noecho(); 
    curs_set(0);
    return c;
}

Produto obterDadosNovoProduto(void) {
    Produto p;
    char buffer[100];
    
    clear(); 
    echo(); 
    curs_set(1);
    
    mvprintw(2, 2, "NOVO PRODUTO");
    
    mvprintw(4, 2, "ID: ");
    getstr(buffer); p.id = atoi(buffer);
    
    mvprintw(5, 2, "Descricao: ");
    getstr(p.descricao);
    
    mvprintw(6, 2, "Preco: ");
    getstr(buffer); p.preco = atof(buffer);
    
    mvprintw(7, 2, "Estoque: ");
    getstr(buffer); p.estoque = atoi(buffer);
    
    noecho(); 
    curs_set(0);
    return p;
}

void mostrarListaClientes(Cliente* array, int qtd) {
    clear();
    mvprintw(1, 2, "LISTA DE CLIENTES");
    mvprintw(2, 2, "ID   | NOME                 | DOC");
    mvprintw(3, 2, "------------------------------------");
    
    for(int i = 0; i < qtd; i++) {
        mvprintw(4+i, 2, "%d   | %s           | %s", 
                 array[i].id, array[i].nome, array[i].cpf_cnpj);
    }
    
    mvprintw(4+qtd+2, 2, "Pressione qualquer tecla para voltar...");
    getch();
}

void mostrarListaProdutos(Produto* array, int qtd) {
    clear();
    mvprintw(1, 2, "LISTA DE PRODUTOS");
    
    for(int i = 0; i < qtd; i++) {
        mvprintw(3+i, 2, "#%d | %s | R$ %.2f", 
                 array[i].id, array[i].descricao, array[i].preco);
    }
    
    mvprintw(3+qtd+2, 2, "Pressione qualquer tecla para voltar...");
    getch();
}