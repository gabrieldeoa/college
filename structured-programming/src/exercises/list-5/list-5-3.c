/*
Um número primo é um inteiro positivo que possui apenas dois divisores também positivos diferentes.
Escreva uma função para retornar verdadeiro ou falso para o fato de um número ser primo.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>

int quantidadeDivisores(int x) {
    int divisores = 0;
    for(int i = 1; i <= x; i++){
        if(x % i == 0)
            divisores++;
    }
    return divisores;
}

int primo(int x) {
    return (quantidadeDivisores(x) == 2);
}

int primo_direto(int n) {
    if(n == 0 || n == 1) return 0;

    for(int i=2; i < n; i++){
        if(n % i == 0){
            return 0;
        }
    }

    return 1;
}

main() {
    int n, r;

    while(1) {
        system("cls");// linux usa clear

        printf("\nForneca um numero para checar se ele e primo: ");
        scanf("%d", &n);

        printf("\nO numero %d %s primo. Diretamente", n, primo_direto(n) ? "e" : "nao e");
         printf("\nO numero %d %s primo. Usando a funcao auxiliar quantidadeDivisores", n, primo(n) ? "e" : "nao e");

        printf("\n\nDeseja Continuar [1 para sim e 2 para nao] ? ");
        scanf("%d", &r);

        if(r != 1 ) break;
    }
}
