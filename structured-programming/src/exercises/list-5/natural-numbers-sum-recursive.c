#include <stdio.h>
#include <stdlib.h>

int somaNaturaisRec(int n) {
    return (n == 0)
        ? 0
        : (n + somaNaturaisRec(n-1));
}

int main() {
    int num;

    printf("Forneca um numero: ");
    scanf("%d", &num);

    printf("a soma dos numeros naturais ate %d e %d\n\n", num, somaNaturaisRec(num));

    system("pause");
}
