/*A biblioteca math.h oferece algumas funções matemáticas.
    Supondo a inexistência desta biblioteca, implemente uma função para calcular:
    a) o piso de um número real, tal como a função floor;
    b) o teto de um número real, tal como a função ceil;
Em seguida, chame estes módulos a partir de um módulo main para testar seu programa.

===> RECURSIVO <===
*/

#include <stdio.h>

float pisoRecAux(float x, float r) {
    if(x >= 0) {
        if(r < x) return pisoRecAux(x, r+1);
        else return r-1;
    } else {
        if( r > x) return pisoRecAux(x, r-1);
        else return r;
    }
}

float pisoRec(float x) {
   return pisoRecAux(x, 0);
}

float tetoRecAux(float x, float res) {
    if(x >= 0) {
        if(res < x) return tetoRecAux(x, res+1);
        else return res;
    }
    else {
        if(res > x) return tetoRecAux(x, res-1);
        else return res+1;
    }
}

float tetoRec(float x) {
    return tetoRecAux(x, 0);
}

main() {
    float x;
    printf("Forneca um numero: ");
    scanf("%f", &x);

    printf("O piso de %.2f e %.2f", x, pisoRec(x));

    printf("\nO teto de %.2f e %.2f", x, tetoRec(x));
}
