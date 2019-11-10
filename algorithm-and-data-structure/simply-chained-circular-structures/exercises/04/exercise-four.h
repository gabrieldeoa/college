#include "../03/process-list.h"

processo lista_obter_processo_sorteado(lista listaProcessos) {
    int i, numeroDePassos = rand();

    no_enc* no = listaProcessos;

    for(i = 0; i < numeroDePassos; i++)
        no = no->proximo;

    return no->elemento;
}