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
    int codigo;
    int dia, mes, ano;
    float quilos, altura;
} Historico_Pesos;

int incluirpessoa(void)
{

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

    char linha[200];
    printf("\n--- Pessoas Cadastradas ---\n");
    printf("Codigo | Nome | Altura | Peso\n");
    printf("---------------------------\n");

    while (fgets(linha, 200, fp) != NULL)
    {
        printf("%s", linha);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}

int incluirpeso(void)
{

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

int mostrarimc(void)
{
    int codigo_pessoa, pesopessoa;
    float altura_pessoa, imc;
    char linha[200];
    Pessoa p;
    Historico_Pesos p2;

    printf("Digite o codigo da pessoa para o historico de IMC: ");
    scanf("%d", &codigo_pessoa);

    FILE *fp = fopen("Pessoa.csv", "r");

    if (fp == NULL)
    {
        perror("Erro!!!");
        return EXIT_FAILURE;
    }

    while (fgets(linha, 200, fp) != NULL)
    {
        if (sscanf(linha, "%d | %19[^|] | %f | %f", &p.codigo, p.nome, &p.altura, &p.peso) == 4)
        {
            if (p.codigo == codigo_pessoa)
            {
                altura_pessoa = p.altura;
                break;
            }
        }
    }

    fclose(fp);

    if (altura_pessoa == 0.0)
    {
        printf("Codigo %d nao encontrado em Pessoa.csv ou dados invalidos.\n", codigo_pessoa);
        return EXIT_SUCCESS;
    }

    FILE *fp2 = fopen("Pesos.csv", "r");

    if (fp2 == NULL)
    {
        perror("Erro!!!");
        return EXIT_FAILURE;
    }

    printf("\n--- Historico de IMC para Codigo %d (Altura: %.2f m) ---\n", codigo_pessoa, altura_pessoa);
    printf("Data\t\tPeso (kg)\tIMC\n");
    printf("----------------------------------------------------\n");

    while (fgets(linha, 200, fp2) != NULL)
    {
        int dia, mes, ano;
        if (sscanf(linha, "%d | %f | %d/%d/%d", &p2.codigo, &p2.quilos, &dia, &mes, &ano) == 5)
        {
            if (p2.codigo == codigo_pessoa)
            {
                imc = p2.quilos / (altura_pessoa * altura_pessoa);
                printf("%02d/%02d/%d\t%.2f\t\t%.2f\n", dia, mes, ano, p2.quilos, imc);
                pesopessoa = 1;
            }
        }
    }

    if (!pesopessoa)
    {
        printf("Nenhum historico de peso encontrado para o Codigo %d.\n", codigo_pessoa);
    }

    fclose(fp2);
    printf("----------------------------------------------------\n");
    return EXIT_SUCCESS;
}

int main(void)
{
    int selecao;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Incluir Pessoa\n");
        printf("2. Mostrar Pessoas cadastradas\n");
        printf("3. Incluir Historico de pesos\n");
        printf("4. Mostrar historico de IMCs\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &selecao) != 1)
        {
            printf("Opcao invalida. Tente novamente.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            selecao = -1;
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
        case 4:
            mostrarimc();
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