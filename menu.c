#include <stdio.h>
#include <stdlib.h>
#include "transacoes.h"
#include "fila.h"
#include "relatorio.h"

void inicializar_menu() {
    Fila* fila = inicializar_fila();
    int option;

    do {
        printf("1 - Adicionar cliente na fila\n");
        printf("2 - Atender cliente\n");
        printf("3 - Exibir clientes atendidos até o momento\n");
        printf("4 - Encerrar atendimento\n");
        printf("Escolha uma das opções: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                fila = adicionar_cliente(fila);
                break;
            case 2:
                fila = atender_cliente(fila);
            case 3:
                exibir_fila(fila);
                break;
            case 4:
            // testa se a fila ta vazia, caso não, atende clientes restantes
            if (fila->front != NULL) {
                printf("Encerrando atendimento. Atendendo os clientes restantes...\n");
                while (fila->front != NULL) {
                    fila = atender_cliente(fila);
                }
            } else {
                printf("A fila já está vazia.\n");
            }
            printf("Atendimento encerrado.\n");
            exibir_relatorio();
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (option != 4);

     // liberar a memória da fila
    while (fila->front != NULL) {
        atender_cliente(fila);
    }
    free(fila);
}
