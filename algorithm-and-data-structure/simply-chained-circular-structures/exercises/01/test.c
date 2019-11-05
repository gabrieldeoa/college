#include "exercise-one.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    fila filaUm, filaDois, filaUnificada;

    filaUm = fila_ler();
    fila_exibir(filaUm);

    filaDois = fila_ler();
    fila_exibir(filaDois);

    filaUnificada = fila_unificar_filas(filaUm, filaDois);
    fila_exibir(filaUnificada);
}

