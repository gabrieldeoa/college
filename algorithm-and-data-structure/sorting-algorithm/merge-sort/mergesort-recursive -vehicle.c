#include <stdio.h>
#include <string.h>

typedef struct {
    char placa[8];
    /*char marca[20];
    char modelo[20];
    int ano;*/
} veiculo;

void exibir_lista(veiculo lista[], int tamanho) {
    int i;

    for(i = 0; i < tamanho; i++) {
        printf("|%s", lista[i].placa);
    }
    printf("|\n");
}

void mergesort_recursive(veiculo lista[], int inicio, int fim) {
    int posicao = (inicio+fim)/2;
    int i = inicio;
    int j = posicao + 1;
    int k = 0;
    veiculo lista_auxiliar[fim-inicio+1];

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
            else if (strcmp(lista[i].placa, lista[j].placa) == -1 ) {
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
    veiculo lista[3];
    int tamanho = 3;

    strcpy(lista[0].placa, "qqqqq");
    strcpy(lista[1].placa, "bbbbb");
    strcpy(lista[2].placa, "aaaa");

    exibir_lista(lista, tamanho);
    mergesort(lista, tamanho);
    exibir_lista(lista, tamanho);
}