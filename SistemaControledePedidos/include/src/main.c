#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int selecao;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Manter Produtos\n");
        printf("2. Manter Clientes\n");
        printf("3. Manter Pedidos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &selecao) != 1)
        {
            printf("Opcao invalida. Tente novamente.\n");

            int c;
            // limpa o buffer de entrada após erro de scanf
            while ((c = getchar()) != '\n' && c != EOF); 
            selecao = -1; // garante que o loop continue
            continue;
        }

        switch (selecao)
        {
        case 1:
            incluirpessoa();
            break;

        case 2:
            mostrarpessoa();
            break;

        case 3:
            incluirpeso();
            break;
        case 0:
            printf("Saindo...");
            break;
        default:
            printf("Opcao invalida, escolha de novo");
            break;
        }

    } while (selecao != 0);

    return 0;
}