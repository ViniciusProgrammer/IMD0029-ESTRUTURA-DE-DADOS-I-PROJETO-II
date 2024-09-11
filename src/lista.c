#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void inicializarLista(ListaPedidos* lista) {
    lista->inicio = NULL;
}

void adicionarPedidoNaLista(ListaPedidos* lista, Pedido* pedido) {
    pedido->prox = lista->inicio;
    lista->inicio = pedido;
}

void removerPedidoDaLista(ListaPedidos* lista, int idPedido) {
    Pedido* atual = lista->inicio;
    Pedido* anterior = NULL;
    while (atual != NULL && atual->id != idPedido) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->prox = atual->prox;
        } else {
            lista->inicio = atual->prox;
        }
        liberarPedido(atual);
    }
}

void listarPedidosPendentes(const ListaPedidos* lista) {
    Pedido* atual = lista->inicio;

    if(atual == NULL){
        printf("---Nenhum pedido pendente!---\n\n");
    } else{
        while (atual != NULL) {
        printf("---Pedido %d:\n", atual->id);
        listarPratos(atual);
        atual = atual->prox;
        printf("---------------------\n\n");
        }
    }
}

Pedido* obterPedidoMaisAntigo(ListaPedidos* lista) {
    Pedido* atual = lista->inicio;
    Pedido* anterior = NULL;
    Pedido* maisAntigo = NULL;
    Pedido* maisAntigoAnterior = NULL;

    while (atual != NULL) {
        if (maisAntigo == NULL || atual->id < maisAntigo->id) {
            maisAntigo = atual;
            maisAntigoAnterior = anterior;
        }
        anterior = atual;
        atual = atual->prox;
    }

    if (maisAntigoAnterior != NULL) {
        maisAntigoAnterior->prox = maisAntigo->prox;
    } else {
        lista->inicio = maisAntigo->prox;
    }

    return maisAntigo;
}