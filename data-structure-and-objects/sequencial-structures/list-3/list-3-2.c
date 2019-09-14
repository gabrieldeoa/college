#include <stdlib.h>
#include <stdio.h>

#define ELEMENTO_NAO_EXISTENTE -1
#define PILHA_CHEIA -2
#define ELEMENTO_EXISTENTE -3
#define PILHA_VAZIA -4
#define PILHA_NAO_ALOCADA -5
#define SUCESSO -10

typedef struct {
    int * elementos;
    int topo, tamanho;
} pilha;

void pilha_criar(pilha *p, int  tam) {
    p->elementos = malloc(sizeof(int[tam]));
    p->topo = -1;
    p->tamanho = tam;
}

int pilha_numero_elementos(pilha p) {
    return p.topo + 1;
}

int pilha_posicao_elemento(int elem, pilha p) {
    int i, num_elems;

    num_elems = pilha_numero_elementos(p);

    for(i = 0; i < num_elems; i++) {
        if(p.elementos[i] == elem)
            return i;
    }

    return ELEMENTO_NAO_EXISTENTE;
}

int pilha_obter_elemento(int pos, pilha p) {
    return p.elementos[pos];
}

int pilha_inserir(int elem, pilha *p) {
    int i, num_eles, pos;
    num_eles = pilha_numero_elementos(*p);
    pos = pilha_posicao_elemento(elem, *p);

    if(num_eles >= p->tamanho)
        return PILHA_CHEIA;

    if(pos != ELEMENTO_NAO_EXISTENTE)
        return  ELEMENTO_EXISTENTE;
    p->elementos[num_eles] = elem;
    p->topo++;

    return SUCESSO;
}

int pilha_remover(pilha *p) {
    int num_elems;
    num_elems = pilha_numero_elementos(*p);

    if(num_elems <= 0)
        return PILHA_VAZIA;

    p->topo--;

    return SUCESSO;
}

void pilha_exibir(pilha p) {
    int i, num_elems;

    num_elems = pilha_numero_elementos(p);

    for(i = 0; i < num_elems; i++)
        printf("%d|", p.elementos[i]);

    printf("\n");
}

void pilha_ler(pilha *p, int tam, int qtd_elems) {
    int i, elem;
    pilha_criar(p, tam);

    for(i = 0; i < tam && i < qtd_elems; i++) {
        printf("Pilha[%d] = ", i);
        scanf("%d", &elem);
        pilha_inserir(elem, p);
    }
}

void pilha_destruir(pilha *p) {
    free(p->elementos);
    p->elementos = NULL;
    p->topo = p->tamanho = PILHA_NAO_ALOCADA;
}

/*
Escreva uma rotina que receba duas pinhas e empilhe a segunda sobre a primeira.
Após isso, elimine a segunda pilha da memória.
*/

int empilhar(pilha *p1, pilha *p2, pilha *np) {
    int i, j, num_elems_p1, num_elems_p2, novo_tam;

    num_elems_p1 = pilha_numero_elementos(*p1);
    num_elems_p2 = pilha_numero_elementos(*p2);
    novo_tam = num_elems_p1 + num_elems_p2;

    if(num_elems_p1 <= 0 || num_elems_p2 <= 0)
        return PILHA_VAZIA;

    pilha_criar(np, novo_tam);

    j = 0;

    for(i = 0; i < novo_tam; i++) {
        if(i < num_elems_p1)
            pilha_inserir(p1->elementos[i], np);
        else {
            pilha_inserir(p2->elementos[j], np);
            j++;
        }
    }

    pilha_destruir(p2);

    return SUCESSO;
}

int main () {
    pilha p1, p2, np;

    pilha_ler(&p1, 3, 3);
    pilha_ler(&p2, 6, 7);
    pilha_exibir(p1);
    pilha_exibir(p2);

    empilhar(&p1, &p2, &np);
    pilha_exibir(np);
}
