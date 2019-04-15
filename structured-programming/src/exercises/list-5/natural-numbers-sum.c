#include <stdio.h>
#include <stdlib.h>

int somaNaturais(int n) {
    int soma = 0;
    for(int i = 1; i <= n; i++)
        soma += i;

    return soma;
}

int main() {
    int num;

    printf("Forneca um numero: ");
    scanf("%d", &num);

    printf("a soma dos numeros naturais ate %d e %d\n\n", num, somaNaturais(num));

    system("pause");
}
