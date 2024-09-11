#ifndef PEDIDO_H
#define PEDIDO_H

#include "pratos.h"

typedef struct Prato {
    PratoEnum prato;
    struct Prato* prox;
} Prato;

typedef struct Pedido {
    int id;
    Prato* pratos; 
    struct Pedido* prox;
} Pedido;

Pedido* criarPedido(int id);
void adicionarPrato(Pedido* pedido, PratoEnum tipo);
void listarPratos(const Pedido* pedido);
void removerPrato(Pedido* pedido, PratoEnum tipo);
void liberarPedido(Pedido* pedido);

#endif