#include <stdlib.h>
#include <stdio.h>
#ifndef PILHA_CARTAS
#define PILHA_CARTAS

#define ELEMENTO_NAO_EXISTENTE -1
#define PILHA_CHEIA -2
#define ELEMENTO_EXISTENTE -3
#define PILHA_VAZIA -4
#define PILHA_NAO_ALOCADA -5
#define SUCESSO -6
#define DIFERENTE -7
#define IGUAL 0


/* DEFINICOES DE TIPO*/
typedef enum {
    espadas, copas, paus, ouros
} naipe;

typedef enum {
    as = 1, dois, tres, quatro, cinco, seis, sete, oito, nove, dez, dama, valete, rei
} numero;

typedef struct {
    naipe naipe;
    numero numero;
} carta;

typedef struct {
    carta * elementos;
    int topo, tamanho;
} pilha;

/* FUNCOES AUXILIARES PARA OS TIPOS */

char * naipe_para_texto(naipe n) {
    switch(n) {
        case espadas: return "espadas";
        case copas: return "copas";
        case paus: return "paus";
        case ouros: return "ouros";
        default: "Naipe inválido";

    }
}

char * numero_para_texto(numero n) {
    switch(n) {
        case as: return "as";
        case dois: return "dois";
        case tres: return "tres";
        case quatro: return "quatro";
        case cinco: return "cinco";
        case seis: return "seis";
        case sete: return "sete";
        case oito: return "oito";
        case nove: return "nove";
        case dez: return "dez";
        case dama: return "dama";
        case valete: return "valete";
        case rei: return "rei";
        default: "Numero inválido";
    }
}

int sao_cartas_iguais(carta c1, carta c2) {
    if(c1.naipe == c2.naipe && c1.numero == c2.numero)
        return IGUAL;
    else
        return DIFERENTE;
}

void carta_exibir(carta carta) {
    printf("|[%s,%s]", numero_para_texto(carta.numero) , naipe_para_texto(carta.naipe) );
}

carta carta_ler() {
    carta c;
    printf("Numero [AS=1,...,Q=11,J=12,K=13]: ");
    scanf("%d",&c.numero);
    printf("Naipe [ESPADAS=0, COPAS=1, PAUS=2, OUROS=3]: ");
    scanf( "%d,%d", &c.naipe );

    return c;
}

/* OPERACAOES DE PILHA */

//criar
void pilha_carta_criar(pilha *p, int tam) {
    p->elementos = malloc(sizeof(carta[tam]));
    p->topo = -1;
    p->tamanho = tam;
}

//numero elementos
int pilha_carta_numero_elementos(pilha p) {
    return p.topo + 1;
}

//posicao elemento
int pilha_carta_posicao_elemento(carta elemento, pilha p) {
    int i, ne;
    ne = pilha_carta_numero_elementos(p);

    for(i = 0; i < ne; i++) {
        if(sao_cartas_iguais(p.elementos[i], elemento) == IGUAL)
            return i;
    }

    return ELEMENTO_NAO_EXISTENTE;
}

//obter elemento
carta pilha_carta_obter_elemento(int posicao, pilha p) {
    return p.elementos[posicao];
}

//inserir
int pilha_carta_inserir(carta elemento, pilha *p) {
    int ne, pos;
    ne = pilha_carta_numero_elementos(*p);
    pos = pilha_carta_posicao_elemento(elemento, *p);

    if(ne >= p->tamanho)
        return PILHA_CHEIA;

    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;

    p->elementos[ne] = elemento;
    p->topo++;

    return SUCESSO;
    
}

//remover
int pilha_carta_remover(pilha *p) {
    int ne, pos;
    ne = pilha_carta_numero_elementos(*p);

    if(ne <= 0)
        return PILHA_VAZIA;
    
    p->topo--;
    return SUCESSO;
}

//exibir
void pilha_carta_exibir(pilha p) {
    int i, ne;
    ne = pilha_carta_numero_elementos(p);

    for(i = 0; i < ne; i++) {
        carta_exibir(p.elementos[i]);
    }

    printf("\n");
}

//ler
void pilha_carta_ler(pilha *p, int tam, int qtd) {
    int i;
    carta elemento;

    pilha_carta_criar(p, tam);

    for(i = 0; i < tam && i < qtd; i++) {
        printf("LISTA[%d]= ",i);
        elemento = carta_ler();
        pilha_carta_inserir(elemento, p);

    }
}

//destruir
void pilha_carta_destruir(pilha *p) {
    free(p->elementos);
    p->elementos = NULL;
    p->topo = p->tamanho = PILHA_NAO_ALOCADA;
}

#endif