#include <stdio.h>
#include <stdlib.h>
#include "exercise-four.h"

int main () {
    lista listaProcessos;
    int quantidadeElementos;
    processo processo;

    listaProcessos = lista_ler();
    printf("\n--> PROCESSOS <--\n");
    lista_exibir(listaProcessos);
    printf("\n--> FIM PROCESSOS <--\n");

    srand(time(NULL));
    processo = lista_obter_processo_sorteado(listaProcessos);
    exibir_processo(processo);

}
