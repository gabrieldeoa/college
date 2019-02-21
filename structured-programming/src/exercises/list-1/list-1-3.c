/*
Escreva um módulo para receber o primeiro nome de uma pessoa em seu primeiro parâmetro.
Este módulo possui ainda um segundo parâmetro que deve receber o sobrenome desta mesma pessoa.
Como resultado de seu processamento, este módulo deve imprimir um texto no seguinte formato:
sobrenome, seguido de uma vírgula, seguido do nome.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
Escreva um comentário logo no início do arquivo abordando o seu nome e a data de quando o programa foi criado.
*/

/*
Autor: Gabriel de O. Araujo
Data: 12/02/2019
*/

#include <stdio.h>
#include <stdlib.h>

void inverterNome(char* nome, char* sobrenome) {
    printf("%s, %s", sobrenome, nome);
}

main() {
    char* nome;
    char* sobrenome;

    // Alocando memória
    nome = (char*)malloc(sizeof(char));
    sobrenome = (char*)malloc(sizeof(char));

    printf("Forneça o Nome: ");
    gets(nome);

    printf("Forneça o Sobrenome: ");
    gets(sobrenome);


    inverterNome(nome, sobrenome);

    // Liberando memória
    free(nome);
    free(sobrenome);
    return 0;
}
