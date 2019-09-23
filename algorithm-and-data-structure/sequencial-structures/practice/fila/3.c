/*
Crie uma biblioteca para trabalhar com duas filas de clientes simultâneamente.

Uma das filas será a “convencional” e a outra a “prioritária”. Ao inserir um el-
emento, deve-se verificar se o cliente é preferêncial ou não. Caso seja, deve-se

inseri-lo na fila “prioritária”, caso contrário, na fila “convencional”. Ao retirar um
cliente na fila deve-se observar as seguintes regras:
1. Caso existam clientes em ambas as filas, as três primeiras remoções serão
da fila preferêncial e a quarta da fila convencional, essa regra deve ser
aplicada sucessivas vezes até que uma das filas fiquem vazias.

2. Caso uma das filas esteja esteja vazia, as remoções irão acontecer apenas na
fila que possui elementos.
*/

#include "2.h"

int remocoes_fila_preferencial = 0;

void fila_inserir_cliente(cliente cliente, fila *convencional, fila *preferencial) {
    if(cliente.preferencial == 1)
        fila_inserir(cliente, preferencial);
    else
        fila_inserir(cliente, convencional);

}

void fila_remover_cliente(fila *convencional, fila *preferencial) {
    int ne_fc, ne_fp;

    ne_fp = fila_numero_elementos(*preferencial);
    ne_fc = fila_numero_elementos(*convencional);
    
    if( ne_fp > 0 && remocoes_fila_preferencial < 3 ) {
        
        fila_remover(preferencial);
        remocoes_fila_preferencial++;

    } else if(ne_fc > 0) {

        fila_remover(convencional);
        remocoes_fila_preferencial = 0;
    }
}