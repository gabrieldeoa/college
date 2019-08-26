/*
Escreva uma função recursiva que retorne o maior número de um vetor.
*/
#include <stdio.h>

int maior(int vetor[], int tamanho){
    int i = 0;
    int maior = vetor[0];

    for(i; i < tamanho; i++) {
        if(vetor[i] > maior)
            maior = vetor[i];
    }
    return maior;
}

int maiorRecursivo(int vetor[], int tamanho) {
    int maior;
    if(tamanho == 1)
        return vetor[0];
    else {
         maior= maiorRecursivo(vetor, tamanho-1);

        if(vetor[tamanho-1] > maior)
            maior = vetor[tamanho-1];

        return maior;
    }
}

int main() {
    int v[4] = {11, 9, 3, 7};

    printf("O maior elemento do vetor: %d", maior(v, 4));
    printf("\n\n");
    printf("O maior elemento do vetor: %i", maiorRecursivo(v, 4));
}
