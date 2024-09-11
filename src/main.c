#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pedido.h"
#include "pratos.h"
#include "lista.h"
#include "fila.h"

void menuInicial() {
    printf("1- Adicionar Pedido\n");
    printf("2- Remover prato\n");
    printf("3- Processar Pedido\n");
    printf("4- Listar Pedidos Pendentes\n");
    printf("5- Listar Pedidos em Processamento\n");
    printf("6- Sair\n");
    printf("Escolha uma opcao: ");
}

void menuCardapio() {
    printf("------Cardapio------\n");
    for (int i = 0; i < NUM_PRATOS; i++) {
        printf("%d- %s\n", i+1, obterNomePrato(i));
    }
    printf("Escolha uma opcao (0 para sair): ");
}

void limparTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(int argc, char const *argv[]) {

    ListaPedidos lista;
    FilaProcessamento fila;
    int opcao, id = 1;

    inicializarLista(&lista);
    inicializarFila(&fila);

    do {
        menuInicial();
        scanf("%d", &opcao);
        limparTerminal();
        if (opcao == 1) {
            Pedido* novoPedido = criarPedido(id++);
            int opPrato;
            do {
                menuCardapio();
                scanf("%d", &opPrato);
                if (opPrato > 0 && opPrato <= NUM_PRATOS) {
                    limparTerminal();
                    printf("\n\n---Prato adicionado com sucesso!---\n\n");
                    adicionarPrato(novoPedido, opPrato - 1);
                } else if (opPrato != 0) {
                    printf("Opcao invalida!\n");
                }
            } while (opPrato != 0);
            limparTerminal();
            printf("---Pedido adicionado com sucesso!---\n\n");
            adicionarPedidoNaLista(&lista, novoPedido);
        } else if (opcao == 2) {
            int idPedido, opPrato;
            printf("Informe o ID do pedido: ");
            scanf("%d", &idPedido);
            printf("\n---Escolha o prato a ser removido:\n");
            menuCardapio();
            scanf("%d", &opPrato);
            Pedido* pedido = lista.inicio;
            while (pedido != NULL && pedido->id != idPedido) {
                pedido = pedido->prox;
            }
            if (pedido != NULL && opPrato > 0 && opPrato < NUM_PRATOS) {
                removerPrato(pedido, opPrato);
            } else {
                printf("---Pedido ou prato nao encontrado!---\n\n");
            }
            limparTerminal();
        } else if (opcao == 3) {
            Pedido* pedido = obterPedidoMaisAntigo(&lista);
            if (pedido != NULL) {
                adicionarPedidoNaFila(&fila, pedido);
                printf("---Pedido %d transferido para a fila de processamento.---\n\n", pedido->id);
            } else {
                printf("---Nao ha pedidos pendentes.\n\n---");
            }
        } else if (opcao == 4) {
            listarPedidosPendentes(&lista);
        } else if (opcao == 5) {
            listarPedidosEmProcessamento(&fila);
        } else if (opcao == 6) {
            limparTerminal();
            printf("---Mercadinho Tabajaras agradece a preferencia!---");
            break;
        } else {
            printf("---Opcao invalida!---\n\n");
        }
    } while(opcao != 6);

    return 0;
}
