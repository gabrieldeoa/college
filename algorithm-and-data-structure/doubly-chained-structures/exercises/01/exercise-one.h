#include "../../list/list.h"


no_dup_enc* lista_ultimo_no(lista lista) {
    no_dup_enc *ultimoNo = lista;

    if( lista != NULL)
        while(ultimoNo->proximo != NULL)
            ultimoNo = ultimoNo->proximo;
    
    return ultimoNo;
}