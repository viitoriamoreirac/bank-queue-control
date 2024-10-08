#include "../include/relatorio.h"

#include <stdio.h>

int fluxo_de_clientes = 0;
int tempo_total_de_atendimento = 0;
int media_tempo_de_atendimento = 0;
int prioridade = 0;

void atualizar_relatorio(int tempo_total, int prioritario) {
    fluxo_de_clientes++;
    tempo_total_de_atendimento += tempo_total;
    if (prioritario) {
        prioridade++;
    }
    if (fluxo_de_clientes > 0) {
        media_tempo_de_atendimento = tempo_total_de_atendimento / fluxo_de_clientes;
    }
}

void exibir_relatorio() {
    printf("--------------------------------------\n");
    printf("Relatório do dia:\n");
    printf("Fluxo de Clientes: %d atendidos.\n", fluxo_de_clientes);
    printf("Tempo Total de Atendimento: %d segundos.\n", tempo_total_de_atendimento);
    printf("Média de Tempo de Atendimento: %d segundos.\n", media_tempo_de_atendimento);
    printf("Prioridade: %d clientes atendidos.\n", prioridade);
    printf("---------------------------------------\n");
}
