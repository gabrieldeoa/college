/*
* Faça um algoritmo que some os elementos anteriores até ele mesmo.
*/
#include <stdio.h>

//O(n) pois a complexidade dempederá da entrada, o for irá percorrer somando até o número de entrada
int somatorioOdeN(int n) {
    int somatorio = 0, i = 0;

    for(i; i <= n; i++)
        somatorio += i;

    return somatorio;
}

// O(1) pois é realiza operações baseadas em constantes e também contém um única linha
int somatorioOdeUm(int n) {
    return (n * (n+1)) / 2;
}

// recursivo O(n)
int somatorioRecursivo(int n) {
     return (n == 1) ? 1 : n + somatorioRecursivo(n-1);
}

main() {
    const NUM = 132;

    printf("O(n) = %d", somatorioOdeN(NUM));
    printf("\n\nO(1) = %d", somatorioOdeUm(NUM));
    printf("\n\n RECURSIVO O(n) = %d", somatorioRecursivo(NUM));
}
