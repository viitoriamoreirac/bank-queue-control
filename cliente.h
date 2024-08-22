#ifndef CLIENTE_H
#define CLIENTE_H


typedef struct cliente {
    char nome[50];
    int tempo_na_fila;
    int tempo_de_atendimento;
    int tempo_total;
    int prioritario;
    
} Cliente;

Cliente* criar_cliente();

#endif
