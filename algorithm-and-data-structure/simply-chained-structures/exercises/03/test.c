#include <stdio.h>
#include <stdlib.h>
#include "disc-list.h"


int main() {
    lista listaCds;

    cd discoASerRemovido;
    discoASerRemovido.codigo = 1;

    listaCds = lista_cd_ler();

    lista_cd_exibir(listaCds);

    lista_cd_remover(discoASerRemovido, &listaCds);

    lista_cd_exibir(listaCds);
}
