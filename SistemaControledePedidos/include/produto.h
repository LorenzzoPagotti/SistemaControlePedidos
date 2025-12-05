#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int id;
    double preco;
    int estoque;
    char descricao[100];
} Produto;

int cadastrar_produto(void);
int listar_produtos(void);
void remover_produto(void);
void consultar_produto_visual(void);
int consultar_produto(int id);

Produto* get_array_produtos(void);
int* get_total_produtos(void);
int get_max_produtos(void);

#endif