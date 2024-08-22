#ifndef RELATORIO_H
#define RELATORIO_H

extern int fluxo_de_clientes;
extern int tempo_total_de_atendimento;
extern int media_tempo_de_atendimento;
extern int prioridade;

void atualizar_relatorio(int tempo_total, int prioritario);
void exibir_relatorio();

#endif