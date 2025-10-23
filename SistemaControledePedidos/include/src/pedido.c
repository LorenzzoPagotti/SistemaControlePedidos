#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    double preco;
    int estoque;
    char descricao[100];

} Produto;

int cadastrarr_produto(void)
{
}

int analisa_produto(void)
{
}

int consultarr_produto(void)
{
}

int remover_produto(void)
{
}

int listar_produto(void)
{
}

int listar_cliente(void)
{
}

int main()
{
    Produto x;

    FILE *fp_produto;
    fp_produto = fopen("Produtos.csv", "a");
    if (fp_produto == NULL)
    {
        perror("Erro na abertura de Produtos.csv");
        return EXIT_FAILURE;
    }

    printf("Digite o codigo identificador do produto: ");
    scanf("%d", &x.id);

    //==================================
    // FUNÇÃO ANALISA PRODUTO RODA AQUI
    //==================================

    printf("Informe a descrição: ");
    scanf(" %[^\n]", x.descricao); // leitura do nome (inclui espaços até a quebra de linha)
    printf("Informe o preço: ");
    scanf("%lf", x.preco);
    printf("Informe a quantidade em estoque: "); // coleta de informações
    scanf("%d", x.estoque);

    // impressão dos dados coletados no arquivo CSV
    fprintf(fp_produto, "%d | %s | %lf | %d\n", x.id, x.descricao, x.preco, x.estoque);

    fclose(fp_produto); // fecha o arquivo
    return EXIT_SUCCESS;
}