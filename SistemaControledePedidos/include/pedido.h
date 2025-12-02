#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct {
    int id;
    int clienteId;
    int produtoId; 
    int quantidade;
    double total;
} Pedido;

int cadastrar_pedido(void);
int listar_pedidos(void);

Pedido* get_array_pedidos(void);
int* get_total_pedidos(void);
int get_max_pedidos(void);

#endif