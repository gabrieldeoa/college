/*
Seja X a seguinte sentença: “elefantes são mais pesados que gafanhotos”. Desenvolva a expressão:
    !(!X && X) && (!X || X)
*/

/*
7) A afirmação acima é verdadeira logo:
    !(!X && X) && (!X || X)
    !(!  && 1) && (!1 || 1)
     !(0 && 1) && (0 || 1)
        !0 && 1
        1 && 1
          1
A resposta é verdadeiro.
*/

/*
8)Você conseguiria avaliar a expressão da questão 7 desconhecendo o valor de X? Justifique.
   Caso não soubessemos o valor lógico, 0 ou 1, para x na expressão acima
   não importaria. O resultado da expressão será verdadeiro independente de x ser falso ou verdadeiro.
*/

#include <stdlib.h>
#include <stdio.h>

int expressaoLogica(int x) {
    return !(!x && x) && (!x || x);
}

main() {
    int valorLogico, resultado;

    printf("Resolvendo a expressão: \n!(!X && X) && (!X || X)");

    printf("\nForneça o valor de X [1 para verdadeiro e 0 para falso]: ");
    scanf("%d", &valorLogico);

    resultado = expressaoLogica(valorLogico);

    printf("Inserindo o valor %d, o resultado da expressao logica e: %d", valorLogico, resultado);

}
