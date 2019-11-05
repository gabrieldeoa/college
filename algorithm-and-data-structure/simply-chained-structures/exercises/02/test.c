#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main() {
    pilha pilhaInteiros;

    pilhaInteiros = pilha_ler();

    pilha_exibir(pilhaInteiros);

    pilha_remover(&pilhaInteiros);

    pilha_exibir(pilhaInteiros);
}
