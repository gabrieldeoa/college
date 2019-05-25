/*
Representamos um número racional na forma , onde n é o numerador e d é o denominador.
Escreva uma definição para um tipo de dado capaz de representar um número racional.
*/

#include <stdio.h>

typedef struct TNumeroRacional {
    int n;
    int d;
} NumeroRacional;

main ()  {
    NumeroRacional numero;

    printf("Forneca o numerador: ");
    scanf("%d", &numero.n);

    printf("Forneca o denominador: ");
    scanf("%d", &numero.d);

    printf("O numero racional e %d/%d", numero.n, numero.d);
}
