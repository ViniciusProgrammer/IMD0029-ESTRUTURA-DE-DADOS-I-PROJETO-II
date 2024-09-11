#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

void inicializarFila(FilaProcessamento* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void adicionarPedidoNaFila(FilaProcessamento* fila, Pedido* pedido) {
    pedido->prox = NULL;
    if (fila->fim != NULL) {
        fila->fim->prox = pedido;
    } else {
        fila->inicio = pedido;
    }
    fila->fim = pedido;
}

Pedido* processarProximoPedido(FilaProcessamento* fila) {
    if (fila->inicio == NULL) {
        return NULL;
    }
    Pedido* proximo = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    return proximo;
}

void listarPedidosEmProcessamento(const FilaProcessamento* fila) {
    Pedido* atual = fila->inicio;
    if(atual == NULL){
        printf("---Nenhum pedido em processamento!---\n\n");
    } else{
        while (atual != NULL) {
        printf("Pedido %d:\n", atual->id);
        listarPratos(atual);
        atual = atual->prox;
        }
         printf("---------------------\n\n");
    }
}