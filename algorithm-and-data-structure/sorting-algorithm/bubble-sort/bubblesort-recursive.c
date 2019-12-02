#include <stdio.h>

void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubblesort(int lista[], int tamanho) {
    int i;

    if(tamanho > 0) {
        for(i = 0; i < tamanho-1; i++) {
            if(lista[i] > lista[i + 1])
                trocar(&lista[i], &lista[i+1]);
        }

        bubblesort(lista, tamanho-1);
    }
}

void exibir_lista(int lista[], int tamanho) {
    int i;

    for(i = 0; i < tamanho; i++) {
        printf("|%d", lista[i]);
    }
    printf("|\n");
}

int main () {
    int lista[] = {2, 5, 8, 9, 1, 6, 3, 0, 7};
    int tamanho = 9;

    exibir_lista(lista, tamanho);
    bubblesort(lista, tamanho);
    exibir_lista(lista, tamanho);
}