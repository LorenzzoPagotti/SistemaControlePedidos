#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// feito por kauã e lorenzzo!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef struct
{
    int codigo;
    char nome[20];
    float altura;
    float peso;
} Pessoa; // struct com dados permanentes da pessoa

typedef struct
{
    int codigo;
    int dia, mes, ano;
    float quilos;
} Historico_Pesos; // struct com dados para o historico de peso da pessoa

int incluirpessoa(void)
{
    Pessoa d; // declaração de variável do tipo Pessoa

    FILE *fp; // declaração de um ponteiro para arquivo (FILE)
    fp = fopen("Pessoa.csv", "a"); // abre o arquivo no modo 'append' (adicionar)
    if (fp == NULL) // verificação de erro na abertura do arquivo
    {
        perror("Erro na abertura de Pessoa.csv");
        return EXIT_FAILURE;
    }

    printf("Digite o codigo: "); 
    scanf("%d", &d.codigo);
    printf("Digite o nome: ");
    scanf(" %[^\n]", d.nome); // leitura do nome (inclui espaços até a quebra de linha)
    printf("Digite a altura: ");
    scanf("%f", &d.altura);
    printf("Digite o peso: "); // coleta de informações
    scanf("%f", &d.peso);

    // impressão dos dados coletados no arquivo CSV
    fprintf(fp, "%d | %s | %.2f | %.2f\n", d.codigo, d.nome, d.altura, d.peso);

    fclose(fp); // fecha o arquivo
    return EXIT_SUCCESS;
}

int mostrarpessoa()
{
    FILE *fp; // declaração de um ponteiro para arquivo
    fp = fopen("Pessoa.csv", "r"); // abre o arquivo no modo 'leitura'
    if (fp == NULL) // verificação de erro
    {
        perror("Erro ao abrir Pessoa.csv");
        return EXIT_FAILURE;
    }

    char linha[200];
    printf("\n--- Pessoas Cadastradas ---\n");
    printf("Codigo | Nome | Altura | Peso\n");
    printf("---------------------------\n");

    while (fgets(linha, 200, fp) != NULL) // leitura da linha do arquivo até o fim
    {
        printf("%s", linha); // imprime a linha lida (que já contém os dados da pessoa)
    }

    fclose(fp); // fecha o arquivo
    return EXIT_SUCCESS;
}

int incluirpeso(void)
{
    Historico_Pesos a; // declaração de variável para o histórico de pesos

    FILE *fp2; // declaração do ponteiro para o arquivo de pesos
    fp2 = fopen("Pesos.csv", "a"); // abre o arquivo Pesos.csv em modo 'append'
    if (fp2 == NULL) // verificação de erro
    {
        perror("Erro ao abrir Pesos.csv");
        return EXIT_FAILURE;
    }

    // coleta de dados do histórico de peso
    printf("Digite o codigo: ");
    scanf("%d", &a.codigo);
    printf("Digite a data (dd/mm/aaaa): ");
    scanf("%d%*c%d%*c%d", &a.dia, &a.mes, &a.ano);
    printf("Digite o peso: ");
    scanf("%f", &a.quilos);

    // impressão dos dados no arquivo Pesos.csv
    fprintf(fp2, "%d | %.2f | %02d/%02d/%04d\n", a.codigo, a.quilos, a.dia, a.mes, a.ano);

    fclose(fp2); // fecha o arquivo
    return EXIT_SUCCESS;
}

int mostrarimc(void)
{
    int codigo_pessoa, pesopessoa = 0; // codigo para busca e flag de controle (foi achado peso?)
    float altura_pessoa = 0.0, imc;
    char linha[200];
    Pessoa p;
    Historico_Pesos p2;

    printf("Digite o codigo da pessoa para o historico de IMC: ");
    scanf("%d", &codigo_pessoa);

    // achar a altura da pessoa em Pessoa.csv
    FILE *fp = fopen("Pessoa.csv", "r"); // abre Pessoa.csv em modo de leitura

    if (fp == NULL) // verificação de erro
    {
        perror("Erro ao abrir Pessoa.csv");
        return EXIT_FAILURE;
    }

    while (fgets(linha, 200, fp) != NULL) // leitura linha por linha
    {
        // sscanf extrai os dados da linha para a struct p, buscando a altura
        if (sscanf(linha, "%d | %19[^|] | %f | %f", &p.codigo, p.nome, &p.altura, &p.peso) == 4)
        {
            if (p.codigo == codigo_pessoa) // se o código procurado for achado
            {
                altura_pessoa = p.altura; // armazena a altura
                break; // altura encontrada, sai do loop
            }
        }
    }

    fclose(fp); // fecha o arquivo Pessoa.csv

    if (altura_pessoa <= 0.0)
    {
        // caso alternativo se pessoa não encontrada ou altura inválida
        printf("Codigo %d nao encontrado em Pessoa.csv ou altura invalida.\n", codigo_pessoa); 
        return EXIT_SUCCESS;
    }

    // achar os pesos em Pesos.csv e calcular o IMC
    FILE *fp2 = fopen("Pesos.csv", "r"); // abre Pesos.csv em modo de leitura

    if (fp2 == NULL)
    {
        perror("Erro ao abrir Pesos.csv");
        return EXIT_FAILURE;
    }

    printf("\n--- Historico de IMC para Codigo %d (Altura: %.2f m) ---\n", codigo_pessoa, altura_pessoa);
    printf("Data\t\tPeso (kg)\tIMC\n");
    printf("----------------------------------------------------\n");

    while (fgets(linha, 200, fp2) != NULL) // leitura linha por linha de Pesos.csv
    {
        int dia, mes, ano;
        // sscanf extrai código, peso e data. Atribui o valor às variáveis.
        if (sscanf(linha, "%d | %f | %d/%d/%d", &p2.codigo, &p2.quilos, &dia, &mes, &ano) == 5)
        {
            if (p2.codigo == codigo_pessoa) // se o código for o da pessoa buscada
            {
                imc = p2.quilos / (altura_pessoa * altura_pessoa); // cálculo do IMC
                // imprime a linha do histórico com os dados calculados
                printf("%02d/%02d/%d\t%.2f\t\t%.2f\n", dia, mes, ano, p2.quilos, imc); 
                pesopessoa = 1; // marca a flag como 'encontrado'
            }
        }
    }

    if (!pesopessoa) // se a flag pesopessoa for 0
    {
        printf("Nenhum historico de peso encontrado para o Codigo %d.\n", codigo_pessoa);
    }

    fclose(fp2); // fecha o arquivo Pesos.csv
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