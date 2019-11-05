#include <stdio.h>
#include <stdlib.h>
#include "disc-list.h"


int main() {
    int ANO = 2000;

    lista listaCds, sublistaCds;

    listaCds = lista_cd_ler();
    printf("LISTA PRINCIPAL");
    lista_cd_exibir(listaCds);

    sublistaCds = lista_cd_obter_lancamentos_por_ano(ANO, listaCds);
    printf("LISTA POR ANO");
    lista_cd_exibir(sublistaCds);
}
