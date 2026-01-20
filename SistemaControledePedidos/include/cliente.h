#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    int id;
    int tipo; 
    char nome[100];
    char cpf_cnpj[20];
    char telefone[20];
    char endereco[200];
} Cliente;

int valida_cpf(const char *cpf);
int valida_cnpj(const char *cnpj);
void cadastrar_cliente(void);
void listar_clientes(void);
void remover_cliente(void);
void consultar_cliente(void);

Cliente* get_array_clientes(void);
int* get_total_clientes(void);
int get_max_clientes(void);

#endif