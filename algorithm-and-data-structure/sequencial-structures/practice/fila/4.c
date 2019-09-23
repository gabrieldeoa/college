/*
Crie uma rotina que receba duas filas e gere uma fila única a partir das duas.
A regra para a composição da fila é: a cada posição de ambas as listas o cliente mais
velho fica à frente.
*/

#include "2.h" // era pra ta com a biblioteca que na exclusao reorganiza, mas deu preguica
#include <math.h>

fila fila_unica(fila f1, fila f2) {
    int i, ne_1, ne_2, ne, tam;
    fila auxilar;

    tam = f1.tamanho + f2.tamanho;
    fila_criar(&auxilar, tam);
    ne = fmax(ne_1,ne_1); // retorna o maior

    for(i = 0; i < ne; i++) {
        if(i >= ne_1) //Acabou os elementos da fila 1
            fila_inserir(fila_obter_elemento(i, f2), &auxilar);

        else if(i >= ne_2) //Acabou os elementos da fila 2
            fila_inserir(fila_obter_elemento(i, f1), &auxilar);

        else if(fila_obter_elemento(i, f1).idade >= fila_obter_elemento(i, f2).idade) {

            fila_inserir(fila_obter_elemento(i, f1), &auxilar);
            fila_inserir(fila_obter_elemento(i, f2), &auxilar);

        } else {

            fila_inserir(fila_obter_elemento(i, f2), &auxilar);
            fila_inserir(fila_obter_elemento(i, f1), &auxilar);
        }
        
        return auxilar;
    }
}
