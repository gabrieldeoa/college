#include <stdio.h>
#include <stdlib.h>

typedef struct TNumeroRacional {
    float n;
    float d;
} NumeroRacional;

NumeroRacional soma(NumeroRacional n1, NumeroRacional n2) {
    NumeroRacional resposta;
    resposta.n = (n1.n * n2.d) + (n2.n * n1.d);
    resposta.d = n1.d * n2.d;

    return resposta;
}

NumeroRacional subtracao(NumeroRacional n1, NumeroRacional n2) {
    NumeroRacional resposta;
    resposta.n = (n1.n * n2.d) - (n2.n * n1.d);
    resposta.d = n1.d * n2.d;
    
    return resposta;
}

NumeroRacional multiplicacao(NumeroRacional n1, NumeroRacional n2) {
    NumeroRacional resposta;
    resposta.n = n1.n * n2.n;
    resposta.d = n1.d * n2.d;

    return resposta;
}

NumeroRacional divisao(NumeroRacional n1, NumeroRacional n2) {

    NumeroRacional resposta;
    resposta.n = n1.n * n2.d;
    resposta.d = n1.d * n2.n;

    return resposta;
}

main () {
    NumeroRacional n1, n2, res;

    printf("o numerador de x: ");
    scanf("%f", &n1.n);

    printf("o denominador de x: ");
    scanf("%f", &n1.d);

    printf("o numerador de y: ");
    scanf("%f", &n2.n);

    printf("o denominador de y: ");
    scanf("%f", &n2.d);

    res = soma(n1, n2);
    printf("\n%.2f/%.2f + %.2f/%.2f = %.2f/%.2f", n1.n, n1.d, n2.n, n2.d, res.n, res.d);

    res = subtracao(n1, n2);
    printf("\n%.2f/%.2f - %.2f/%.2f = %.2f/%.2f", n1.n, n1.d, n2.n, n2.d, res.n, res.d);

    res = multiplicacao(n1, n2);
    printf("\n%.2f/%.2f x %.2f/%.2f = %.2f/%.2f", n1.n, n1.d, n2.n, n2.d, res.n, res.d);

    res = divisao(n1, n2);
    printf("\n%.2f/%.2f / %.2f/%.2f = %.2f/%.2f", n1.n, n1.d, n2.n, n2.d, res.n, res.d);

}
