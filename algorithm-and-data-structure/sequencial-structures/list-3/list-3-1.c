#define ELEMENTO_NAO_EXISTENTE -1
#define PILHA_CHEIA -2
#define ELEMENTO_EXISTENTE -3
#define PILHA_VAZIA -4
#define PILHA_NAO_ALOCADA -5
#define SUCESSO -10

typedef struct{
    int * elementos;
    int topo1, topo2, tamanho;
} pilha_dupla;

void pilha_criar(pilha_dupla *p, int tam) {
    p->elementos = malloc(sizeof(int[tam]));
    p->topo1 = -1;
    p->topo2 = tam;
    p->tamanho = tam;
}

int pilha_numero_elementos(pilha_dupla p, int tipo_pilha) {
    if(tipo_pilha == 1)
        return p.topo1 + 1;
    else
        return p.tamanho - p.topo2;
}

int pilha_posicao_elemento(int elem, pilha_dupla p, int tipo_pilha) {
    int i;
    if(tipo_pilha == 1) {
        for(i = 0; i < p.topo1; i++)
            if(p.elementos[i] == elem)
                return i;
    }
    else {
        for(i = p.tamanho - 1; i >= p.topo2; i--)
            if(p.elementos[i] == elem)
                return i;
    }

    return ELEMENTO_NAO_EXISTENTE;
}

int pilha_obter_elemento(int pos, pilha_dupla p) {
    return p.elementos[pos];
}

int pilha_inserir(int elem, pilha_dupla *p, int tipo_pilha) {
    int pos;
    pos = pilha_posicao_elemento(elem, *p, tipo_pilha);
    if(p->topo1 + 1 == p->topo2)
        return PILHA_CHEIA;
    
    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;
    
    if(tipo_pilha == 1) {
        p->topo1++;
        p->elementos[p->topo1] = elem;
    } else {
        p->topo2--;
        p->elementos[p->topo2] = elem;
    }

    return SUCESSO;
}

int pilha_remover(pilha_dupla *p, int tipo_pilha) {
    int num_elems;

    num_elems = pilha_numero_elementos(*p, tipo_pilha);

    if(num_elems <= 0)
        return PILHA_VAZIA;
    
    if(tipo_pilha == 1)
        p->topo1--;
    else
        p->topo2++;
    
    return SUCESSO;
}

void pilha_exibir(pilha_dupla p, int tipo_pilha) {
    int i;
    if(tipo_pilha == 1) {
        for(i = 0; i<= p.topo1; i++) {
            printf("%d|", p.elementos[i]);
        }
    }
    else {
        for(i = p.tamanho -1; i >= p.topo2; i--) {
            printf("%d|", p.elementos[i]);
        }
    }
}

