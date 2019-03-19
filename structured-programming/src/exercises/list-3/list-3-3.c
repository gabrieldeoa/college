/*
Programe uma função para receber em seus parâmetros dois números inteiros.
Sua função deve indicar se o primeiro parâmetro é divisível pelo segundo.
Em seguida, chame esta função a partir de um módulo main para testar seu programa.
Neste programa, informe se um número fornecido pelo usuário é par ou ímpar.
*/

#include <stdio.h>

int divisivel(int x, int y) {
    int divisivel = 0;

    if( x % y == 0) {
        divisivel = 1;
    }
    return divisivel;
}


main() {
    int x;

    printf("Forneca o primeiro numero:  ");
    scanf("%d", &x);

    if(divisivel(x, 2)) {
        printf("O número %d e par", x);
    } else {
        printf("O número %d e impar", x);
    }
}
