/*A biblioteca math.h oferece algumas funções matemáticas.
    Supondo a inexistência desta biblioteca, implemente uma função para calcular:
    a) o piso de um número real, tal como a função floor;
    b) o teto de um número real, tal como a função ceil;
Em seguida, chame estes módulos a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>

float floor(float n) {
    int i = 0;
    if(n>=0) {
        while(i<n) {
            i++;
        }

        return i-1;
    }
    else {
        while(i>n) {
            i--;
        }
        return i;
    }
}

float ceil(float n) {
    int i = 0;

    if(n>=0) {
        while(i<n) {
            i++;
        }
        return i;
    }
    else {
        while(i>n) {
            i--;
        }
        return i+1;
    }
}

main() {
    float x;
    printf("Forneca um número para ter seu valor piso: ");
    scanf("%f", &x);

    printf("O piso de %.2f e %.2f", x, floor(x));

    printf("\nO teto de %.2f e %.2f", x, ceil(x));
}
