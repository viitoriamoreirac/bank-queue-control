#ifndef FILA_H
#define FILA_H

#include "cliente.h"

// nó da fila
typedef struct node {
    Cliente* cliente;
    struct node* next;
} Node;

typedef struct fila {
    Node* front;
    Node* rear;
} Fila;

Fila* inicializar_fila();
Fila* adicionar_cliente(Fila* fila);
void exibir_fila(Fila* fila);
Fila* prioritario(Fila* fila, Cliente* cliente);
int tempo_na_fila(Fila* fila);
void prioritario_aumenta_tempo_na_fila(Fila* fila, int tempo_adicional);
Fila* atender_cliente(Fila* fila); 

#endif
