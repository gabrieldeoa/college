#include <stdio.h>

int triangulo(int x, int y, int z) {

    return (x < y+z &&  y < x+z  && z < x+y );
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
