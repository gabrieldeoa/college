/*

*/

#include <stdio.h>

int oposto(int n) {
    int resultado = 0, i;

    if(n > 0) {
        for(i = 0; i < n; i++)
            resultado--;
    }

    if(n < 0){
        for(i = 0; i > n; i--)
            resultado++;
    }

    return resultado;
}

int valorAbsoluto(int n) {

    if(n >= 0) return n;

    else return oposto(n);

}

int subtracao(int n, int m) {
    int mOposto = oposto(m);

    return adicao(n, mOposto);
}

int adicao(int n, int m) {
   int resultado = n, i;

    if(m >= 0)
        for(i = 0; i < m; i++)
            resultado++;
    else
        for(i = 0; i > m; i--)
            resultado--;

    return resultado;

}

int multiplicacao(int n, int m) {
    int resultado = 0, i;

    if(m > 0)
        for(i = 0; i < m; i++)
            resultado = adicao(resultado, n);
    else
        for(i = 0; i < oposto(m); i++)
            resultado = adicao(resultado, oposto(n));


    return resultado;
}

int divisao(int n, int m) {
    int i = 0;
    int N = valorAbsoluto(n);
    int M = valorAbsoluto(m);

    while(subtracao(N, M) >= 0){
        i++;
        N = subtracao(N, M);
    }


    if(multiplicacao(n, m) < 0) return oposto(i);
    else return i;
}

int restoDivisao(int n, int m) {
    int aux = multiplicacao(divisao(n,m), m);

    return subtracao(n, aux);
}

main() {
    int x, y;

    printf("Forneça dois números:");
    printf("\nO primero: ");
    scanf("%d", &x);

    printf("\nO segundo: ");
    scanf("%d", &y);

    printf("\no oposto de %d é %d", x, oposto(x));
    printf("\no valor absoluto de %d é %d", x, valorAbsoluto(x));
    printf("\n%d + %d = %d", x, y, adicao(x, y));
    printf("\n%d - %d = %d", x, y, subtracao(x, y));
    printf("\n%d x %d = %d", x, y, multiplicacao(x, y));
    printf("\n%d / %d = %d", x, y, divisao(x, y));
    printf("\n%d %% %d = %d", x, y, restoDivisao(x, y));

}
