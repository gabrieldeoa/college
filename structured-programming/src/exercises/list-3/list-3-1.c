/*
Usando o comando if sem a cláusula else, programe funções para receber um caractere e retornar verdadeiro ou falso.
Cada função deve verificar se o caractere recebido por parâmetro é:
 a) uma letra minúscula;
 b) uma letra maiúscula;
 c) uma letra;
 d) uma vogal;
 e) uma consoante;
 f) um algarismo. 
Em seguida, já podendo usar o if com else, chame os módulos programados a partir de um módulo main para testar seu programa. 
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

int vogal(char c) {
    int resultado = 0;

    if(c == 'a' || c == 'e' || c == 'i'|| c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I'|| c == 'O' || c == 'U' )
        resultado = 1;

    return resultado;
}

int consoante(char c) {
    int resultado = 0;

    if(letra(c) && !vogal(c))
        resultado = 1;

    return resultado;
}

int algarismo(char c) {
    int resultado = 0;

    if(c >= '0' && c<= '9')
        resultado = 1;

    return resultado;
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

