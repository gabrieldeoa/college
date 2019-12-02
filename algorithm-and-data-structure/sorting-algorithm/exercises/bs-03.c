/*
* Crie o método bubble sort para ordenar uma lista de veiculos
* Segue a estrutura abaixo.
*/

#include <stdio.h>
#include <string.h>
 
#define MAIOR -1
#define MENOR -2

typedef struct {
    char placa[8];
    char marca[20];
    char modelo[20];
    int ano;
} veiculo;

// auxiliares
void exibir_veiculo(veiculo v) {
    printf(
        "\n Placa: %s\n Marca: %s\n Modelo: %s\n Ano: %d\n\n",
        v.placa,
        v.marca,
        v.modelo,
        v.ano
    );
}

veiculo ler_veiculo() {
    veiculo v;

    printf("PLACA: ");
    scanf("\n");
    gets(v.placa);

    printf("MARCA: ");
    scanf("\n");
    gets(v.marca);

    printf("MODELO: ");
    scanf("\n");
    gets(v.modelo);

    printf("ANO: ");
    scanf("%d", &v.ano);

    return v;
}

void preencher_veiculo(veiculo lista[], int tamanho) {
    int i;

    for(i = 0; i < tamanho; i++) {
        lista[i] = ler_veiculo();
        printf("\n");
    }
}

int veiculo_comparar(veiculo v1, veiculo v2) {
    if(strcmp(v1.placa, v2.placa) > 0 )
        return MAIOR;
    return MENOR;
}

void exibir_lista(veiculo lista[], int tamanho) {

    int i;

    for(i = 0; i < tamanho; i++) {
        exibir_veiculo(lista[i]);
    }

    printf("\n");
}

void troca( veiculo *a, veiculo *b) {
    veiculo aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

// algoritmo de ordenação
void bubblesort_recursivo(veiculo lista[], int tamanho) {
    int i;
    veiculo aux;

    if(tamanho > 0) {
        for(i = 0; i < tamanho - 1; i++) {
            if(veiculo_comparar(lista[i], lista[i + 1]) == MAIOR) {
                aux = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = aux;
            }
        }
        bubblesort_recursivo(lista, tamanho - 1);
    }
}

void bubblesort(veiculo lista[], int tamanho) {
    int i, j;
    
    for(i = 0; i < tamanho - 1; i++) {
        for(j = 0; j < tamanho - i - 1; j++) {
            if(veiculo_comparar(lista[j], lista[j + 1]) == MAIOR) {
                troca(&lista[j], &lista[j + 1]);
            }
        }
    }
}

// teste
int main () {
    int lista[3];

    preencher_veiculo(lista, 3);

    printf("\nLista: ");
    exibir_lista(lista, 3);
    
    // bubblesort_recursivo(lista, 3);
    bubblesort(lista, 3);
    
    printf("\nLista Ordenada: ");
    exibir_lista(lista, 3);

}