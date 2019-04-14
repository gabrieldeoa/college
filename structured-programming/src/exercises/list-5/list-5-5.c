/*
A sequência infinita 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55... é conhecida como a sequência de Fibonacci.
Nela, os dois primeiros números são 0 e 1. Os demais números são obtidos pala soma dos dois números imediatamente anteriores.
Implemente uma função retornar o n-ésimo termo da sequência de Fibonacci.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>

int fibonacci(int n) {
    int fibonacci = 0, x = 0, y = 1;

    if( n == 0 || n == 1) return x;
    if( n == 2) return y;

    for(int i = 2; i < n; i++) {
        fibonacci = x + y;
        x = y;
        y = fibonacci;
    }

    return fibonacci;
}

main() {
    int n, r;

    while(1) {
        system("clear");

        printf("\nForneça o numero da posição para saber o elemento que a consta: ");
        scanf("%d", &n);

        printf("\nNa posição %d esta o elemento %d.", n, fibonacci(n));

        printf("\n\nDeseja Continuar [1 para sim e 2 para não] ? ");
        scanf("%d", &r);

        if(r != 1 ) break;
    }
}
