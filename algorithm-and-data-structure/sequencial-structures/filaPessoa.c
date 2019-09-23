#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FILA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define FILA_CHEIA -4
#define FILA_VAZIA -5
#define SUCESSO -6

/*
    REPRESENTACAO

    typedef struct {
        <TIPO>*  <IDENTIFICADOR>
        int inicio, fim, tamanho;
    } <NOME>;

    EXEMPLO

    typedef struct {
        Pessoa*  elementos
        int inicio, fim, tamanho;
    } fila;
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
    Pessoa*  elementos;
    int inicio, fim, tamanho;
} Fila;
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


// CRIACAO DE FILA - dado a fila e o tamanho cria-se a fila por referencia.
void fila_pessoa_criar(Fila* f, int tam) {
    f->elementos = malloc(sizeof(Pessoa[tam]));
    f->inicio = f->fim = -1;
    f->tamanho = tam;
}

// CONTAGEM DE ELEMENTOS - dado uma fila retorna a qtd de elementos validos na mesma.
int fila_pessoa_numero_elementos(Fila f) {
    int intervalo = f.fim - f.inicio;

    if(f.inicio == -1 || f.fim == -1) return 0;

    if(f.inicio <= f.fim) return intervalo + 1;

    return intervalo + f.tamanho + 1;

}

// OBTER POSICAO DE UM ELEMENTO - dado uma elemento, a fila retorna o posicao do elemento.
int fila_pessoa_posicao_elemento(Pessoa elem, Fila f) {
    int i, j, num_elems;
    num_elems = fila_pessoa_numero_elementos(f);

    j = f.inicio;

    for(i = 0; i < num_elems; i++) {
        if(strcmp(f.elementos[j].nome, elem.nome) == 0)
            return j;

        if(j == f.tamanho - 1)
            j = 0;
        else
            j++;
    }

    return ELEMENTO_NAO_EXISTENTE;
}

// OBTER UM ELEMENTO NA FILA - dada a posicao e a FILA retorna o elemento(seu conteudo)
Pessoa fila_pessoa_obter_elemento( int pos , Fila f ) {
    return f.elementos[ pos ];
}

//INSERIR UM ELEMENTO NA FILA - dado o elemento e a fila insere um elemento e retorna flag de sucesso
int fila_pessoa_inserir(Pessoa elem, Fila* f) {
    int i, num_elems;
    num_elems = fila_pessoa_numero_elementos(*f);

    if(num_elems >= f->tamanho)
        return FILA_CHEIA;

    if(fila_pessoa_posicao_elemento(elem, *f) != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_NAO_EXISTENTE;

    if(f->fim == -1)// fila vazia
        f->inicio = f->fim = 0;
    else if (f->fim == f->tamanho - 1)
        f->fim = 0;
    else
        f->fim++;

    f->elementos[ f->fim ] = elem;

    return SUCESSO;
}

//REMOVER ELEMENTO - dada fila remover o elemento primeiro e retorna flag de sucesso
int fila_pessoa_remover(Fila* f) {
    int i, num_elems;
    num_elems = fila_pessoa_numero_elementos(*f);

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

// EXIBIR UMA FILA  - dado a fila printa-se seu conteudo
void fila_pessoa_exibir(Fila f) {
    int i, j, num_elems;
    num_elems = fila_pessoa_numero_elementos(f);

    j = f.inicio;

    for(i = 0; i < num_elems; i++) {
        printf("\nPessoa [%d]\n", i);
        exibir_pessoa(f.elementos[i]);

        if(j == f.tamanho - 1)
            j = 0;
        else
            j++;
    }
    printf("\n");
}

// LER UMA  FILA - dado um tamanho maximo da fila e a quantidade de elementos que espera-se ler retorna a fila preenchida
void fila_pessoa_ler( Fila* f , int tam , int qtd_elems ) {
    int i , elem;
    Pessoa elemento;

    fila_pessoa_criar (f , tam );

    for( i = 0; i < qtd_elems || i < tam ; i ++) {
        elemento = preencher_pessoa();
        fila_pessoa_inserir (elemento , f );
    }
}

// DESTRUIR UMA fila - dado a fila e seu tamanho a desaloca da memoria
void fila_pessoa_destruir (Fila * f ) {
    free(f -> elementos ) ;
    f-> elementos = NULL ;
    f-> inicio = f-> fim = f-> tamanho = FILA_NAO_ALOCADA ;
}

/*-- FIM OPERACAOES DE FILA--*/

main () {
    const TAM = 4;
    int pos;
    Pessoa p;
    Fila pessoas;
    char opcao;

    fila_pessoa_ler(&pessoas, TAM, TAM);

    fila_pessoa_exibir(pessoas);

    printf("\nTamanho da fila = %d\n", fila_pessoa_numero_elementos(pessoas));

    printf("\nForneca o nome de uma pessoa para ser buscado na fila: ");
    scanf("\n", &p.nome);
    gets(p.nome);

    pos = fila_pessoa_posicao_elemento(p, pessoas);

    p = fila_pessoa_obter_elemento(pos, pessoas);

    printf("\nA pessoa procurada esta na posicao %d da fila.", pos);
    printf("\nMais detalhes da pessoa: \n");
    exibir_pessoa(p);

    printf("\nDeseja excluir da Fila ? [s - sim ou qualquer outra tecla para n]: ");
    scanf("\n%c", &opcao);

    if(opcao == 's' || opcao == 'S') {
        fila_pessoa_remover(&pessoas);
        fila_pessoa_exibir(pessoas);
    }

    fila_pessoa_destruir(&pessoas);
}
