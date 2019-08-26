/*
Escreva uma função recursiva que retorne o menor número de um vetor.
*/
#include <stdio.h>

int menor(int vetor[], int tamanho){
    int i = 0;
    int menor = vetor[0];

    for(i; i < tamanho; i++) {
        if(vetor[i] < menor)
            menor = vetor[i];
    }
    return menor;
}

int menorRecursivo(int vetor[], int tamanho) {
    if(tamanho == 1)
        return vetor[0];
    else {
        int menor = menorRecursivo(vetor, tamanho-1);

        if(vetor[tamanho-1] < menor)
            menor = vetor[tamanho-1];

        return menor;
    }
}

int main() {
    int v[3] = {2, 1, 7};

    printf("O menor elemento do vetor: %d", menor(v, 3));
    printf("\n\n");
    printf("O menor elemento do vetor: %i", menorRecursivo(v, 3));
}
