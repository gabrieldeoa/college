#include <stdio.h>
#include <stdlib.h>
#include "process-list.h"

int main () {
    lista listaProcessos;
    int quantidadeElementos;
    processo processo;

    listaProcessos = lista_ler();
    printf("\n--> PROCESSOS <--\n");
    lista_exibir(listaProcessos);
    printf("\n--> FIM PROCESSOS <--\n");


    quantidadeElementos = lista_numero_elementos(listaProcessos);
    printf("\nA lista de processos possui %d elementos.", quantidadeElementos);

    printf("\nQual é o pid do proceso que voce deseja remover: ");
    scanf("%d", &processo.pid);

    lista_remover(processo, &listaProcessos);

    printf("\n--> PROCESSOS <--\n");
    lista_exibir(listaProcessos);
    printf("\n--> FIM PROCESSOS <--\n");
}