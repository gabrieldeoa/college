#define ELEMENTO_NAO_EXISTENTE -1
#define PILHA_CHEIA -2
#define ELEMENTO_EXISTENTE -3
#define PILHA_VAZIA -4
#define PILHA_NAO_ALOCADA -5
#define SUCESSO -6

typedef struct {
    int * elementos;
    int topo , tamanho;
} pilha;

void pilha_criar ( pilha * p , int tam ) {
    p->elementos = malloc ( sizeof (int [ tam ]) );
    p->topo = -1;
    p->tamanho = tam;
}

int pilha_numero_elementos ( pilha p ) {
    return p.topo + 1;
}

int pilha_posicao_elemento ( int elem , pilha p){
    int i , num_elems ;
    num_elems = pilha_numero_elementos (p);

    for ( i =0; i < num_elems ; i ++)
        if( p.elementos [ i ] == elem )
            return i ;

    return ELEMENTO_NAO_EXISTENTE;
}

int pilha_obter_elemento(int pos , pilha p ) {
    return p.elementos[ pos ];
}

int pilha_inserir(int elem, pilha*p){
    int i, num_elems;
    num_elems = pilha_nnumero_elementos(*p);
    if(num_elems >= p->tamanho)
        return PILHA_CHEIA;
    if(pilha_posicao_elemento(elem, *p) != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;

    p->elementos[num_elems] = elem;
    p->topo++;
    return SUCESSO;
}

int pilha_remover (pilha *p){
    int i,num_elems;
    num_elems=pilha_numero_elementos(*p);
    if(num_elems <= 0)
        return PILHA_VAZIA;
    p->topo--;
    return SUCESSO;
}

void pilha_exibir (pilha p){

    int i, num_elems = pilha_numero_elementos(p);
    for (i = 0; i<num_elems; i++)
        printf("%d|", p.elementos[i]);
    printf("\n");
}

void pilha_ler (pilha* p, int tam){
    int i, elem;

    pilha_criar(p, tam);
    for(i=0; i<tam; i++){
        printf("PILHA [%d]", i);
        scanf("%d", &elem);
        if(elem == '#')
            break;
        pilha_inserir(elem, p);
    }
}

void pilha_destruir(pilha *p){
    free(p-> elementos);
    p->elementos = NULL;
    p->topo = p->tamanho = PILHA_NAO_ALOCADA;
}

