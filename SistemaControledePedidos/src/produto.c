#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cadastrar_produto(void)
{
        Produto x;

    FILE *fp_produto;
    fp_produto = fopen("Produtos.csv", "a");
    if (fp_produto == NULL)
    {
        perror("Erro na abertura de Produtos.csv");
        return EXIT_FAILURE;
    }

    printf("Digite o codigo identificador do Produto: ");
    scanf("%d", &x.id);

    //==================================
    // FUNÇÃO ANALISA PRODUTO RODA
    //==================================

    printf("Informe a descrição do produto: ");
    scanf(" %[^\n]", x.descricao); 
    printf("Informe o preço do produto: ");
    scanf("%lf", x.preco);
    printf("Informe a quantidade em estoque do produto: "); 
    scanf("%d", x.estoque);

    // impressão dos dados coletados no arquivo CSV
    fprintf(fp_produto, "%d | %s | %lf | %d\n", x.id, x.descricao, x.preco, x.estoque);

    fclose(fp_produto); // fecha o arquivo
    return EXIT_SUCCESS;
}

int analisa_produto(void)
{
}

int consultar_produto(int id)
{
}

int remover_produto(int id)
{
}

int listar_produto(void)
{
} // fazer
