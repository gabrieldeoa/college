#include <stdio.h>
#include <stdlib.h>
#include "exercise-five.h"

int main () {
    lista listaProcessos, listaProcessoPrioridade;
    int PRIORIDADE = 2;

    listaProcessos = lista_ler();
    printf("\n--> PROCESSOS <--\n");
    lista_exibir(listaProcessos);
    printf("--> FIM PROCESSOS <--\n");

    listaProcessoPrioridade = lista_obter_processo_por_prioridade(listaProcessos, PRIORIDADE);
    printf("\n--> PROCESSOS DE PRIORIDADE %d <--\n", PRIORIDADE);
    lista_exibir(listaProcessoPrioridade);
    printf("--> FIM PROCESSOS <--\n");

}
