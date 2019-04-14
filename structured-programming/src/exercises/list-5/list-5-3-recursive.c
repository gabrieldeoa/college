/*
Um número primo é um inteiro positivo que possui apenas dois divisores também positivos diferentes.
Escreva uma função para retornar verdadeiro ou falso para o fato de um número ser primo.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
===> RECURSIVO <===
*/

#include <stdio.h>

int qtdDivisoresRec(int num, int aux) {
    // valor de parada
    if(aux == 0)
        return 0;
    // quando for divisivel, soma 1 e decrementa
    else if(num % aux == 0)
        return 1 + qtdDivisoresRec(num, aux - 1);
    // quando nao for so decrementa
    else
        return qtdDivisoresRec(num, aux - 1);
}

int primo(int x) {
    return (qtdDivisoresRec(x, x) == 2);
}

main() {
    int n, r;

    while(1) {
        system("cls");// linux usa clear

        printf("\nForneca um numero para checar se ele e primo: ");
        scanf("%d", &n);

        printf("\nO numero %d %s primo", n, primo(n) ? "e" : "nao e");

        printf("\n\nDeseja Continuar [1 para sim e 2 para nao] ? ");
        scanf("%d", &r);

        if(r != 1 ) break;
    }
}
