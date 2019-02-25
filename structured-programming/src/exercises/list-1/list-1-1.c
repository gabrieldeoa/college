/*
Você deve escrever um módulo para receber um único parâmetro do tipo texto e escrevê-lo de volta à tela do computador.
Atenção: este módulo não retorna resultado;
apenas executa o processamento referente à escrita de um texto na saída do computador.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>

void printarTexto(char* txt);

main() {
    char* texto;
    texto = (char*)malloc(sizeof(char));

    printf("Forneça algum texto: ");
    gets(texto);

    printf("Você escreveu o seguinte: ");
    printarTexto(texto);
    free(texto);
}

void printarTexto(char* txt) {
    printf("%s", txt);
}

