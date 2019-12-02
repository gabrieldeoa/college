/*
* Crie o método bubble sort recursivo
*/

#include <stdio.h>

// auxiliares
void exibir_lista(int lista[], int tamanho) {
    int i;

    for(i = 0; i < tamanho; i++) {
        printf("%d|", lista[i]);
    }
    printf("\n");
}

void exibir_lista_recursivo(int lista[], int tamanho, int contador) {
    if(contador < tamanho) {
        printf("%d|", lista[contador]);
        exibir_lista_recursivo(lista, tamanho, contador + 1);
    }
}

void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

// algoritmo de ordenação
void bubblesort(int lista[], int tamanho) {
    int i, aux;

    if(tamanho > 0) {
        for(i = 0; i< tamanho - 1; i++) {
            if(lista[i] > lista[i + 1]) {
                /*
                    aux = lista[i];
                    lista[i] = lista[i + 1];
                    lista[i + 1] = aux;
                */

                // podemos simplificar com uma função
                troca(&lista[i], &lista[i + 1]);
            }
        }
        bubblesort(lista, tamanho - 1);
    }
}

// teste
int main () {
    int TAMANHO = 10;
    int lista[] = {3, 1, 34, 21, 9, 35, 78, 66, 24, 13};

    printf("\nLista: ");
    exibir_lista_recursivo(lista, TAMANHO, 0);
    
    bubblesort(lista, TAMANHO);
    
    printf("\nLista Ordenada: ");
    exibir_lista(lista, TAMANHO);

}