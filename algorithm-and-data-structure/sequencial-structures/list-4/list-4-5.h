#include "list-4-2.h"

int fila_atender(fila *f, int atendentes) {
    int i, num_elems;

    num_elems = fila_numero_elementos(*f);

    if(num_elems <= 0)
        return FILA_VAZIA;
    
    for(i = 0; i < atendentes; i++ ) {
        fila_remover(f);
    }

    return SUCESSO;
   
}