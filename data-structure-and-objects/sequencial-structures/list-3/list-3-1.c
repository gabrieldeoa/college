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
    p->topo1 = 0;
    p->topo2 = -1;
    p->tamanho = tam;
}