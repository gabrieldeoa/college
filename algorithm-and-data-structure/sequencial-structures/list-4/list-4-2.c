#include <stdio.h>
#include <stdlib.h>
#include "list-4-2.h"

int main () {
    fila f;
    int tam = 2, atendentes = 2;

    fila_ler(&f, tam, tam);
    printf("\n ---- FILA DE CLIENTES ----\n");
    fila_exibir(f);
    printf("\n ---- Atendendo %d ----\n", atendentes);
    printf("\n %d\n", fila_atender(&f, atendentes));
    printf("\n ---- FILA DE CLIENTES DEPOIS DO ATENDIMENTO ----\n");
    fila_exibir(f);

}
