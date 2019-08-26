/*
Se um vetor de números estiver ordenado, ou seja, seus elementos estão alocados
do menor para o maior número, é possível efetuar uma busca neste vetor da
seguinte forma:
Toma-se o elemento central do vetor e verifica-se se ele é o elemento procurado, se
for, retorna-se a posição dele, caso não for, verifica-se se o elemento procurado é
maior ou menor do que o elemento em análise.
Se for maior, toma-se o elemento do central entre o elemento em análise o o último
elemento do vetor e repite-se o processo até encontrar.
Caso seja menor, toma-se o elemento central entre o elemento em análise e o
primeiro elemento do vetor e repete-se o processo até encontrar.
Se o algoritmo chegar no primeiro ou no último elemento do vetor e não achar o
número procurado, é porque ele não existe ali.
Construa um algoritmo recursivo ou não recursivo que implemente o mecanismo de
busca descrito acima.
*/

#include <stdio.h>

void preencheVetor(int vetor[], int tamanho) {
    if(tamanho == 1)
        vetor[0] = tamanho;
    else {
        vetor[tamanho - 1] = tamanho;
        preencheVetor(vetor, tamanho - 1);
    }
}

void imprimeVetor(int vetor[], int tamanho, int contador) {
    if(contador < tamanho) {
        printf("[%d]", vetor[contador]);
        imprimeVetor(vetor, tamanho, contador + 1);
    }
}

int buscarElemento(int v[], int elemento, int tam) {
    int inicio = v[0], fim = v[tam - 1];
    int posicao = tam/2;

    if(elemento < 1 || elemento > tam) return -1;

    while(1) {
        if(v[posicao] == elemento)
            return posicao;

        if(elemento > v[posicao])
            inicio = posicao;
        else
            fim = posicao;

        posicao=(inicio+fim)/2;

    }
}

int buscarElementoRecursivo(int vetor[],int elemento, int inicio, int fim) {
    int posicao = (inicio+fim)/2;

    if(vetor[posicao] == elemento)
        return posicao;
    else if (posicao == inicio || posicao == fim) {
        return -1;
    }
    else {
        if(elemento > vetor[posicao]) {
            inicio = posicao;
        }
        else {
            fim = posicao;
        }
        return buscarElementoRecursivo(vetor,elemento, inicio, fim);
    }
}

int main() {
    const int TAMANHO = 10;
    int elemento = 10;
    int v[TAMANHO];

    preencheVetor(v, TAMANHO);
    imprimeVetor(v, TAMANHO, 0);
    printf("\n RECURSIVO o elemento %d esta na posicao: %d", elemento, buscarElementoRecursivo(v, elemento, 0, TAMANHO));

    printf("\no elemento %d esta na posicao: %d", elemento, buscarElemento(v, elemento, TAMANHO));
}
