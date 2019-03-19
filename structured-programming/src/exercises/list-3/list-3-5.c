/*
Para que três valores constituam os lados de um triângulo, é necessário que qualquer um dos lados seja inferior
que a soma dos lados restantes.
Programe um módulo para verificar se três valores são capazes de formar os lados de um triângulo.
Dando continuidade, programe outra função. Esta segunda função deve receber três valores,
e informar se tais medidas representam um triângulo equilátero (quando os três lados são iguais),
um triângulo isósceles (quanto dois dos três lados são iguais), um triângulo escaleno (quando os três lados são diferentes), ou se não constituem um triângulo. Esta segunda função pode retornar um inteiro entre 0 e 3, de acordo com a tabela abaixo:

Retorno Tipo de triângulo
0 Não é triângulo
1 Escaleno
2 Isósceles
3 Equilátero

Em seguida, a partir de um módulo main, peça para o usuário fornecer três valores e faça seu programa responder
a ele se ele forneceu valores incapazes de formar um triângulo, ou que tipo de triângulo é formado com os valores de entrada. 
*/
#include <stdio.h>

int triangulo(int x, int y, int z) {

    return (x >= y+z ||  y >= x+z  || z >= x+y ) ? 0 : 1;
}

int tipoTriangulo(int x, int y, int z) {

    if(!triangulo(x, y, z)) {
        return 0;
    }

    if(x == y && y == z) {
        return 3;
    }

    else if(x == y || x == z || y == z) {
        return 2;
    }
    else {
        return 1;
    }
}

main() {
    int x, y, z;

    printf("Forneca o primeiro lado:  ");
    scanf("%d", &x);

    printf("Forneca o segundo lado:  ");
    scanf("%d", &y);

    printf("Forneca o terceiro lado:  ");
    scanf("%d", &z);

    printf("O triangulo e :");

    switch (tipoTriangulo(x,y,z)) {
        case 1:
            printf(" Escaleno");
            break;
        case 2:
            printf(" Isosceles");
            break;
        case 3:
            printf(" Equilatero");
            break;
        default:
            printf("Nao e triangulo");
            break;
    }


}
