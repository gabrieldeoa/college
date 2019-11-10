#include "../../stack/stack.h"


void pilha_inverter(pilha pilha) {
    int auxiliar;
    no_dup_enc *noInicial, *noFinal;

    noInicial = noFinal = pilha;

    // chegar ao final e atribuir ao noFinal
    while(noFinal->proximo != NULL)
        noFinal = noFinal->proximo;

    // Enquanto o os ponteiros de no não se esbarrarem e um não ultrapassar a metade da pilha do outro
    while( noInicial != noFinal && noInicial->anterior != noFinal) {
        // guarda o inteiro que noInicial aponta
        auxiliar = noInicial->elemento;
        noInicial->elemento = noFinal->elemento;
        noFinal->elemento = auxiliar;

        noInicial = noInicial->proximo;
        noFinal = noFinal->anterior;
    }
}