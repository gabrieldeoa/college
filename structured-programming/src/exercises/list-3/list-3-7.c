/*
Programe uma função para receber um caractere e retornar a posição deste caractere no alfabeto,
apenas se ele for uma letra. Você pode chamar uma das funções programadas no exercício 1 desta lista para facilitar sua programação.
Porém, caso o caractere recebido no parâmetro desta função não seja uma letra, o retorno deste módulo deve ser o valor zero.
Em seguida, chame a função criada a partir de um módulo main para testar seu programa. 
*/
#include <stdio.h>

int letraMinuscula(char c) {
    int resultado = 0;

    if(c >= 'a' && c <= 'z')
        resultado = 1;

    return resultado;
}

int letraMaiuscula(char c) {
    int resultado = 0;

    if(c >= 'A' && c <= 'Z')
        resultado = 1;

    return resultado;
}

int letra(char c) {
    int resultado = 0;

    if(letraMinuscula(c) || letraMaiuscula(c))
        resultado = 1;

    return resultado;
}

int posicaoAlfabeto(char c) {
    if(!letra(c))
        return 0;

    if(letraMaiuscula(c))
        return c - 'A' + 1;
    else
        return c - 'a' + 1;
}

main() {
    char c;

    printf("\nForneca uma letra para saber sua posicao no alfabeto: ");
    scanf("%c", &c);

    printf("\nA posicao do \'%c\' e %d", c, posicaoAlfabeto(c));
}
