#include <stdio.h>
#include <stdlib.h>
#include "exercise-two.h"

int main () {
    pilha pilhaInteiros;
    no_dup_enc *ultimoNo;


    pilhaInteiros = pilha_ler();
    printf("\n--> pilha <--\n");
    pilha_exibir(pilhaInteiros);
    printf("--> FIM pilha <--\n");

    pilha_inverter(pilhaInteiros);
    printf("\n--> pilha invertida <--\n");
    pilha_exibir(pilhaInteiros);
    printf("--> FIM pilha invertida <--\n");
}
