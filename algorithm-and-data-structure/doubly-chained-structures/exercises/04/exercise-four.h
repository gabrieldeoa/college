#include "../03/exercise-three.h"

lista lista_obter_veiculo_por_marca(char marca[10], lista listaVeiculos) {
    lista subLista = NULL;
    no_dup_enc *no = listaVeiculos;

    while (no != NULL) {
        if( strcmp(no->elemento.marca, marca) == 0 ) {
            lista_inserir(no->elemento, &subLista);
        }

        no = no->proximo;
    }
    return subLista;
}