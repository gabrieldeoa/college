/*
* Modifique o algoritmo de ordenação Quick Sort para trabalhar com o primeiro
* elemento como pivô, ao invés do elemento central.
*/

#include <stdio.h>

// auxiliares
void exibir_lista(int lista[], int tamanho) {
    int i;

    for(i = 0; i < tamanho; i++) {
        printf("|%d", lista[i]);
    }
    printf("\n");
}

void troca(int *a, int *b) {
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux;
}

// algoritmo
void quicksort_recursive(int lista [], int inicio, int fim) {
    int i = inicio;
    int j = fim;
    int posicao = inicio; // = (inicio+fim)/2
    int pivo = lista[posicao];

    if(inicio >= fim) return;
    
    while(i < j) {
        while(lista[i] < pivo)
            i++;
        while(lista[j] > pivo)
            j--;
        if(lista[i] == pivo)
            posicao = i;
        else if(lista[j] == pivo)
            posicao = j;
        troca(&lista[i], &lista[j]);
    }
    quicksort_recursive(lista, posicao + 1, fim);
    quicksort_recursive(lista, inicio, posicao);
}

void quicksort(int lista[], int tamanho) {
    quicksort_recursive(lista, 0, tamanho - 1);
}

int main () {
    int TAMANHO = 10;
    int lista[] = {3, 1, 34, 21, 9, 35, 78, 66, 24, 13};

    printf("\nLista: ");
    exibir_lista(lista, TAMANHO);
    
    quicksort(lista, TAMANHO);
    
    printf("\nLista Ordenada: ");
    exibir_lista(lista, TAMANHO);

}