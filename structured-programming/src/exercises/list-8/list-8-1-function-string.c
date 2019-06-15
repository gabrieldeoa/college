    /*
Neste exercício, você irá supor que algumas funções não existem em bibliotecas da linguagem C e as programará.
Em seguida, teste cada módulo programado em um módulo main. Segue a lista de funções a serem implementadas:
a. strcpy
b. strcat
c. strlen
d. strcmp
e. toupper
f. tolower
 */

#include <stdio.h>
#include <stdlib.h>

// a)
void strCpy(char * t1, char * t2 ) {
    int i;
    
    for(i = 0; t2[i] != '\0'; i++) {
        t1[i] = t2[i];
    }
}

// b)
void strCat(char * t1, char * t2) {
    int final = strLen(t1), i;

    for(i = 0; t2[i] != '\0'; i++) {
        t1[final+i] = t2[i];
    }
}

// c)
int strLen (char * t1) {
    int i;

    for(i = 0; t1[i] != '\0'; i++);

    return i;
}

// d)
int strCmp(char * t1, char * t2) {
    int i;
    for(i = 0; t1[i] != '\0' || t2[i] != '\0'; i++) {
        if(t2[i] < t1[i]) return 1;
        else if (t2[i] > t1[i]) return -1;
    }
    return 0;
}

// e)
char toUpper(char c) {
    return ( c >= 'a' && c <= 'z')? c - ('a' - 'A'): c;
}

// f)
char toLower(char c) {
    return ( c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}

int main() {
    char *t1 = (char *)malloc(sizeof(char));
    char *t2 = (char *)malloc(sizeof(char));
    char *clone = (char *)malloc(sizeof(char));

    printf("Forneca o primeiro texto: ");
    gets(t1);

    printf("Forneca o segundo texto: ");
    gets(t2);


    strCpy(clone, t1);

    printf("\nt1: %s", t1);
    printf("\nt2: %s", t2);
    printf("\ncopiei a t1 para clone: %s", clone);

    strCat(clone, t2);

    printf("\nt1: %s possui %d letras", t1, strLen(t1));
    printf("\nt2: %s possui %d letras", t2, strLen(t2));
    printf("\nclone: %s possui %d letras", clone, strLen(clone));

    switch(strCmp(t1, t2)) {
        case 1: printf("\nA %s e maior que %s", t1, t2); break;
        case 0: printf("\nA %s e %s são iguais", t1, t2); break;
        case -1: printf("\nA %s e menor que %s", t1, t2); break;
    }

    printf("\ntoLower A -> %c", toLower('A'));
    printf("\ntoUpper a -> %c", toUpper('a'));

    free(t1);
    free(t2);
    free(clone);
}




