/*A biblioteca math.h oferece algumas funções matemáticas.
    Supondo a inexistência desta biblioteca, implemente uma função para calcular:
    a) o piso de um número real, tal como a função floor;
    b) o teto de um número real, tal como a função ceil;
Em seguida, chame estes módulos a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
float piso(float x) {
    float res = 0;

    if(x >= 0) {
        while(res <= x) {
            res = res + 1;
        }

        return res - 1;
    }
    else {
        while(res > x) {
            res = res - 1;
        }
        return res;
    }
}

float teto(float x) {
    float res = 0;

    if(x >= 0) {
        while(res < x) {
            res = res + 1 ;
        }
        return res;
    }
    else {
        while(res > x) {
            res = res - 1;
        }
        return res + 1;
    }
}

main() {
    float x;
    printf("Forneca um numero para ter seu valor piso: ");
    scanf("%f", &x);

    printf("O piso de %.2f e %.2f", x, piso(x));

    printf("\nO teto de %.2f e %.2f", x, teto(x));
}
