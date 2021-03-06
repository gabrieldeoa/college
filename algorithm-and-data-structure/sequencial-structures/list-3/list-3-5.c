#include <stdlib.h>
#include <stdio.h>

#define ELEMENTO_NAO_EXISTENTE -1
#define PILHA_CHEIA -2
#define ELEMENTO_EXISTENTE -3
#define PILHA_VAZIA -4
#define PILHA_NAO_ALOCADA -5
#define SUCESSO -10
#define POSICAO_INVALIDA -6

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

void pilha_criar(pilha *p, int tam) {
    p->elementos = malloc(sizeof(Carta[tam]));
    p->topo = -1;
    p->tamanho = tam;
}

int pilha_numero_elementos(pilha p) {
    return p.topo+1;
}

int sao_cartas_iguais(Carta c1, Carta c2) {
    return (c1.naipe == c2.naipe && c1.numero == c2.numero);
}

int pilha_posicao_elemento(Carta elem, pilha p) {
    int i, num_elems;

    num_elems = pilha_numero_elementos(p);

    for( i = 0; i < num_elems; i++)
        if(sao_cartas_iguais(elem, p.elementos[i]))
            return i;

    return ELEMENTO_NAO_EXISTENTE;
}

Carta pilha_obter_elemento(int pos, pilha p) {
    return p.elementos[pos];
}

int pilha_inserir(Carta elem, pilha *p) {
    int pos, num_eles;

    num_eles = pilha_numero_elementos(*p);

    pos = pilha_posicao_elemento(elem, *p);

    if(num_eles >= p->tamanho)
        return PILHA_CHEIA;
    
    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;
    
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

void pilha_exibir(pilha p) {
    int i, num_elems;

    num_elems = pilha_numero_elementos(p);

    for(i = 0; i < num_elems; i++)
        exibir_carta(p.elementos[i]);

    printf("\n");

}

Carta preencher_carta() {
    Carta c;

    printf("\nDados da Carta:\n");
    printf("    Naipe: \n       0 - espadas, 1 - copas, 2 - paus e 3 ouros\n    : ");
    scanf("%d", &c.naipe);

    printf("    Numero: \n" );
    printf("    0 - as, \n    1 - um, \n    2 - dois, \n    3 - tres \n    4 - quatro, \n    5 - cinco, \n    6 - seis,\n    7 - sete, \n    8 - oito, \n    9 - nove, \n    10 - dez, \n    11 - dama, \n    12 - valete ou \n    13 - rei \n    \n: ");
    scanf("%d", &c.numero);

    return c;
}

void pilha_ler(pilha *p , int tam, int qtd_elems) {
    int i;
    Carta c;

    pilha_criar(p, tam);

    for(i = 0; i < tam && i < qtd_elems; i++) {
        c = preencher_carta();
        pilha_inserir(c, p);
    }
}

void pilha_destruir(pilha *p) {
    free(p->elementos);
    p->elementos = NULL;
    p->topo = p-> tamanho = PILHA_NAO_ALOCADA;
}
/*
    Escreva uma rotina para sacar uma carta do baralho (pilha de cartas). Essa rotina
    deve retornar uma carta do topo da pilha e em seguida excluí-la da mesma.
        
        Questao 5
*/

Carta comprar_do_baralho(pilha *p) {
    Carta c;
    c = pilha_obter_elemento(p->topo, *p);
    pilha_remover(p);

    return c;
}


int main () {
    int tam = 3, pos;
    Carta c;
    pilha cartas;

    pilha_ler(&cartas, tam , tam);

    pilha_exibir(cartas);
    printf("-----------------\n\n");

    c = comprar_do_baralho(&cartas);

    exibir_carta(c);
    printf("-----------------\n\n");

    pilha_exibir(cartas);



    /*printf("\nForneça um elemento carta para ser buscado: ");
    c = preencher_carta();

    pos = pilha_posicao_elemento(c, cartas);

    printf("\nPosicao do elemento: %d", pos);

    exibir_carta(pilha_obter_elemento(pos, cartas));

    pilha_remover(&cartas);
    printf("-----------------\n\n");
    pilha_exibir(cartas);*/
}

