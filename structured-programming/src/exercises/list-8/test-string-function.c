#include<stdio.h>
#include<string.h>

int strLen (char * t1) {
    int i;

    for(i = 0; t1[i] != '\0'; i++);

    return i;
}

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


int main() {
    char c[20] = "a";
    char d[20] = "f";

    printf("%d", strcmp("joao", "jose"));



    strCpy(c, "abcde");
    printf("\n\n%s", c);

    strCat(c,d);
    printf("\n\n%s", c);






}
