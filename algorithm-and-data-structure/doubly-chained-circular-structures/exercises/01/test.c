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

    printf("\n--> LISTA <--\n");
    lista_exibir_intercalada(listaInteiros);
    printf("--> \nFIM LISTA <--\n");


}
