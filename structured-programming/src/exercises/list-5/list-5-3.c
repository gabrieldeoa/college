/*
Um número primo é um inteiro positivo que possui apenas dois divisores também positivos diferentes.
Escreva uma função para retornar verdadeiro ou falso para o fato de um número ser primo.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>

int primo(int n) {
    if(n == 0 || n == 1) return 0;

    for(int i=2; i < n; i++){
        if(n % i == 0){
            return 0;
        }
    }

    return 1;
}

main() {
    int n, r;

    while(1) {
        system("clear");

        printf("\nForneça um número para checar se ele é primo: ");
        scanf("%d", &n);

        printf("\nO número %d %s primo.", n, primo(n) ? "é" : "não é");

        printf("\n\nDeseja Continuar [1 para sim e 2 para não] ? ");
        scanf("%d", &r);

        if(r != 1 ) break;
    }
}
