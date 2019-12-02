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

void bubblesort(int lista[], int tamanho) {
    int i, j;

    for(i = 0; i < tamanho-1; i++) {
        for(j = 0; j < tamanho - i - 1; j++) {
            if(lista[j] > lista[j + 1])
                trocar(&lista[j], &lista[j + 1]);
            }
    }

}

int main () {
    int lista[] = {2, 5, 8, 9, 1, 6, 3, 0, 7};
    int tamanho = 9;

    exibir_lista(lista, tamanho);
    bubblesort(lista, tamanho);
    exibir_lista(lista, tamanho);
}