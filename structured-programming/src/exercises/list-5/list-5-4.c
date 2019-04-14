/*
Implemente uma função para calcular o fatorial de um número. 
O fatorial de 0 é 1, por definição. 
Para qualquer outro número inteiro positivo n, o seu fatorial é dado por n x (n-1) x (n-2) x ... x 3 x 2 x 1. 
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>

int fatorial(int n) {
    int fatorial = 1;

    if(n == 0) return fatorial;

    for(int i=1; i <= n; i++){
        fatorial = fatorial * i;
    }

    return fatorial;
}

main() {
    int n, r;

    while(1) {
        system("clear");

        printf("\nForneça um número para calcular seu fatorial: ");
        scanf("%d", &n);

        printf("\nO Fatorial de %d é %d.", n, fatorial(n));

        printf("\n\nDeseja Continuar [1 para sim e 2 para não] ? ");
        scanf("%d", &r);
    
        if(r != 1 ) break;
    }
}
