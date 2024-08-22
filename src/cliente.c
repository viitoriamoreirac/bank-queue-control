#include "../include/cliente.h"

#include <stdlib.h>
#include <stdio.h>

Cliente* criar_cliente() {
    Cliente *cliente = malloc(sizeof(Cliente));

    return cliente;
}

