/*
Programe uma função para receber em seus parâmetros dois números inteiros.
Sua função deve indicar se o primeiro parâmetro é divisível pelo segundo.
Em seguida, chame esta função a partir de um módulo main para testar seu programa.
Neste programa, informe se um número fornecido pelo usuário é par ou ímpar.
*/

#include <stdio.h>

int divisivel(int x, int y) {
    return ( x % y == 0);
}

main() {
    int x;
    
    printf("Forneca o primeiro numero:  ");
    scanf("%d", &x);

    printf("\no numero %d e %s", x, divisivel(x, 2) ? "par" :  "impar");
}
