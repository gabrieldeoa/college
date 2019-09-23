/*
Escreva uma função recursiva
que retorne o enésimo termo da série de fibonacci.
*/
#include <stdio.h>

// recursivo
int fibonacciRecursivo(int termo){
   if(termo == 1 || termo == 2 ) return 1;
   else return fibonacciRecursivo(termo - 1) + fibonacciRecursivo(termo - 2);
}

int fib(int termo) {
    int aux, i = 3, penultimo = 1, ultimo = 1;

    if(termo == 1 || termo == 2)
        return 1;
    else {
        for(i = 3; i <= termo; i++ ) {
           aux = ultimo;
           ultimo = penultimo + ultimo;
           penultimo = aux;
        }
        return ultimo;
    }
}



int main() {
    int termo = 7;
    printf("RECURSIVO - O énesimo termo e: %d ", fibonacciRecursivo(termo));
    printf("\n\nO énesimo termo e: %d ", fib(termo));
}
