#include "../../stack/stack.h"

int pilha_sortear(pilha pilha, int sentidoHorario) {
    int i, numeroPassos;
    no_dup_enc *no = pilha;

    numeroPassos = rand();

    for(i = 0; i < numeroPassos; i++) {
        if(sentidoHorario) 
           no = no->proximo;

        else 
           no = no->anterior;
    }

    return no->elemento;
}

int pilha_soma_sorteada(pilha pilhaUm, pilha pilhaDois) {
    int sorteadoUm, sorteadoDois;

    sorteadoUm = pilha_sortear(pilhaUm, 1);
    sorteadoDois = pilha_sortear(pilhaDois, 0);

    return sorteadoUm + sorteadoDois;
}