#include "../03/process-list.h"

lista lista_obter_processo_por_prioridade(lista listaProcessos, int prioridade) {
    no_enc *no = listaProcessos;
    lista subLista = NULL;

    do {
        if(no->elemento.prioridade == prioridade)
            lista_inserir(no->elemento, &subLista);
        no = no->proximo;
    } while(no != listaProcessos);

    return subLista;
}