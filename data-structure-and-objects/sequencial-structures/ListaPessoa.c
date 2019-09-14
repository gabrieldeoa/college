#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LISTA_NAO_ALOCADA  -1
#define ELEMENTO_NAO_EXISTENTE  -2
#define ELEMENTO_EXISTENTE -3
#define LISTA_CHEIA -4
#define LISTA_VAZIA -5
#define SUCESSO -6

/* DEFINICAO TIPOS */
typedef enum TGenero {
    feminino  = 1,
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

typedef struct TPessoa {
    char nome[40];
    int idade;
    float altura;
    float peso;
    Genero genero;
    CorOlhos cor;

} Pessoa;
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
/*-- FIM FUNCOES AUXILIARES --*/

/* OPERACOES LISTA*/
Pessoa** lista_pessoa_criar(int tam) {
    Pessoa **lista;
    lista = calloc(tam, sizeof(Pessoa*[tam]));
    return lista;
}

int lista_pessoa_numero_elementos(Pessoa **lista, int tam) {
    int i;

    if(lista == NULL) return LISTA_NAO_ALOCADA;

    for(i = 0; i < tam; i++)
        if(lista[i] == NULL)
            return i;

    return tam;
}

int lista_pessoa_posicao_elemento(Pessoa elemento, Pessoa **lista, int tam) {
    int i, totalElementos;

    if(lista == NULL) return LISTA_NAO_ALOCADA;

    totalElementos = lista_pessoa_numero_elementos(lista, tam);

    for(i = 0; i < totalElementos; i++)
        if(strcmp(lista[i]->nome, elemento.nome) == 0)
            return i;

    return ELEMENTO_NAO_EXISTENTE;
}

Pessoa lista_pessoa_obter_elemento(int pos, Pessoa** lista) {
    return *(lista[pos]);
}

int lista_pessoa_inserir(Pessoa elemento, Pessoa **lista, int tam) {
    int i, totalElementos, posicaoElemento;

    totalElementos = lista_pessoa_numero_elementos(lista, tam);

    if(totalElementos >= tam ) return LISTA_CHEIA;

    posicaoElemento = lista_pessoa_posicao_elemento(elemento, lista, tam);

    if(posicaoElemento != ELEMENTO_NAO_EXISTENTE) return ELEMENTO_EXISTENTE;

    lista[totalElementos] = malloc(sizeof(Pessoa));

    *(lista[totalElementos]) = elemento;

    return SUCESSO;
}

int lista_pessoa_remover(Pessoa elemento, Pessoa** lista, int tam) {
    int i, posicao, totalElementos;

    totalElementos = lista_pessoa_numero_elementos(lista, tam);
    posicao = lista_pessoa_posicao_elemento(elemento, lista, tam);

    if(totalElementos <= 0) return LISTA_VAZIA;

    if(posicao == ELEMENTO_NAO_EXISTENTE) return ELEMENTO_NAO_EXISTENTE;

    free(lista[posicao]);

    for(i = posicao; i < totalElementos-1; i++)
        lista[i] = lista[i + 1];

    lista[i] = NULL;

    return SUCESSO;
}

void lista_pessoa_exibir(Pessoa **lista, int tam) {
    int i;

    printf("\n----- LISTANDO DADOS DE PESSOAS -----\n");

    for(i = 0; i < tam; i++) {
        if(lista[i] != NULL) {
            printf("\nPESSOA[%d]", i);
            exibir_pessoa(*(lista[i]));
        }
        else
            printf("N|");
    }
}

Pessoa** lista_pessoa_ler(int tam, int qtd_elems) {
    int i;
    Pessoa elemento, ** lista;

    lista = lista_pessoa_criar(tam);

    printf("\n----- CAPTURANDO DADOS DE PESSOAS -----\n");

    for(i = 0; i < qtd_elems || i < tam; i++) {
        printf("\nPESSOA[%d]", i);
        elemento = preencher_pessoa();

        lista_pessoa_inserir(elemento, lista, tam);
    }
    return lista;
}

void lista_pessoa_destruir(Pessoa** lista, int tam) {
    int i;

    for(i = 0; i < tam; i++) free(lista[i]);

    free(lista);
}
/*-- FIM OPERACOES LISTA --*/

int main() {
    const int TAM = 1;
    int pos;

    Pessoa **listaPessoa, p;

    listaPessoa = lista_pessoa_ler(TAM, TAM);

    lista_pessoa_exibir(listaPessoa, TAM);

    printf("\nTAMANHO DA LISTA = %d\n", lista_pessoa_numero_elementos(listaPessoa, TAM));

    printf("\nFORNECA O NOME DE UMA PESSOA PARA SER BUSCADO NA LISTA: ");
    scanf("\n", &p.nome);
    gets(p.nome);

    pos = lista_pessoa_posicao_elemento(p, listaPessoa, TAM);
    p = lista_pessoa_obter_elemento(pos, listaPessoa);

    printf("\nA PESSOA PROCURADA ESTA NA POSICAO %d DA LISTA.", pos);
    printf("\nMAIS DETALHES DA PESSOA: \n");
    exibir_pessoa(p);

    printf("\nFORNECA O NOME DE UMA PESSOA PARA SER EXCLUIDO DA LISTA: ");
    scanf("\n", &p.nome);
    gets(p.nome);

    lista_pessoa_remover(p, listaPessoa, TAM);
    lista_pessoa_exibir(listaPessoa, TAM);

    lista_pessoa_destruir(listaPessoa, TAM);
}
