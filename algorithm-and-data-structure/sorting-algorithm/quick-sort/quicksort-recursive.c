#include <stdio.h>

void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void exibir_lista(int lista[], int tamanho) {
    int i;

    for(i = 0; i < tamanho; i++) {
        printf("|%d", lista[i]);
    }
    printf("|\n");
}

void quicksort_recursive(int lista[], int inicio, int fim) {
    int i = inicio;
    int j = fim;
    int posicao = (inicio+fim)/2;
    int pivo = lista[posicao];

    if(inicio < fim) {
        while(i < j) {
            while(lista[i] < pivo) i++;

            while(lista[j] > pivo) j--;

            if(lista[i] == pivo) posicao = i;

            else if(lista[j] == pivo) posicao = j;

            trocar(&lista[i], &lista[j]);
        }

        quicksort_recursive(lista, posicao+1, fim);
        quicksort_recursive(lista, inicio, posicao);
    }
}

void quicksort(int lista[], int tamanho) {
    quicksort_recursive(lista, 0, tamanho - 1);
}

int main () {
    int lista[] = {2, 5, 8, 9, 1, 6, 3, 0, 7};
    int tamanho = 9;

    exibir_lista(lista, tamanho);
    quicksort(lista, tamanho);
    exibir_lista(lista, tamanho);
}