#include <stdio.h>
#include <stdlib.h>

#define LISTA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define LISTA_CHEIA -4
#define LISTA_VAZIA -5
#define SUCESSO -6

typedef enum TGenero {
    feminino,
    masculino,
    outro
} Genero;

typedef enum TCorOlhos {
    castanhos,
    azuis,
    verdes,
    pretos,
    outros

} CorOlhos;

typedef struct TPessoa {
    char nome[40];
    int idade;
    float altura;
    float peso;

} Pessoa;

Pessoa** criarListaPessoa(int tam) {
    int i;
    Pessoa **lista;

    lista = calloc(tam, sizeof(Pessoa*[tam]));

    return lista;
}

int tamanhoListaPessoa(Pessoa **lista, int tam) {
    int i;

    if(lista == NULL) return LISTA_NAO_ALOCADA;

    for(i=0; i < tam; i++)
        if(lista[i] == NULL)
            return i;

    return tam;
}

int posicaoDoElementoPessoa(char * elemento, Pessoa **lista, int tam) {
    int i, totalElementos;

    if(lista == NULL)
        return LISTA_NAO_ALOCADA;

    totalElementos = tamanhoListaPessoa(lista, tam);

    for(i=0; i < totalElementos; i++)
        if(lista[i]->nome == elemento)
            return i;

    return ELEMENTO_NAO_EXISTENTE;
}

int inserirElementoPessoa(Pessoa elemento, Pessoa **lista, int tam) {
    int i, totalElementos, posicaoElemento;

    totalElementos = tamanhoListaPessoa(lista, tam);

    if(totalElementos >= tam )
        return LISTA_CHEIA;

    posicaoElemento = posicaoDoElementoPessoa(elemento.nome, lista, tam);

    if(posicaoElemento != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;

    lista[totalElementos] = malloc(sizeof(Pessoa));

    *(lista[totalElementos]) = elemento;

    return SUCESSO;
}

int removerElementoPessoa(char* elemento, Pessoa** lista, int tam) {
    int i, posicao, totalElementos;

    totalElementos = tamanhoListaPessoa(lista, tam);
    posicao = posicaoDoElementoPessoa(elemento, lista, tam);

    if(totalElementos <= 0)
        return LISTA_VAZIA;

    if(posicao == ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_NAO_EXISTENTE;

    free(lista[posicao]);

    for(i = posicao; i < totalElementos-1; i++)
        lista[i] = lista[i + 1];

    lista[i] = NULL;

    return SUCESSO;
}

void exibirListaPessoa(Pessoa **lista, int tam) {
    int i;

    for(i = 0; i < tam; i++)
        if(lista[i] != NULL) {
            printf("\nPESSOA[%d]\n", i);
            printf(
                " Nome: %s\n Idade: %d\n Altura: %.2f\n Peso: %.2f\n\n",
                lista[i]->nome,
                lista[i]->idade,
                lista[i]->altura,
                lista[i]->peso
            );

        }
        else
            printf("N|");
    printf("\n");
}

Pessoa** lerListaPessoa(int tam) {
    int i;
    Pessoa elemento, ** lista;

    lista = criarListaPessoa(tam);

    for(i=0; i < tam; i++) {
        printf("PESSOA[%d]", i);

        printf("\n Nome: ");
        gets(elemento.nome);
        printf(" idade: ");
        scanf("%d", &elemento.idade);
        printf(" altura: ");
        scanf("%f", &elemento.altura);
        printf(" peso: ");
        scanf("%f", &elemento.peso);

        if(*elemento.nome == '\0')
            return lista;

        inserirElementoPessoa(elemento, lista, tam);
    }

    return lista;
}

void destruirListaPessoa(Pessoa** lista, int tam) {
    int i;

    for(i=0; i < tam; i++)
        free(lista[i]);

    free(lista);
}

int main() {
    const int TAM = 1;

    Pessoa **listaPessoa;

    listaPessoa = lerListaPessoa(TAM);

    exibirListaPessoa(listaPessoa, TAM);

    printf("\nO tamanho da lista de pessoas e: ")




}
