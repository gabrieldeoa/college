#include <stdio.h>

void somaIntervalo(int *inicio, int *fim) {

    int somatorioPar = 0;
    int somatorioImpar = 0;

    for(int i = *inicio; i <= *fim; i++) {
        if(i % 2 == 0)
            somatorioPar += i;
        else
            somatorioImpar += i;
    }

    *inicio = somatorioImpar;
    *fim = somatorioPar;
}

int main() {
    int i = 8 , f = 5;
        if(i < f) {
            somaIntervalo(&i, &f);

            printf("soma impar = %d", i);
            printf("\nsoma par = %d", f);
        }
        else {
            somaIntervalo(&f, &i);

            printf("soma impar = %d", f);
            printf("\nsoma par = %d", i);
        }




}
