/*
Implemente uma função para calcular a potência entre dois números inteiros quaisquer.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
Teste as potências de 2^3, 2^-3, -3^2 e -3^-2.
*/

#include <stdio.h>
#include <stdlib.h>

float absoluto(float n) {
    return (n < 0)
        ? -1 * n
        : n;
}

float potencia(int base, int expoente) {
    float resposta = 1;

    for(int i = 0; absoluto(e) > i; i++) {
        resposta = base * resposta;
    }

    if(e == 0)
        return 1;

    else if(e > 0)
        return resposta;
    else
        return 1/resposta;

}

main() {
    int r, b, e;

    while(1) {
        system("clear");
        printf("\nForneca a base da potencia: ");
        scanf("%d", &b);

        printf("\nForneca o expoente da potencia: ");
        scanf("%d", &e);

        printf("\nresultado: %.2f", potencia(b, e));

        printf("\n\nDeseja continuar[ 1 - sim ou 2 - não]: ");
        scanf("%d", &r);

        if(r != 1) {
            break;
        }
    }

}
