#include <stdio.h>
#include <stdlib.h>
#include "exercise-one.h"

int main () {
    lista listaInteiros;
    no_dup_enc *ultimoNo;


    listaInteiros = lista_ler();
    printf("\n--> LISTA <--\n");
    lista_exibir(listaInteiros);
    printf("--> FIM LISTA <--\n");

    ultimoNo = lista_ultimo_no(listaInteiros);

    printf("\n--> ultimo no %d <--\n", ultimoNo->elemento);


}
