#include <stdio.h>
#include <stdlib.h>

typedef struct TNumeroRacional {
    int n;
    int d;
} NumeroRacional;

NumeroRacional soma(NumeroRacional n1, NumeroRacional n2) {
    NumeroRacional resposta;
    resposta.n = (n1.n * n2.d) + (n2.n * n1.d);
    resposta.d = n1.d * n2.d;
    printf("%f %f", resposta.d, resposta.n);

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

}
