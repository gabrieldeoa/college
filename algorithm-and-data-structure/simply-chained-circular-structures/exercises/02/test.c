#include "exercise-two.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    lista listaUm, listaDois;

    listaUm = lista_ler();
    lista_exibir(listaUm);

    listaDois = lista_ler();
    lista_exibir(listaDois);
    
    lista_remover_elementos(listaUm, listaDois);
    printf("\n-------------\n");
    lista_exibir(listaUm);
}

