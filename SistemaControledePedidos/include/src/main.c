#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int selecao;

    do
    {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Manter Produtos\n");
        printf("2. Manter Clientes\n");
        printf("3. Manter Pedidos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &selecao) != 1)
        {
            printf("Opcao invalida. Tente novamente.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            selecao = -1;
            continue;
        }

        switch (selecao)
        {
        // =====================================================
        case 1: // MANTER PRODUTOS
        {
            int opcao_produto;
            do
            {
                printf("\n--- MANTER PRODUTOS ---\n");
                printf("1. Cadastrar Novo Produto\n");
                printf("2. Remover Produto Cadastrado\n");
                printf("3. Consultar Produto Cadastrado\n");
                printf("4. Listar Produtos Cadastrados\n");
                printf("0. Voltar\n");
                printf("Escolha uma opcao: ");

                if (scanf("%d", &opcao_produto) != 1)
                {
                    printf("Opcao invalida. Tente novamente.\n");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    opcao_produto = -1;
                    continue;
                }

                switch (opcao_produto)
                {
                case 1:
                    printf("-> Cadastrar novo produto (futura funcao)\n");
                    break;
                case 2:
                    printf("-> Remover produto cadastrado (futura funcao)\n");
                    break;
                case 3:
                    printf("-> Consultar produto cadastrado (futura funcao)\n");
                    break;
                case 4:
                    printf("-> Listar produtos cadastrados (futura funcao)\n");
                    break;
                case 0:
                    printf("Voltando ao menu principal...\n");
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                }

            } while (opcao_produto != 0);
            break;
        }

        // =====================================================
        case 2: // MANTER CLIENTES
        {
            int opcao_cliente;
            do
            {
                printf("\n--- MANTER CLIENTES ---\n");
                printf("1. Cadastrar Novo Cliente\n");
                printf("2. Remover Cliente Cadastrado\n");
                printf("3. Consultar Cliente Cadastrado\n");
                printf("4. Listar Clientes Cadastrados\n");
                printf("0. Voltar\n");
                printf("Escolha uma opcao: ");

                if (scanf("%d", &opcao_cliente) != 1)
                {
                    printf("Opcao invalida. Tente novamente.\n");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    opcao_cliente = -1;
                    continue;
                }

                switch (opcao_cliente)
                {
                case 1:
                    printf("-> Cadastrar novo cliente (futura funcao)\n");
                    break;
                case 2:
                    printf("-> Remover cliente cadastrado (futura funcao)\n");
                    break;
                case 3:
                    printf("-> Consultar cliente cadastrado (futura funcao)\n");
                    break;
                case 4:
                    printf("-> Listar clientes cadastrados (futura funcao)\n");
                    break;
                case 0:
                    printf("Voltando ao menu principal...\n");
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                }

            } while (opcao_cliente != 0);
            break;
        }

        // =====================================================
        case 3: // MANTER PEDIDOS
        {
            int opcao_pedido;
            do
            {
                printf("\n--- MANTER PEDIDOS ---\n");
                printf("1. Cadastrar Novo Pedido\n");
                printf("2. Remover Pedido Cadastrado\n");
                printf("3. Consultar Pedido Cadastrado\n");
                printf("4. Listar Pedidos Cadastrados\n");
                printf("0. Voltar\n");
                printf("Escolha uma opcao: ");

                if (scanf("%d", &opcao_pedido) != 1)
                {
                    printf("Opcao invalida. Tente novamente.\n");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    opcao_pedido = -1;
                    continue;
                }

                switch (opcao_pedido)
                {
                case 1:
                    printf("-> Cadastrar novo pedido (futura funcao)\n");
                    break;
                case 2:
                    printf("-> Remover pedido cadastrado (futura funcao)\n");
                    break;
                case 3:
                    printf("-> Consultar pedido cadastrado (futura funcao)\n");
                    break;
                case 4:
                    printf("-> Listar pedidos cadastrados (futura funcao)\n");
                    break;
                case 0:
                    printf("Voltando ao menu principal...\n");
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                }

            } while (opcao_pedido != 0);
            break;
        }

        // =====================================================
        case 0:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
        }

    } while (selecao != 0);

    return 0;
}
