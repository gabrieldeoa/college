/*
Implemente as funções do exercício 1 desta lista usando o operador ternário.
*/
#include <stdio.h>

int letraMinuscula(char c) {
    return (c >= 'a' && c <= 'z') ? 1 : 0;
}

int letraMaiuscula(char c) {
    return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

int letra(char c) {
    return (letraMinuscula(c) || letraMaiuscula(c)) ? 1 : 0;
}

int vogal(char c) {
    return (c == 'a' || c == 'e' || c == 'i'|| c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I'|| c == 'O' || c == 'U' ) ? 1 : 0;
}

int consoante(char c) {
    return (letra(c) && !vogal(c)) ? 1 : 0;
}

int algarismo(char c) {
    return (c >= '0' && c<= '9') ? 1 : 0;
}


main() {
    char c;

    printf("Forneça um caracter: ");
    c = getchar();

    if(letra(c)){
        if(letraMinuscula(c)){
            printf("\nO caracter %c é uma letra minuscula", c);
        }

        if(letraMaiuscula(c)){
            printf("\nO caracter %c é uma letra maiuscula", c);
        }

        if(vogal(c)){
            printf("\nO caracter %c é uma vogal", c);
        }

        if(consoante(c)){
            printf("\nO caracter %c é uma consoante", c);
        }

    } else if (algarismo(c)){
        printf("\n  O caracter %c é um algarismo", c);
    } else {
        printf("É um caracter especial", c);
    }
}

