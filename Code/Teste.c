#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int incluirpessoa(void)
{
    typedef struct
    {
        int codigo;
        char nome[20];
        float altura;
        float peso;
    } Pessoa;

    Pessoa d;

    FILE *fp;
    fp = fopen("Pessoa.csv", "a");
    if (fp == NULL)
    {
        perror("Erro!!!");
        return EXIT_FAILURE;
    }

    printf("Digite o codigo: ");
    scanf("%d", &d.codigo);
    printf("Digite o nome: ");
    scanf(" %[^\n]", d.nome);
    printf("Digite a altura: ");
    scanf("%f", &d.altura);
    printf("Digite o peso: ");
    scanf("%f", &d.peso);

    fprintf(fp, "%d | %s | %.2f | %.2f\n", d.codigo, d.nome, d.altura, d.peso);

    fclose(fp);
    return EXIT_SUCCESS;
}

int mostrarpessoa()
{
    FILE *fp;
    fp = fopen("Pessoa.csv", "r");
    if (fp == NULL)
    {
        perror("Erro!!!");
        return EXIT_FAILURE;
    }
}

int incluirpeso(void)
{
    typedef struct
    {
        int codigo;
        int dia, mes, ano;
        float quilos, altura;
    } Historico_Pesos;

    Historico_Pesos a;

    FILE *fp2;
    fp2 = fopen("Pesos.csv", "a");
    if (fp2 == NULL)
    {
        perror("Erro!!!");
        return EXIT_FAILURE;
    }

    printf("Digite o codigo: ");
    scanf("%d", &a.codigo);
    printf("Digite a data: ");
    scanf("%d%*c%d%*c%d", &a.dia, &a.mes, &a.ano);
    printf("Digite o peso: ");
    scanf("%f", &a.quilos);

    fprintf(fp2, "%d | %.2f | %d/%d/%d\n", a.codigo, a.quilos, a.dia, a.mes, a.ano);

    fclose(fp2);
    return EXIT_SUCCESS;
}

int main(void)
{



}