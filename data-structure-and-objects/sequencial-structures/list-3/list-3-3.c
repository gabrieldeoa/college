#include <stdlib.h>
#include <stdio.h>

#define ELEMENTO_NAO_EXISTENTE -1
#define PILHA_CHEIA -2
#define ELEMENTO_EXISTENTE -3
#define PILHA_VAZIA -4
#define PILHA_NAO_ALOCADA -5
#define SUCESSO -10

typedef enum {
    espadas, copas, paus, ouros
} Naipe;

typedef enum {
    as, um, dois, tres, quatro, cinco, seis, sete, oito, nove, dez, dama, valete, rei
} Numero;

typedef struct {
    Naipe naipe;
    Numero numero;
} Carta;

typedef struct {
    Carta * elementos;
    int topo, tamanho;
} pilha;


void pilha_cartas_criar(pilha *p, int tam) {
    p->elementos = malloc(sizeof(Carta [tam]));
    p->topo = -1;
    p->tamanho = tam;
}

int pilha_cartas_numero_elementos(pilha p) {
    return p.topo+1;
}

int sao_cartas_iguais(Carta c1, Carta c2) {
    return (c1.naipe == c2.naipe && c1.numero == c2.numero);
}

int pilha_cartas_posicao_elemento(Carta elem, pilha p) {
    int i, num_elems;
    num_elems = pilha_cartas_numero_elementos(p);

    for(i = 0; i < num_elems; i++)
        if( sao_cartas_iguais(p.elementos[i], elem) )
            return i;

    return ELEMENTO_EXISTENTE;    
}

Carta pilha_cartas_obter_elemento(int pos, pilha p) {
    return p.elementos[pos];
}

int pilha_cartas_inserir(Carta elem, pilha *p) {
    int num_elems, pos;

    num_elems = pilha_cartas_numero_elementos(*p);

    pos = pilha_cartas_posicao_elemento(elem, *p);

    if(num_elems >= p->tamanho)
        return PILHA_CHEIA;
    
    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;

    p->elementos[num_elems] = elem;
    p->topo++;
    return SUCESSO;

}

int pilha_cartas_remover(pilha *p) {
    int num_elems;

    num_elems = pilha_cartas_numero_elementos(*p);

    if(num_elems<= 0)
        return PILHA_VAZIA;

    p->topo--;

    return SUCESSO;
}

char * naipe_para_texto(Naipe n) {
    switch(n) {
        case espadas: return "espadas";
        case copas: return "copas";
        case paus: return "paus";
        case ouros: return "ouros";
        default: "Naipe inválido";

    }
}

char * numero_para_texto(Numero n) {
    switch(n) {
        case as: return "as";
        case um: return "um";
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

void exibir_carta(Carta c) {
    printf("\nCarta: \n   Naipe: %s\n   Numero: %s\n", naipe_para_texto(c.naipe), numero_para_texto(c.numero));
}

void pilha_cartas_exibir(pilha p) {
    int i, num_elems;

    num_elems = pilha_cartas_numero_elementos(p);

    for(i = 0; i < num_elems; i++)
        exibir_carta(p.elementos[i]);
    
    printf("\n");

}

Carta preencher_carta() {
    Carta c;

    printf("Dados da Carta:\n");
    printf("    Naipe: \n [0 - espadas, 1 - copas, 2 - paus e 3 ouros]: ");
    scanf("%d", c.naipe);

    printf("    Numero: \n" );
    printf("        [0 - as, 1 - um, 2 - dois, 3 - tres 4 - quatro, 5 - cinco, 6 - seis, 7 - sete, 8 - oito, 9 - nove, 10 - dez, 11 - dama, 12 - valete ou 13 - rei: ");
    scanf("%d", c.numero);

    return c;
}

void pilha_cartas_ler(pilha *p , int tam) {
    int i;
    Carta c;

    pilha_cartas_criar(p, tam);

    for(i = 0; i < tam; i++) {
        c = preencher_carta();
        pilha_cartas_inserir(c, p);
    }
}

void pilha_cartas_destruir(pilha *p) {
    free(p->elementos);
    p->elementos = NULL;
    p->topo = p-> tamanho = PILHA_NAO_ALOCADA;
}





