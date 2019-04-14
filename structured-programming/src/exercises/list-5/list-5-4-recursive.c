/*
Implemente uma função para calcular o fatorial de um número.
O fatorial de 0 é 1, por definição.
Para qualquer outro número inteiro positivo n, o seu fatorial é dado por n x (n-1) x (n-2) x ... x 3 x 2 x 1.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
===> RECURSIVO <===
*/

#include <stdio.h>

int fatorialRec(int n) {
    //valor de parada
    if(n == 0)
        return 1; // Elementro neutro multiplicacao
    //caso nao, multiplique N e decremente
    else
        return n * fatorialRec(n-1);
}

main() {
    int n, r;

    while(1) {
        system("cls"); // no linux use "clear"

        printf("\nForneca um numero para calcular seu fatorial: ");
        scanf("%d", &n);

        printf("\nO Fatorial de %d e %d.", n, fatorialRec(n));

        printf("\n\nDeseja Continuar [1 para sim e 2 para nao] ? ");
        scanf("%d", &r);

        if(r != 1 ) break;
    }
}
