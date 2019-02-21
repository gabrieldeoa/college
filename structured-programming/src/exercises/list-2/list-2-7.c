/*
Seja X a seguinte sentença: “elefantes são mais pesados que gafanhotos”. Desenvolva a expressão:
    !(!X && X) && (!X || X)
*/

/*
 A afirmação acima é verdadeira logo:
    !(!X && X) && (!X || X)
    !(!1 && 1) && (!1 || 1)
     !(0 && 1) && (0 || 1)
        !0 && 1
        1 && 1
          1
*/

#include <stdlib.h>
#include <stdio.h>

int expressaoLogica(int x) {
    return !(!x && x) && (!x || x);
}

main() {
    int valorLogico;

    printf("Resolvendo a expressão: \n!(!X && X) && (!X || X)");

    printf("\nForneça o valor de X [1 para verdadeiro e 0 para falso]: ");
    scanf("%d", &valorLogico);

    printf(expressaoLogica(valorLogico));

}
