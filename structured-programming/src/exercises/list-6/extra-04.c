/*
*/

#include <stdio.h>
#include <stdlib.h>

void requisitarRespostas(char *r, int col) {
    int i;
    for(i = 0; i < col; i++) {
        printf("\nForneca a respostas da questão %d: ", i);
        scanf("\n");
        r[i] = getchar();
    }
    printf("\n");
}

void escreverRespostas(char *v, int col) {
    int i;
    for(i = 0; i < col; i++) {
        printf("[%c]", v[i]);
    }
    printf("\n");
}

void inicializarFrequencia(int *fq, int col) {
    int i;
    for(i = 0; i < col; i++) {
        fq[i] = 0;
    }
    printf("\n");
}

void corrigirProva(char *g, char *r, int *fq, int *ap, int *nota, int col ) {
   int i;
   *nota = 0;

    for(i = 0; i < col; i++) {
        if(g[i] == r[i]) {
            *nota++;
        }
    }

    //atualizando aprovado
    if(*nota >= 6) *ap++;
    
    //atualizando frequencia
    fq[*nota]++;
}

int maiorFrequencia(int *fq, int col) {
    int i = 0, maior = 0;

    for(i = 0; i < col; i++) {
        if(fq[i] > maior)
            maior = fq[i];
    }
    return maior;
}

void escreverMaiorFrequencia(int *fq, int col, int maior) {
    int i = 0;

    for(i = 0; i < col; i++) {
        if(fq[i] == maior)
            printf("%d", i);
    }
    return maior;
}

float percentualAprovacao(int *fq, int col, int aprovados, int total) {
    return (aprovados * 100)/total;
}


main() {
    int const tam = 10;

    char *gabarito = (char *)malloc(sizeof(char[tam]));
    char *respostas = (char *)malloc(sizeof(int[tam]));
    int *frequencia = (int *)malloc(sizeof(int[tam+1]));
    int numero = 1, aprovados = 0 , nota = 0, maior = 0, total = 0;
    float porcentagem = 0.0;

    requisitarRespostas(gabarito, tam);
    inicializarFrequencia(frequencia, tam+1);

    printf("Gabarito: \n");
    escreverRespostas(gabarito, tam);

    while(1) {
        printf("Forneca o número do aluno: ");
        scanf("%d", &numero);

        if(numero == 0) break; // ponto de parada
        
        // incrementando aluno
        total++;

        requisitarRespostas(respostas, tam);

        corrigirProva(gabarito, respostas, frequencia, &aprovados, &nota, tam);

        printf("\nO aluno %d tirou %d", numero, nota);
    }

    maior = maiorFrequencia(frequencia, tam+1);

    escreverMaiorFrequencia(frequencia, tam+1, maior);

    porcentagem = percentualAprovacao(frequencia, tam, aprovados, total);
    printf("A porcentagem de aprovacao e %f", porcentagem);

    free(gabarito);
    free(respostas);
    free(frequencia);
}



