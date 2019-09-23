#ifndef FILA_CLIENTES
#define FILA_CLIENTES

#include <stdio.h>
#include <stdlib.h>

#define FILA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define FILA_CHEIA -4
#define FILA_VAZIA -5
#define SUCESSO -6

typedef struct {
    int codigo;
    char nome[40];
    int idade;
    int preferencial;
} Cliente;

typedef struct {
    Cliente * elementos;
    int inicio, fim, tamanho;

} fila;

void fila_criar(fila *f, int tam) {
    f->elementos = malloc(sizeof(Cliente[tam]));
    f->inicio = f->fim = -1;
    f->tamanho = tam;
}

int fila_numero_elementos(fila f) {
    int intervalo = f.fim - f.inicio;

    if(f.inicio == -1 || f.fim == -1)
        return 0;
    
    if(f.inicio <= f.fim)
        return intervalo + 1;
    
    return intervalo + f.tamanho + 1;
}

int fila_posicao_elemento(Cliente elem, fila f) {
    int i, j, num_elems;

    num_elems = fila_numero_elementos(f);

    j = f.inicio;

    for(i = 0; i < num_elems; i++) {
        if(f.elementos[j].codigo == elem.codigo)
            return j;
        if(j == f.tamanho -1)
            j = 0;
        else
            j++;
    }

    return ELEMENTO_NAO_EXISTENTE;
}

Cliente fila_obter_elemento(int pos, fila f) {
    return f.elementos[pos];
}

int fila_inserir(Cliente elem, fila *f) {
    int num_elems, pos;

    num_elems = fila_numero_elementos(*f);
    pos = fila_posicao_elemento(elem, *f);

    if(num_elems >= f->tamanho)
        return FILA_CHEIA;
    
    if(pos != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;
    
    if(f->fim == -1)
        f->inicio = f->fim = 0;
    else if(f->fim == f->tamanho - 1)
        f->fim = 0;
    else 
        f->fim++;
    
    f->elementos[f->fim] = elem;

    return SUCESSO;
}

int fila_remover(fila *f) {
    int i, num_elems;

    num_elems = fila_numero_elementos(*f);

    if(num_elems <= 0)
        return FILA_VAZIA;
    if(f->inicio == f->fim)
        f->inicio = f->fim = -1;
    if(f->inicio == f->tamanho)
        f->inicio = 0;
    else
        f->inicio++;
    
    return SUCESSO;
}

void exibir_cliente(Cliente c) {
    printf(
        "\n Codigo: %d\n Nome: %s\n Idade: %d\n preferencial: %s\n\n",
        c.codigo,
        c.nome,
        c.idade,
        (c.preferencial) ? "Sim" : "Nao"
    );
}

void fila_exibir(fila f) {
    int i, j, num_elems;

    num_elems = fila_numero_elementos(f);

    j = f.inicio;

    for(i = 0; i < num_elems; i++) {
        exibir_cliente(f.elementos[j]);

        if(j == f.tamanho - 1)
            j = 0;
        else 
            j++;
    }

    printf("\n");
}

Cliente preencher_cliente() {
    Cliente c;

    printf("\n Codigo: ");
    scanf("%d", &c.codigo);
    printf("\n Nome: ");
    scanf("%c", &c.nome);
    gets(c.nome);
    printf(" Idade: ");
    scanf("%d", &c.idade);
    printf(" Preferencial [0 - Nao | 1 - Sim] : ");
    scanf("%d", &c.preferencial);

    return c;
}


void fila_ler(fila *f, int tam, int qtd_elems) {
    int i;
    Cliente c;

    fila_criar(f, tam);

    for(i = 0; i < qtd_elems && i < tam; i++) {
        printf("--- Cliente ---");
        c = preencher_cliente();
        fila_inserir(c, f);
    }
}

void fila_destruir(fila *f) {
    free(f->elementos);
    f->elementos = NULL;
    f->inicio = f->fim = f->tamanho = FILA_NAO_ALOCADA;
}   
#endif