/*
Programe uma função para receber um caractere e retornar a posição deste caractere no alfabeto, apenas se ele for uma letra.
Você pode chamar uma das funções programadas no exercício 1 desta lista para facilitar sua programação.
Porém, caso o caractere recebido no parâmetro desta função não seja uma letra, o retorno deste módulo deve ser o valor zero. 
Em seguida, chame a função criada a partir de um módulo main para testar seu programa. 
*/
#include <stdio.h>

float calcular(float op1, float op2, char opr) {
    float resultado;

    switch (opr) {
        case '+':
            resultado = op1 + op2;
            break;
        case '-':
            resultado = op1 - op2;
            break;
        case '*':
        case 'x':
        case 'X':
            resultado = op1 * op2;
            break;
        case '/':
        case ':':
            resultado = op1 / op2;
            break;
    }

    return resultado;
}

main() {
    float n1, n2, resultado;
    char opr;

    printf("Forneca o primeiro valor ");
    scanf("%f", &n1);

    printf("\nForneca o segundo ");
    scanf("%f", &n2);

    printf("\nForneca o operador ");
    scanf("\n", &opr);
    opr = getchar();

    resultado = calcular(n1, n2, opr);

    printf("\n%.2f %c %.2f = %.2f", n1, opr, n2, resultado);
}
