#include <stdlib.h>
#include "../include/interface.h"
#include "../include/persistencia.h"
#include "../include/cliente.h"
#include "../include/produto.h"
#include "../include/pedido.h"

int main(void)
{
    carregarClientesCSV(get_array_clientes(), get_total_clientes(), get_max_clientes());
    carregarProdutosCSV(get_array_produtos(), get_total_produtos(), get_max_produtos());
    
    inicializarInterface();

    int rodando = 1;
    while (rodando)
    {
        int opcao = mostrarMenuPrincipal();

        switch (opcao)
        {
        case 1:
            {
                int opt = mostrarMenuClientes();
                if (opt == 1) cadastrar_cliente();
                if (opt == 2) listar_clientes();
            }
            break;

        case 2:
            {
                int opt = mostrarMenuProdutos();
                if (opt == 1) cadastrar_produto();
                if (opt == 2) listar_produto();
            }
            break;

        case 3:
            {
                int opt = mostrarMenuPedidos();
                if (opt == 1) cadastrar_pedido();
                if (opt == 2) listar_pedido();
            }
            break;

        case 4:
            rodando = 0;
            break;
            
        default:
            break;
        }
    }

    salvarClientesCSV(get_array_clientes(), *get_total_clientes());
    salvarProdutosCSV(get_array_produtos(), *get_total_produtos());

    finalizarInterface();
    return 0;
}