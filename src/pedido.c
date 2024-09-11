#include <stdio.h>
#include <stdlib.h>

#include "pedido.h"

Pedido* criarPedido(int id) {
    Pedido* novoPedido = (Pedido*)malloc(sizeof(Pedido));
    if (novoPedido != NULL) {
        novoPedido->id = id;
        novoPedido->pratos = NULL;
        novoPedido->prox = NULL;
    }
    return novoPedido;
}


void adicionarPrato(Pedido* pedido, PratoEnum prato) {
    Prato* novoPrato = (Prato*)malloc(sizeof(Prato));
    if (novoPrato != NULL) {
        novoPrato->prato = prato;
        novoPrato->prox = pedido->pratos;
        pedido->pratos = novoPrato;
    }
}

void removerPrato(Pedido* pedido, PratoEnum tipo) {
    Prato* atual = pedido->pratos;
    Prato* anterior = NULL;
    while (atual != NULL && atual->prato != tipo) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->prox = atual->prox;
        } else {
            pedido->pratos = atual->prox;
        }
        free(atual);
    }
}

void listarPratos(const Pedido* pedido) {
    Prato* atual = pedido->pratos;
    while (atual != NULL) {
        printf(" - %s\n", obterNomePrato(atual->prato));
        atual = atual->prox;
    }
}

void liberarPedido(Pedido* pedido) {
    Prato* atual = pedido->pratos;
    while (atual != NULL) {
        Prato* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(pedido);
}