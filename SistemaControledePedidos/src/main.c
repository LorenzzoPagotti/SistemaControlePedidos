#include "../include/interface.h"
#include "../include/persistencia.h"
#include "../include/cliente.h"
#include "../include/produto.h"
#include "../include/pedido.h"

int main(void) {
    carregarClientesCSV(get_array_clientes(), get_total_clientes(), get_max_clientes());
    carregarProdutosCSV(get_array_produtos(), get_total_produtos(), get_max_produtos());
    carregarPedidosCSV(get_array_pedidos(), get_total_pedidos(), get_max_pedidos());

    inicializarInterface();

    int rodando = 1;
    while (rodando) {
        int opcao = mostrarMenuPrincipal();
        switch (opcao) {
            case 1: { // clientes :)
                int opt = mostrarMenuClientes();
                if (opt == 1) cadastrar_cliente();
                if (opt == 2) listar_clientes();
                if (opt == 3) remover_cliente(); 
                if (opt == 4) consultar_cliente();
                break;
            }
            case 2: { // produtos :)
                int opt = mostrarMenuProdutos();
                if (opt == 1) cadastrar_produto();
                if (opt == 2) listar_produtos();
                if (opt == 3) remover_produto();
                if (opt == 4) consultar_produto_visual();
                break;
            }
            case 3: { // pedidos :)
                int opt = mostrarMenuPedidos();
                if (opt == 1) cadastrar_pedido();
                if (opt == 2) listar_pedidos();
                if (opt == 3) remover_pedido();
                if (opt == 4) consultar_pedido();
                break;
            }
            case 4: 
                rodando = 0; 
                break;
        }
    }

    salvarClientesCSV(get_array_clientes(), *get_total_clientes());
    salvarProdutosCSV(get_array_produtos(), *get_total_produtos());
    salvarPedidosCSV(get_array_pedidos(), *get_total_pedidos());

    finalizarInterface();
    return 0;
}