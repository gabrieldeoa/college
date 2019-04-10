/*
Um cálculo aproximado para a raiz quadrada de um número positivo n, segue o seguinte algoritmo:

i) 	Estabelecer um intervalo de atuação entre a=0 e b=n
ii) Calcular o ponto médio c do intervalo
iii Se c2 > n, reduzir o intervalo de atuação fazendo b = c; caso contrário, reduzir o intervalo de atuação fazendo a = c
iv)	Repetir os passos ii) e iii) até que o tamanho do intervalo de atuação torne-se muito pequeno, por exemplo, menor que 10-6
Escreva uma função para estimar uma aproximação para a raiz quadrada de um número positivo. Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <math.h>

float raiz(int n) {
    float a = 0;
    float b = n;
    float c = (a+b)/2;
    float parada = pow(10, -6);

    while(fabs(a-b) > parada ) {
        if((c*c) > n) {
            b = c;
        } else {
            a = c;
        }
        c = (a+b)/2;
    }

    return c;
}

main() {
    int x, r;
    while(1) {
        system("clear");
        printf("\nraiz de: ");
        scanf("%d", &x);
        printf("\nraiz quadrada de %d é %f", x ,raiz(x));


        printf("\ndeseja continuar ? [1 - sim, qualquer numero para nao]: ");
        scanf("%d", &r);

        if(r != 1) break;
    }


}
