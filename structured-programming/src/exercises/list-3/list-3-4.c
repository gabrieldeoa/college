/*
Primeiramente, programe uma função para receber dois números e retornar o maior entre eles.
Posteriormente, programe outra função para receber três números e retornar o maior entre eles.
Tente escrever esta segunda função fazendo com que ela tenha uma única linha de código.
Fique à vontade para chamar a primeira função para implementar a segunda.
Em seguida, chame as funções criadas a partir de um módulo main para testar seu programa.
*/
#include <stdio.h>

int maiorEntreDois(int x, int y) {
    if(x > y) {
        return x;
    }

    return y;
}

int maiorEntreTres(int x, int y, int z) {
    return maiorEntreDois(maiorEntreDois(x, y), z);
}

main() {
    int x, y, z;

    printf("Forneca o primeiro numero:  ");
    scanf("%d", &x);

    printf("Forneca o segundo numero:  ");
    scanf("%d", &y);

    printf("Forneca o terceiro numero:  ");
    scanf("%d", &z);

    printf("O maior entre %d, %d, %d e %d .", x, y, z, maiorEntreTres(x, y, z));


}
