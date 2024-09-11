#ifndef LISTA_H
#define LISTA_H

#include "pedido.h"

typedef struct {
    Pedido* inicio;
} ListaPedidos;

void inicializarLista(ListaPedidos* lista);
void adicionarPedidoNaLista(ListaPedidos* lista, Pedido* pedido);
void removerPedidoDaLista(ListaPedidos* lista, int idPedido);
void listarPedidosPendentes(const ListaPedidos* lista);
Pedido* obterPedidoMaisAntigo(ListaPedidos* lista);

#endif
