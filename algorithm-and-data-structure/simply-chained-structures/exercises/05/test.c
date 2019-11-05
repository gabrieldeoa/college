#include <stdio.h>
#include <stdlib.h>
#include "disc-list.h"


int main() {
    int ANO = 2000;

    lista listaUmCds, listaDoisCds, listaIntercalada;

    printf("\nLISTA UM\n");
    listaUmCds = lista_cd_ler();
    lista_cd_exibir(listaUmCds);

    printf("\nLISTA DOIS\n");
    listaDoisCds = lista_cd_ler();
    lista_cd_exibir(listaDoisCds);

    listaIntercalada = lista_cd_alternar_listas(listaUmCds, listaDoisCds);
    printf("\nLISTA INTERCALADA");
    lista_cd_exibir(listaIntercalada);
}
