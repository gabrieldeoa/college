#include "definitions.h"

int strLen (char * t1) {
    int i;

    for(i = 0; t1[i] != '\0'; i++);

    return i;
}

int vitoria(char * p) {
    int i;
    for(i = 0; p[i] != '\0'; i++) {
        if(p[i] == '#') return 0;
    }
    return 1;
}

void strCpy(char * t1, char * t2 ) {
    int i;

    for(i = 0; t2[i] != '\0'; i++) {
        t1[i] = t2[i];
    }
}

void atualizarLetrasUtilizadas(char * t1, char l) {
    int final = strLen(t1);
    t1[final] = l;
}

int totalDeRegistrosArquivoTxt(FILE **arquivo) {
    int contador = 1;
    char palavra[80];

    while(1) {
        fgets(palavra, 80, *arquivo);
        if(feof(*arquivo)) break;
        contador++;
    }

    return contador;
}

void sortearPalavraParaJogo(JogoDaForca *jg, FILE **arquivo) {
    int total = 0, aleatorio, contador = 1;
    char sorteada[80];

    total= totalDeRegistrosArquivoTxt(arquivo);

    srand(time(NULL));
    aleatorio = rand() % (total+1);

    rewind(*arquivo);

    while(1) {
        fgets(sorteada, 80, *arquivo);
        if(feof(*arquivo) || contador == aleatorio) break;
        contador++;
    }
    strCpy(jg->forca.palavraSecreta, sorteada) ;
}

void preparandoForca(JogoDaForca *jg) {
    int i;
    for(i = 0; jg->forca.palavraSecreta[i] != '\0' ; i++) {
        if(jg->forca.palavraSecreta[i] != '\n')
            jg->forca.palavra[i] = '#';
    }
}

int contemLetra(char * palavra, char letra) {
    int i, resultado = 0;
    for (i = 0; palavra[i] != '\0'; i++) {
        if(palavra[i] == letra) {
            resultado = 1;
        }
    }
    return resultado;
}

void jogada(JogoDaForca *jg, char letra) {
    int i;

    //Atualizando letras utilizadas
    if(contemLetra(jg->forca.letrasUsadas, letra) == 0) {
        atualizarLetrasUtilizadas(jg->forca.letrasUsadas, letra);
    }

    //Verifica se a letra existe na palavra da forca
    if(contemLetra(jg->forca.palavraSecreta, letra)) {
        for (i = 0; jg->forca.palavraSecreta[i] != '\0'; i++) {
            if(jg->forca.palavraSecreta[i] == letra) {
                jg->forca.palavra[i] = letra;
            }
        }
    } else {
        jg->forca.vidas = jg->forca.vidas -1;
    }

}

void inicializarJogo(JogoDaForca *jg) {
    jg->forca.vidas = VIDAS;
    preparandoForca(jg);
}

void iniciarJogo(JogoDaForca *jg) {
    int venceu;
    char letra;
    while(1) {
        system("clear");

        venceu = vitoria(jg->forca.palavra);
        printarJogo(jg);

        if(jg->forca.vidas == 0 || venceu) break;

        printf("\nForneca a letra: ");
        scanf("\n%c", &letra);
        jogada(jg, letra);
    }

    printf("\n\nVoce %s !", (venceu) ? "Venceu" : "Perdeu");

    jg->resultado = !venceu;
}

void printarJogo(JogoDaForca *jg) {
    printf("\nFORCA: %s", jg->forca.palavra);
    printf("\nVIDAS: %d\t LETRAS USADAS: %s", jg->forca.vidas, jg->forca.letrasUsadas);
}

void salvarArquivoDeResultadoBinario(JogoDaForca jg, FILE **arquivo) {
    fwrite(&jg, sizeof(JogoDaForca), 1, *arquivo);
}

void exibirResultados(FILE *arquivo) {
    rewind(arquivo);
    JogoDaForca jogo;

    while(1) {
        fread(&jogo, sizeof(JogoDaForca), 1, arquivo);
        if(feof(arquivo)) break;
        printf(
            "\nJogador: %s\npalavra: %s \nletras utilizadas: %s\nvidas: %d, resultado: %d\n\n",
            jogo.jogador,
            jogo.forca.palavraSecreta,
            jogo.forca.letrasUsadas,
            jogo.forca.vidas,
            jogo.resultado
        );
    }
}

main() {
    FILE * arquivoPalavras, *arquivoResultados;

    JogoDaForca jg;
    jg.jogador = (char *)malloc(sizeof(char));
    jg.forca.palavra = (char *)malloc(sizeof(char));
    jg.forca.palavraSecreta = (char *)malloc(sizeof(char));
    jg.forca.letrasUsadas = (char *)malloc(sizeof(char));

    printf("Nome do Jogador: ");
    gets(jg.jogador);

    arquivoPalavras = fopen(DIR_WORDS, "r");

    sortearPalavraParaJogo(&jg, &arquivoPalavras);
    inicializarJogo(&jg);
    iniciarJogo(&jg);

    arquivoResultados = fopen(DIR_RESULT, "ab+");
    salvarArquivoDeResultadoBinario(jg, &arquivoResultados);

    exibirResultados(arquivoResultados);

    fclose(arquivoPalavras);
    fclose(arquivoResultados);
    free(jg.jogador);
    free(jg.forca.palavra);
    free(jg.forca.palavraSecreta);
    free(jg.forca.letrasUsadas);
}
