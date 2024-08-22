#include "transacoes.h"
#include <stdio.h>
#include <stdlib.h>

int soma_tempo_de_atendimento(int transacao, int *tempo_de_atendimento) {
    switch(transacao) {
        case 1:
            *tempo_de_atendimento += 50;
            break;
        case 2:
            *tempo_de_atendimento += 70;
            break;
        case 3:
            *tempo_de_atendimento += 100;
            break;
        case 4:
            *tempo_de_atendimento += 60;
            break;
        default:
            break;
    }

    return *tempo_de_atendimento;
}

int escolher_transacoes() {
    int opcao;
    int tempo_de_atendimento = 0;

    do {
        printf("------------------------------------------\n");
        printf("Escolha a transação que deseja realizar:\n");
        printf("1 - Saque\n");
        printf("2 - Depósito\n");
        printf("3 - Pagamento\n");
        printf("4 - Transferência\n");
        printf("5 - Não desejo mais nenhuma transação\n");
        printf("Digite a sua opção: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 4) {
            soma_tempo_de_atendimento(opcao, &tempo_de_atendimento);
        } else if (opcao != 5) {
            printf("Por favor, digite um número válido entre 1 e 5.\n");
        }

    } while (opcao != 5);
    return tempo_de_atendimento;
}
