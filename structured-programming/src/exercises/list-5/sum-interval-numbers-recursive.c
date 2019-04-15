#include <stdio.h>

int somatorioImparRec(int inicio, int fim) {
    if(inicio > fim)
        return 0;
    else if(inicio % 2 != 0)
        return inicio + somatorioImparRec(inicio+1, fim);
    else
        return somatorioImparRec(inicio+1, fim);
}

int somatorioParRec(int inicio, int fim) {
    if(inicio > fim)
        return 0;
    else if(inicio % 2 == 0)
        return inicio + somatorioParRec(inicio+1, fim);
    else
        return somatorioParRec(inicio+1, fim);
}


void somaIntervaloRec(int *inicio, int *fim) {

    int somatorioPar = somatorioParRec(*inicio, *fim);
    int somatorioImpar = somatorioImparRec(*inicio, *fim);

    *inicio = somatorioImpar;
    *fim = somatorioPar;
}

int main() {
    int i, f;
    printf("Digite o valor inicial do intervalo: ");
    scanf("%d", &i);

    printf("\nDigite o valor final do intervalo: ");
    scanf("%d", &f);

    if(i < f) {
        somaIntervaloRec(&i, &f);

        printf("soma impar = %d", i);
        printf("\nsoma par = %d", f);
    }
    else {
        somaIntervaloRec(&f, &i);

        printf("soma impar = %d", f);
        printf("\nsoma par = %d", i);
    }
}
