/*
A biblioteca math.h oferece a função fabs.
Suponha que ela não exista e escreva um módulo para ter comportamento idêntico a esta função.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/
#include <stdio.h>

float fabs(float numero) {
    if(numero < 0 ) {
        return  numero * -1;
    }
    return numero;
}


main() {
    float numero;

    printf("Forneca um numero para obter seu valor absoluto: ");
    scanf("%f", &numero);

    printf("O valor absoluto de %.2f e %.2f", numero, fabs(numero));
}
