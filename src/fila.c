#include "../include/fila.h"
#include "../include/transacoes.h"
#include "../include/relatorio.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Fila* inicializar_fila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->front = NULL;
        fila->rear = NULL;
    }
    return fila;
}

Fila* adicionar_no_inicio(Fila* fila, Cliente* cliente) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    if (novo_node != NULL) {
        novo_node->cliente = cliente;
        novo_node->next = fila->front;

        // Se a fila estiver vazia, novo_node será o último nó
        if (fila->rear == NULL) {
            fila->rear = novo_node;
        }
        fila->front = novo_node;
    }
    return fila;
}

Fila* adicionar_no_fim(Fila* fila, Cliente* cliente) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    if (novo_node != NULL) {
        novo_node->cliente = cliente;
        novo_node->next = NULL;

        // Se a fila estiver vazia, novo_node será o primeiro e último nó
        if (fila->rear == NULL) {
            fila->front = novo_node;
            fila->rear = novo_node;
        } else {
            fila->rear->next = novo_node;
            fila->rear = novo_node;
        }
    }
    return fila;
}

// adiciona cliente com base na prioridade
Fila* prioritario(Fila* fila, Cliente* cliente) {
    if (cliente->prioritario == 1) {
        fila = adicionar_no_inicio(fila, cliente);
    } else {
        fila = adicionar_no_fim(fila, cliente);
    }
    return fila;
}

int tempo_na_fila(Fila* fila) {
    int tempo_total = 0;
    Node* atual = fila->front;

    while (atual != NULL) {
        tempo_total += atual->cliente->tempo_de_atendimento;
        atual = atual->next;
    }

    return tempo_total;
}

void prioritario_aumenta_tempo_na_fila(Fila* fila, int tempo_adicional) {
    Node* atual = fila->front;

    // Percorre a fila e aumenta o tempo_na_fila de cada cliente
    while (atual != NULL) {
        atual->cliente->tempo_na_fila += tempo_adicional;
        atual->cliente->tempo_total += tempo_adicional;
        atual = atual->next;
    }
}

Fila* adicionar_cliente(Fila* fila) {
    Cliente* novo_cliente = criar_cliente();

    while (getchar() != '\n');  // Limpa o buffer do stdin

    printf("Digite o nome do cliente: ");
    fgets(novo_cliente->nome, 50, stdin);
    novo_cliente->nome[strcspn(novo_cliente->nome, "\n")] = '\0';

    int prioridade_valida = 0;
    while (!prioridade_valida) {
        printf("O cliente é prioritário? (0 = Não, 1 = Sim): ");
        int prioridade;
        if (scanf("%d", &prioridade) == 1 && (prioridade == 0 || prioridade == 1)) {
            novo_cliente->prioritario = prioridade;
            prioridade_valida = 1;
        } else {
            printf("Entrada inválida! Digite 0 para Não ou 1 para Sim.\n");
            while (getchar() != '\n');  // Limpa o buffer do stdin
        }
    }

    novo_cliente->tempo_de_atendimento = escolher_transacoes();

       if (novo_cliente->prioritario == 1) {
        novo_cliente->tempo_na_fila = 0;
        prioritario_aumenta_tempo_na_fila(fila, novo_cliente->tempo_de_atendimento);
        } else {
            novo_cliente->tempo_na_fila = tempo_na_fila(fila);
         }

    novo_cliente->tempo_total = novo_cliente->tempo_de_atendimento + novo_cliente->tempo_na_fila;

    fila = prioritario(fila, novo_cliente);

    return fila;
}

Fila* atender_cliente(Fila* fila) {
    if (fila == NULL || fila->front == NULL) {
        printf("A fila está vazia.\n");
        return fila;
    }

    Node* temp = fila->front;
    Cliente* cliente = temp->cliente;

    atualizar_relatorio(cliente->tempo_total, cliente->prioritario);

    printf("Atendendo o cliente %s\n", cliente->nome);

    fila->front = fila->front->next;
    if (fila->front == NULL) {
        fila->rear = NULL;
    }

    free(temp->cliente);
    free(temp);

    return fila;
}


void exibir_fila(Fila* fila) {
    if (fila->front == NULL) {
        printf("A fila está vazia.\n\n");
        return;
    }

    Node* atual = fila->front;
    printf("Clientes na fila:\n");
    while (atual != NULL) {
        Cliente* cliente = atual->cliente;
        printf("Nome: %s | Prioritário: %s | Tempo na Fila: %d | Tempo de Atendimento: %d | Tempo Total: %d\n",
               cliente->nome,
               cliente->prioritario ? "Sim" : "Não",
               cliente->tempo_na_fila,
               cliente->tempo_de_atendimento,
               cliente->tempo_total);
        atual = atual->next;
    }
    printf("----------------------------------------------------");
}
