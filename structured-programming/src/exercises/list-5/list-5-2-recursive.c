/*
Implemente uma função para calcular a potência entre dois números inteiros quaisquer.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
Teste as potências de 2^3, 2^-3, -3^2 e -3^-2.
===> RECURSIVO <===
*/

#include <stdio.h>
float potenciaRec( int b, int e) {
    if(e == 0) return 1;
    else if(e > 0) return b * potenciaRec(b, e-1);
    else return potenciaRec(b, e+1)/b;
}

main() {
    printf("\n%f elevado a %f = %f", 2.0, 3.0, potenciaRec(2, 3));
    printf("\n%f elevado a %f = %f", 2.0, -3.0, potenciaRec(2, -3));
    printf("\n%f elevado a %f = %f", -3.0, 2.0, potenciaRec(-3, 2));
    printf("\n%f elevado a %f = %f", -3.0, -2.0, potenciaRec(-3, -2));
}
