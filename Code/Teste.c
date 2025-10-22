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

int main(void)
{
    FILE *fp;

    Pessoa b = {1, "Kaua", 175, 70};
    Pessoa c = {2, "Lorenzzo", 175, 65};
    Pessoa d;

    fp = fopen("Pessoa.csv", "a");

    if (fp == NULL)
    {
        perror("Erro!!!");
        return EXIT_FAILURE;
    }

    fprintf(fp, "%d | %s | %.2f | %.2f\n", b.codigo, b.nome, b.altura, b.peso);

    fprintf(fp, "%d | %s | %.2f | %.2f\n", c.codigo, c.nome, c.altura, c.peso);

    printf("Digite o codigo: ");
    scanf("%d", &d.codigo);
    printf("Digite o nome: ");
    scanf(" %[^\n]", d.nome); // lê até o Enter
    printf("Digite a altura: ");
    scanf("%f", &d.altura);
    printf("Digite o peso: ");
    scanf("%f", &d.peso);

    fp = fopen("Pessoa.csv", "a");
    fprintf(fp, "%d | %s | %.2f | %.2f\n", d.codigo, d.nome, d.altura, d.peso);
    fclose(fp);

    fp = fopen("Pessoa.csv", "r");

    while (fscanf(fp, "%d, %[^\0],%f,%f", &d.codigo, d.nome, &d.altura, &d.peso) == 4)
    {

        printf("%d | %s | %.2f | %.2f\n", d.codigo, d.nome, d.altura, d.peso);
    }

    if (fp == NULL)
    {
        perror("Erro ao abrir para leitura");
        return EXIT_FAILURE;
    }

    fclose(fp);
    return EXIT_SUCCESS;
}