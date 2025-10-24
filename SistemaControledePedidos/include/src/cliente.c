#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "E:\VISUAL\TP-TrabalhoFinal\SistemaControledePedidos\include\cliente.h"

int validacpf(const char *cpf)
{
    if (strlen(cpf) != 11)
        return 0;
    for (int i = 0; i < 11; i++)
        if (cpf[i] < '0' || cpf[i] > '9')
            return 0;
    return 1;
}

int validacnpj(const char *cnpj)
{
    if (strlen(cnpj) != 14)
        return 0;
    for (int i = 0; i < 14; i++)
        if (cnpj[i] < '0' || cnpj[i] > '9')
            return 0;
    return 1;
}

int analisa_cliente(void)
{
} // fazer

int consultar_cliente(int id)
{ // fazer
}

int remover_cliente(int id)
{ // fazer
}

int listar_cliente(void)
{
} // fazer

int cadastrar_cliente(void)
{
    Cliente x;

    FILE *fp_cliente;
    fp_cliente = fopen("Clientes.csv", "a");
    if (fp_cliente == NULL)
    {
        perror("Erro na abertura de Clientes.csv");
        return EXIT_FAILURE;
    }

    printf("Digite o codigo identificador do cliente: ");
    scanf("%d", &x.id);

    //==================================
    // FUNÇÃO ANALISA CLIENTE RODA
    //==================================

    printf("Digite o CPF: ");
    scanf(" %[^\n]", x.CPF); // leitura de cpf ou ccnpj, fazer pergunta e decidir com switch
    printf("Digite a altura: ");
    scanf("%s", x.endereco);
    printf("Digite o seu nome: "); // pessoa fisica
    scanf("%s", x.nome);
    printf("Digite o celular: "); // pessoa fisica
    scanf("%s", x.telefone);
    printf("Digite a razão social: "); // pessoa juridica
    scanf("%s", x.razao_social);
    printf("Digite o nome de contato: "); // pessoa juridica
    scanf("%s", x.nome_contato);

    // impressão dos dados coletados no arquivo CSV
    fprintf(fp_cliente, "%d | %s | %s | %s\n", x.id, x.nome, x.endereco, x.telefone);

    fclose(fp_cliente); // fecha o arquivo
    return EXIT_SUCCESS;
}