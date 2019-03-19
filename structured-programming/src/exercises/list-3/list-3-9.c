/*
Programe um módulo para receber um valor inteiro entre 1 e 12 e retornar o nome do mês equivalente.
Se o parâmetro não for um inteiro válido para um mês do ano, o retorno da função deve ser um texto vazio.
Em seguida, chame a função criada a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>

char* mesDoAno(int valor) {

    switch (valor) {
        case 1:
           return "janeiro";
            break;
        case 2:
           return "fevereiro";
            break;
        case 3:
           return "marco";
            break;
        case 4:
           return "abril";
            break;
        case 5:
           return "maio";
            break;
        case 6:
           return "junho";
            break;
        case 7:
           return "julho";
            break;
        case 8:
           return "agosto";
            break;
        case 9:
           return "setembro";
            break;
        case 10:
           return "outubro";
            break;
        case 11:
           return "novembro";
            break;
        case 12:
           return "dezembro";
            break;
        default:
           return " ";
            break;
    }
}

main() {
    int v;
    printf("Forneca o numero para obter o nome do mes: ");
    scanf("%i", &v);
    printf("\nO valor %d equivale ao mes de %s", v, mesDoAno(v));
}
