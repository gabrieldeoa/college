/*
A sequência infinita 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55... é conhecida como a sequência de Fibonacci.
Nela, os dois primeiros números são 0 e 1. Os demais números são obtidos pala soma dos dois números imediatamente anteriores.
Implemente uma função retornar o n-ésimo termo da sequência de Fibonacci.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
===> RECURSIVO <===
*/

#include <stdio.h>

int fibonacciRec(int n) {
    if(n == 1) return 0;
    else if(n == 2) return 1;
    else return fibonacciRec(n-1) + fibonacciRec(n-2);
}

main() {
    int n, r;

    while(1) {
        system("cls");

        printf("\nForneca o numero da posicao para saber o elemento que a consta: ");
        scanf("%d", &n);

        printf("\nNa posicao %d esta o elemento %d.", n, fibonacciRec(n));

        printf("\n\nDeseja Continuar [1 para sim e 2 para nao] ? ");
        scanf("%d", &r);

        if(r != 1 ) break;
    }
}
