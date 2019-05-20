#include <stdio.h>
#include <stdlib.h>

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
