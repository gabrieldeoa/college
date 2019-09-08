#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENTO_NAO_EXISTENTE -1
#define PILHA_CHEIA -2
#define ELEMENTO_EXISTENTE -3
#define PILHA_VAZIA -4
#define PILHA_NAO_ALOCADA -5
#define SUCESSO -6

/*
    REPRESENTACAO

    typedef struct {
        <TIPO>* <INDENTIFICADOR>
        int topo, tamanho;
    } pilha;
*/

/* DEFINICAO TIPOS */
typedef enum TGenero{
    feminino = 1,
    masculino,
    outro
} Genero;

typedef enum TCorOlhos {
    castanhos = 1,
    azuis,
    verdes,
    pretos,
    outros
} CorOlhos;

typedef struct {
    char nome[40];
    int idade;
    float altura;
    float peso;
    Genero genero;
    CorOlhos cor;

} Pessoa;

typedef struct {
    Pessoa * elementos;
    int topo , tamanho;
} Pilha;
/*-- FIM DEFINICAO TIPOS --*/

/* FUNCOES AUXILIARES */
char * cor_olhos_para_texto(CorOlhos cor) {
    switch(cor) {
        case castanhos: return "castanhos";
        case azuis: return "azuis";
        case verdes: return "verdes";
        case pretos: return "pretos";
        case outros: return "outros";
        default: "cor dos olhos inválida";
    }
}

char * genero_para_texto(Genero genero) {
    switch(genero) {
        case feminino: return "feminino";
        case masculino: return "masculino";
        case outro: return "outro";
        default: "genero inválido";
    }
}

Pessoa preencher_pessoa() {
    Pessoa pessoa;

    printf("\n Nome: ");
    scanf("\n", &pessoa.nome);
    gets(pessoa.nome);
    printf(" Idade: ");
    scanf("%d", &pessoa.idade);
    printf(" Altura: ");
    scanf("%f", &pessoa.altura);
    printf(" Peso: ");
    scanf("%f", &pessoa.peso);
    printf(" Genero: ");
    printf("\n     1 - feminino\n     2 - masculino\n     3 - outros\n          Escolha um: ");
    scanf("%d", &pessoa.genero);
    printf(" cor dos olhos: ");
    printf("\n     1 - castanhos\n     2 - azuis\n     3 - verdes\n     4 - pretos\n     5 - outros\n          Escolha uma: ");
    scanf("%d", &pessoa.cor);

    return pessoa;
}

void exibir_pessoa(Pessoa p) {
    printf(
        " Nome: %s\n Idade: %d\n Altura: %.2f\n Peso: %.2f\n Genero: %s\n Cor dos Olhos: %s\n",
        p.nome,
        p.idade,
        p.altura,
        p.peso,
        genero_para_texto(p.genero),
        cor_olhos_para_texto(p.cor)
    );
}
/*-- FIM FUNCOES AUXILIARES --*/


/* OPERACOES DE PILHA */
void pilha_pessoa_criar ( Pilha * p , int tam ) {
    p->elementos = malloc(sizeof (Pessoa[ tam ]));
    p->topo = -1;
    p->tamanho = tam;
}

int pilha_pessoa_numero_elementos ( Pilha p ) {
    return p.topo + 1;
}

int pilha_pessoa_posicao_elemento ( Pessoa elem , Pilha p) {
    int i , num_elems;
    num_elems = pilha_pessoa_numero_elementos (p);

    for (i = 0; i < num_elems ; i ++)
        if(strcmp(p.elementos[ i ].nome, elem.nome) == 0 )
            return i;

    return ELEMENTO_NAO_EXISTENTE;
}

Pessoa pilha_pessoa_obter_elemento ( int pos , Pilha p ) {
    return p.elementos[ pos ];
}

int pilha_pessoa_inserir(Pessoa elem, Pilha *p){
    int i, num_elems;
    num_elems = pilha_pessoa_numero_elementos(*p);

    if(num_elems >= p->tamanho) return PILHA_CHEIA;

    if(pilha_pessoa_posicao_elemento(elem, *p) != ELEMENTO_NAO_EXISTENTE) return ELEMENTO_EXISTENTE;

    p->elementos[num_elems] = elem;
    p->topo++;
    return SUCESSO;
}

int pilha_pessoa_remover (Pilha *p) {
    int i, num_elems;

    num_elems = pilha_pessoa_numero_elementos(*p);

    if(num_elems <= 0) return PILHA_VAZIA;

    p->topo--;

    return SUCESSO;
}

void pilha_pessoa_exibir(Pilha p) {
    int i, num_elems = pilha_pessoa_numero_elementos(p);

    for (i = 0; i < num_elems; i++) {
        printf("\nPessoa [%d]\n", i);
        exibir_pessoa(p.elementos[i]);
    }

    printf("\n");
}

void pilha_pessoa_ler (Pilha *p, int tam, int qtd_elems){
    int i;
    Pessoa elemento;

    pilha_pessoa_criar(p, tam);

    for(i = 0; i < qtd_elems || i < tam; i++) {
        elemento = preencher_pessoa();
        pilha_pessoa_inserir(elemento, p);
    }
}

void pilha_pessoa_destruir(Pilha *p){
    free(p-> elementos);

    p->elementos = NULL;
    p->topo = p->tamanho = PILHA_NAO_ALOCADA;
}
/*-- FIM OPERACAOES DE PILHA--*/

main () {
    const TAM = 2;
    int pos;
    Pessoa p;
    Pilha pessoas;
    char opcao;

    pilha_pessoa_ler(&pessoas, TAM, TAM);

    pilha_pessoa_exibir(pessoas);

    printf("\nTamanho da Pilha = %d\n", pilha_pessoa_numero_elementos(pessoas));

    printf("\nForneca o nome de uma pessoa para ser buscado na pilha: ");
    scanf("\n", &p.nome);
    gets(p.nome);

    pos = pilha_pessoa_posicao_elemento(p, pessoas);

    p = pilha_pessoa_obter_elemento(pos, pessoas);

    printf("\nA pessoa procurada esta na posicao %d da pilha.", pos);
    printf("\nMais detalhes da pessoa: \n");
    exibir_pessoa(p);

    printf("\nDeseja excluir da pilha ? [s - sim ou qualquer outra tecla para n]: ");
    scanf("\n%c", &opcao);
    
    if(opcao == 's' || opcao == 'S') {
        pilha_pessoa_remover(&pessoas);
        pilha_pessoa_exibir(pessoas);
    }

    pilha_pessoa_destruir(&pessoas);
}
