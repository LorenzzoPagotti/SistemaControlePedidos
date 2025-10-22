#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[20];
    float altura;
    float peso;
} Pessoa;

typedef struct
{
    int dia, mes, ano;
    float quilos;
} Historico_Pesos;

int main(void)
{

    FILE *fp;
    FILE *fp2;

    Pessoa b = {1, "Kaua", 175, 70};
    Pessoa c = {2, "Lorenzzo", 175, 65};
    Pessoa d;
    Historico_Pesos a;
    a.quilos = 0;

    fp = fopen("Pessoa.csv", "a");
    fp2 = fopen("Pesos.csv", "a");

    if (fp == NULL || fp2 == NULL)
    {
        perror("Erro!!!");
        return EXIT_FAILURE;
    }

    fprintf(fp, "%d | %s | %.2f | %.2f\n", b.codigo, b.nome, b.altura, b.peso);

    fprintf(fp, "%d | %s | %.2f | %.2f\n", c.codigo, c.nome, c.altura, c.peso);

    printf("Digite o codigo: ");
    scanf("%d", &d.codigo);
    printf("Digite o nome: ");
    scanf(" %[^\n]", d.nome);
    printf("Digite a altura: ");
    scanf("%f", &d.altura);
    printf("Digite a data: ");
    scanf("%d%*c%d%*c%d", &a.dia, &a.mes, &a.ano);
    printf("Digite o peso: ");
    scanf("%f", &d.peso);

    a.quilos = d.peso;

    fprintf(fp, "%d | %s | %.2f | %.2f\n", d.codigo, d.nome, d.altura, d.peso);
    fprintf(fp2, "%d | %.2f | %d/%d/%d\n", d.codigo, a.quilos, a.dia, a.mes, a.ano);

    fclose(fp);
    fclose(fp2);
    return EXIT_SUCCESS;
}