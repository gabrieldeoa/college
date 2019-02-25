#include <stdlib.h>
#include <stdio.h>

void divisao(int *dvd, int *dvr) {
    int quociente, resto;
    quociente = *dvd / *dvr;
    resto = *dvd % *dvr;
    *dvd = quociente;
    *dvr = resto;
}

main() {
    int dividendo, divisor;

    printf("Forneca o dividendo: ");
    scanf("%d", &dividendo);

    printf("Forneca o divisor: ");
    scanf("%d", &divisor);

    divisao(&dividendo, &divisor);

    printf("O Quociente e %d e o resto e %d", dividendo, divisor);
}