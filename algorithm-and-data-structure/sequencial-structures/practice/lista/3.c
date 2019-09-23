/*
Modifique a rotina lista_pos_elemento para que receba um novo parâmetro
booleano chamado ordenada. Caso o parâmetro tenha valor 0 (f alse), deve-se
realizar a busca tal como está implementada, ou seja, sequencialmente. Caso o
parâmetro tenha valor 1 (true), deve-se realizar a busca binária para encontrar o
elemento desejado.
*/

#include "lista.h"

int lista_posicao_elemento_ordenada(int elemento, int **lista, int tamanho, int ordenada) {
    int i, numero_elementos, inicio, fim, posicao;

    numero_elementos = lista_numero_elementos(lista, tamanho);

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;

    inicio = 0;
    fim = numero_elementos - 1;
    posicao = (inicio + fim)/2;

    if(!ordenada) {
        for(i = 0; i < numero_elementos; i++)
            if( *(lista[i]) == elemento ) 
                return i;
            
    }
    else {
        while(inicio <= fim) {
            if(elemento == *(lista[posicao]))
                return posicao;
            
            else if(elemento > *(lista[posicao]) )
                inicio = posicao = (inicio + fim + 1)/2;
            
            else 
                fim = posicao = (inicio + fim )/2;

            if(inicio == fim)
                return ELEMENTO_NAO_EXISTENTE;
        }

        return ELEMENTO_NAO_EXISTENTE;
    }
}
