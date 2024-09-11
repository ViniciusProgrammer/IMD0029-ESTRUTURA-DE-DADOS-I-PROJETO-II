# Projeto: Sistema de Gerenciamento de Pedidos de Restaurante

Este projeto foi desenvolvido durante a segunda unidade da disciplina de Estrutura de Dados 1 - IMD/UFRN. Ele implementa um sistema simples de gerenciamento de pedidos em um restaurante, utilizando listas e filas para organizar os pedidos. O sistema permite adicionar pedidos a uma lista de pendentes, mover pedidos para uma fila de processamento e processá-los, removendo-os da fila. Cada pedido contém uma lista de pratos, com funções para adicionar, remover e listar pratos de um pedido.

## Estrutura do Projeto

O projeto está organizado de forma modular, com código separado em diferentes arquivos e pastas para facilitar a manutenção e o entendimento. A estrutura do projeto é a seguinte:


### Descrição das Pastas

- **/src**: Contém os arquivos-fonte (.c) que implementam as funções para pedidos, filas, listas e pratos.
    - `fila.c`: Funções relacionadas à fila de processamento de pedidos.
    - `lista.c`: Funções relacionadas à lista de pedidos pendentes.
    - `pedido.c`: Manipulação de pedidos e seus pratos associados.
    - `pratos.c`: Funções para tratar os tipos de pratos e suas representações.
    - `main.c`: Função principal, onde o sistema é inicializado e manipulado.

- **/include**: Contém os arquivos de cabeçalho (.h), que definem as interfaces públicas das funções implementadas nos arquivos .c.
    - `fila.h`: Funções e estruturas de dados para a fila.
    - `lista.h`: Funções e estruturas de dados para a lista.
    - `pedido.h`: Funções e estruturas para pedidos e pratos.
    - `pratos.h`: Tipos de pratos e funções associadas.

- **/bin**: Diretório gerado após a compilação, contendo o executável do sistema (`app`).

- **/obj**: Diretório criado durante a compilação, armazenando os arquivos objeto (.o).

## Funcionalidades Principais

### Fila de Processamento (`fila.c`)
- `inicializarFila(FilaProcessamento* fila)`: Inicializa a fila de processamento.
- `adicionarPedidoNaFila(FilaProcessamento* fila, Pedido* pedido)`: Adiciona um pedido à fila de processamento.
- `processarProximoPedido(FilaProcessamento* fila)`: Processa e remove o próximo pedido da fila.

### Lista de Pedidos Pendentes (`lista.c`)
- `inicializarLista(ListaPedidos* lista)`: Inicializa a lista de pedidos pendentes.
- `adicionarPedidoNaLista(ListaPedidos* lista, Pedido* pedido)`: Adiciona um pedido à lista de pendentes.
- `removerPedidoDaLista(ListaPedidos* lista, int idPedido)`: Remove um pedido específico da lista.

### Pedidos e Pratos (`pedido.c`, `pratos.c`)
- `criarPedido(int id)`: Cria um novo pedido com um identificador único.
- `adicionarPrato(Pedido* pedido, PratoEnum tipo)`: Adiciona um prato a um pedido.
- `listarPratos(const Pedido* pedido)`: Lista todos os pratos associados a um pedido.
- `liberarPedido(Pedido* pedido)`: Libera a memória de um pedido e seus pratos.

## Compilação e Execução

Para compilar o projeto, execute o comando `make` na raiz do diretório. Isso compilará os arquivos .c na pasta `src`, gerará os arquivos objeto na pasta `obj` e criará o executável na pasta `bin`.

### Comandos:

- `make`: Compila o projeto.
- `make clean`: Remove os arquivos de compilação e o executável.
- `./bin/app`: Executa o sistema.

---
