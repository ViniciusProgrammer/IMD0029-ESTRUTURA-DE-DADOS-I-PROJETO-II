#ifndef FILA_H
#define FILA_H

#include "pedido.h"

typedef struct {
    Pedido* inicio;
    Pedido* fim;
} FilaProcessamento;

void inicializarFila(FilaProcessamento* fila);
void adicionarPedidoNaFila(FilaProcessamento* fila, Pedido* pedido);
Pedido* processarProximoPedido(FilaProcessamento* fila);
void listarPedidosEmProcessamento(const FilaProcessamento* fila);

#endif
