/*

*/

#include <stdio.h>
// =====> OPOSTO
int opostoRecAux(int n, int aux) {
    if(n > 0){
        aux--;
        if(n + aux == 0) return aux;
        else return opostoRecAux(n, aux);
    }
    else if(n < 0) {
        aux++;
        if(aux + n == 0) return aux;
        else return opostoRecAux(n,aux);
    }
    else return 0;
}

int opostoRec(int n) {
    return opostoRecAux(n, 0);
}


// =====> VALOR ABSOLUTO
int valorAbsolutoRec(int n) {
    // Usando a função oposto
    //return (n >= 0) ? return n : opostoRec(n);

    //Usando a recursiva de valor absuluto
    return valorAbsolutoRecAux(n, 0);

}

int valorAbsolutoRecAux(int n, int aux) {
    if(n > 0) return n;
    else if( n < 0) {
        aux++;
        if(aux + n == 0) return aux;
        else return valorAbsolutoRecAux(n, aux);
    }
    else return 0;
}


// =====> ADIÇÃO
int adicaoRec(int n, int m) {
    return adicaoRecAux(n, m, n);
}

int adicaoRecAux(int n, int m, int aux) {
    if(m >= 0) {
        aux++;
        if(n + m == aux) return aux;
        else return adicaoRecAux(n, m, aux);
    } else {
        aux--;
        if(n + m == aux) return aux;
        else return adicaoRecAux(n, m, aux);
    }
}


// =====> SUBTRAÇÃO
int subtracaoRec(int n, int m) {
    int mOposto = opostoRec(m);

    return adicaoRec(n, mOposto);
}


// =====> MULTIPLICAÇÃO

int multiplicacaoRec(int n, int m) {
    return multiplicacaoRecAux(n, m, m);
}
int multiplicacaoRecAux(int n, int m, int aux) {
    if(m > 0) {
        if(m * n == aux) return aux;
        else return multiplicacaoRecAux(n, m, adicaoRec(aux, n));
    } else {
        if(m * n == aux) return aux;
        else return multiplicacaoRecAux(n, m, adicaoRec(aux, opostoRec(n)));
    }
}

/*
int divisaoRec(int n, int m) {
    return divisaoRecAux(valorAbsolutoRec(n), valorAbsolutoRec(m), 0, n, m);
}

int divisaoRecAux(int n, int m, int r, int a, int b) {
    if(subtracaoRec(n, m) >= 0)
        return divisaoRecAux(subtracaoRec(n, m), m, r+1, a, b);

    else if(multiplicacaoRec(a, b) > 0)
        return r;

    else
        return opostoRec(r);
}

int restoDivisao(int n, int m) {
    int aux = multiplicacao(divisao(n,m), m);

    return subtracao(n, aux);
}
*/
main() {
    int x, y;

    //printf("Forneça dois números:");
    printf("\nO primero: ");
    scanf("%d", &x);

    printf("\nO segundo: ");
    scanf("%d", &y);

    printf("\no oposto de %d e %d", x, opostoRec(x));
    printf("\no valor absoluto de %d e %d", x, valorAbsolutoRec(x));
    printf("\n%d + %d = %d", x, y, adicaoRec(x, y));
    printf("\n%d - %d = %d", x, y, subtracaoRec(x, y));
    printf("\n%d x %d = %d", x, y, multiplicacaoRec(x, y));
    //printf("\n%d / %d = %d", x, y, divisaoRec(x, y));
    //printf("\n%d %% %d = %d", x, y, restoDivisao(x, y));

}
