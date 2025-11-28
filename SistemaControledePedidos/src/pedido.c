#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pedido.h"

int cadastrar_pedido(void)
{
}

int analisa_pedido(void)
{
}

int cadastrar_item_pedido(int id)
{
}

int cadastrar_pedido(void)
{
    Pedido x;

    FILE *fp_pedido;
    fp_pedido = fopen("Pedidos.csv", "a");
    if (fp_pedido == NULL)
    {
        perror("Erro na abertura de Pedidos.csv");
        return EXIT_FAILURE;
    }

    printf("Digite o codigo identificador do pedido: ");
    scanf("%d", &x.id);

    //==================================
    // FUNÇÃO ANALISA PEDIDO RODA
    //==================================

    // impressão dos dados coletados no arquivo CSV
    // fprintf(fp_pedido, "%d | %s | %s | %s\n", x.id, x.nome, x.endereco, x.telefone);

    fclose(fp_pedido); // fecha o arquivo
    return EXIT_SUCCESS;
}