#include "../include/interface.h"
#include <stdlib.h>
#include <string.h>

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
    mvprintw(2, 10, "=== SISTEMA ===");
    mvprintw(4, 10, "1. Clientes");
    mvprintw(5, 10, "2. Produtos");
    mvprintw(6, 10, "3. Pedidos");
    mvprintw(7, 10, "4. Sair");
    mvprintw(9, 10, "Opcao: ");
    echo(); char buf[10]; getstr(buf); noecho();
    return atoi(buf);
}

int mostrarMenuClientes(void) {
    clear();
    mvprintw(2, 10, "--- CLIENTES ---");
    mvprintw(4, 10, "1. Cadastrar");
    mvprintw(5, 10, "2. Listar");
    mvprintw(6, 10, "3. Remover");
    mvprintw(8, 10, "0. Voltar");
    mvprintw(10, 10, "Opcao: ");
    echo(); char buf[10]; getstr(buf); noecho();
    return atoi(buf);
}

int mostrarMenuProdutos(void) {
    clear();
    mvprintw(2, 10, "--- PRODUTOS ---");
    mvprintw(4, 10, "1. Cadastrar");
    mvprintw(5, 10, "2. Listar");
    mvprintw(6, 10, "3. Remover");
    mvprintw(8, 10, "0. Voltar");
    mvprintw(10, 10, "Opcao: ");
    echo(); char buf[10]; getstr(buf); noecho();
    return atoi(buf);
}

int mostrarMenuPedidos(void) {
    clear();
    mvprintw(2, 10, "--- PEDIDOS ---");
    mvprintw(4, 10, "1. Cadastrar");
    mvprintw(5, 10, "2. Listar");
    mvprintw(8, 10, "0. Voltar");
    mvprintw(10, 10, "Opcao: ");
    echo(); char buf[10]; getstr(buf); noecho();
    return atoi(buf);
}

Cliente obterDadosNovoCliente(void) {
    Cliente c;
    char buf[100];
    clear(); echo(); curs_set(1);
    mvprintw(2, 2, "NOVO CLIENTE");
    mvprintw(4, 2, "ID: "); getstr(buf); c.id = atoi(buf);
    mvprintw(5, 2, "Tipo (1-Fisica, 2-Jur): "); getstr(buf); c.tipo = atoi(buf);
    mvprintw(6, 2, "CPF/CNPJ: "); getstr(c.cpf_cnpj);
    mvprintw(7, 2, "Nome: "); getstr(c.nome);
    noecho(); curs_set(0);
    return c;
}

Produto obterDadosNovoProduto(void) {
    Produto p;
    char buf[100];
    clear(); echo(); curs_set(1);
    mvprintw(2, 2, "NOVO PRODUTO");
    mvprintw(4, 2, "ID: "); getstr(buf); p.id = atoi(buf);
    mvprintw(5, 2, "Descricao: "); getstr(p.descricao);
    mvprintw(6, 2, "Preco: "); getstr(buf); p.preco = atof(buf);
    mvprintw(7, 2, "Estoque: "); getstr(buf); p.estoque = atoi(buf);
    noecho(); curs_set(0);
    return p;
}

Pedido obterDadosNovoPedido(void) {
    Pedido p;
    char buf[100];
    clear(); echo(); curs_set(1);
    mvprintw(2, 2, "NOVO PEDIDO");
    mvprintw(4, 2, "ID Pedido: "); getstr(buf); p.id = atoi(buf);
    mvprintw(5, 2, "ID Cliente: "); getstr(buf); p.clienteId = atoi(buf);
    mvprintw(6, 2, "ID Produto: "); getstr(buf); p.produtoId = atoi(buf);
    mvprintw(7, 2, "Quantidade: "); getstr(buf); p.quantidade = atoi(buf);
    mvprintw(8, 2, "Valor Total: "); getstr(buf); p.total = atof(buf);
    noecho(); curs_set(0);
    return p;
}

int obterIdParaAcao(const char* titulo) {
    int id;
    char buf[20];
    clear(); echo(); curs_set(1);
    mvprintw(2, 2, "%s", titulo);
    mvprintw(4, 2, "Informe o ID: ");
    getstr(buf);
    id = atoi(buf);
    noecho(); curs_set(0);
    return id;
}

void mostrarListaClientes(Cliente* array, int total) {
    clear();
    mvprintw(1, 2, "CLIENTES");
    for(int i=0; i<total; i++) {
        mvprintw(3+i, 2, "#%d | %s | %s", array[i].id, array[i].nome, array[i].cpf_cnpj);
    }
    mvprintw(3+total+2, 2, "Voltar..."); getch();
}

void mostrarListaProdutos(Produto* array, int total) {
    clear();
    mvprintw(1, 2, "PRODUTOS");
    for(int i=0; i<total; i++) {
        mvprintw(3+i, 2, "#%d | %s | R$%.2f", array[i].id, array[i].descricao, array[i].preco);
    }
    mvprintw(3+total+2, 2, "Voltar..."); getch();
}

void mostrarListaPedidos(Pedido* array, int total) {
    clear();
    mvprintw(1, 2, "PEDIDOS");
    for(int i=0; i<total; i++) {
        mvprintw(3+i, 2, "#%d | Cli: %d | Prod: %d | Qtd: %d", array[i].id, array[i].clienteId, array[i].produtoId, array[i].quantidade);
    }
    mvprintw(3+total+2, 2, "Voltar..."); getch();
}