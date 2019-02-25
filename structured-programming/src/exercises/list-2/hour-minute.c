#include <stdio.h>
#include <stdlib.h>

int horaAtual(int *min) {
    int hora = *min/60;
    *min = *min%60;
    return hora;
}

main() {
    int hora, minutos;
    printf("minutos passados desde a meia noite: ");
    scanf("%d", &minutos);

    hora = horaAtual(&minutos);

    printf("Hora atual %d:%d \n", hora, minutos);
}