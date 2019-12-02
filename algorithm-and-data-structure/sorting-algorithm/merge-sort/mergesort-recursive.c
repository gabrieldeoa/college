#include <stdio.h>

void exibir_lista(int lista[], int tamanho) {
    int i;

    for(i = 0; i < tamanho; i++) {
        printf("|%d", lista[i]);
    }
    printf("|\n");
}

void mergesort_recursive(int lista[], int inicio, int fim) {
    int posicao = (inicio+fim)/2;
    int i = inicio;
    int j = posicao + 1;
    int k = 0;
    int lista_auxiliar[fim-inicio+1];

    if(inicio < fim) {
        mergesort_recursive(lista, inicio, posicao);
        mergesort_recursive(lista, posicao+1, fim);

        while(i <= posicao || j <= fim) {
            if( i > posicao) {
                lista_auxiliar[k] = lista[j];
                j++;
            }
            else if (j > fim) {
                lista_auxiliar[k] = lista[i];
                i++;
            }
            else if (lista[i] < lista[j]) {
                lista_auxiliar[k] = lista[i];
                i++;
            }
            else {
                lista_auxiliar[k] = lista[j];
                j++;
            }
            k++;
        }
        k = 0;
        for(i = inicio; i <= fim; i++) {
            lista[i] = lista_auxiliar[k];
            k++;
        }

    } 
}

void mergesort(int lista[], int tamanho) {
    mergesort_recursive(lista, 0, tamanho-1);
}

int main () {
    int lista[] = {2, 5, 8, 9, 1, 6, 3, 0, 7};
    int tamanho = 9;

    exibir_lista(lista, tamanho);
    mergesort(lista, tamanho);
    exibir_lista(lista, tamanho);
}