#include <stdio.h>
#include <conio.h>
#include <math.h>

int digito(int n, int pos) {
  int i, r;
  for (i = 1; i <= pos; i++){
    r = n % 10;
    n = n / 10;
  }
  return r;
}

int qtdDeDigitos(int n){
  int r=0;
  if (n == 0) return 1;
  while (n != 0){
    n = n / 10;
    r++;
  }
  return r;
}

int armstrongRec(int a){
    return armstrongRecAux(a, 0, 1) == a;
}

// ERRADO ---- TODO
int armstrongRecAux(int a, int res, int aux){
    if(qtdDeDigitos(a) == aux)
        return 0;
    else if
        return res + armstrongRecAux(a, (int)pow(digito(a,aux+1), qtdDeDigitos(aux)));
        return armstrongRecAux(a, (int)pow(digito(a,aux+1), qtdDeDigitos(aux))));
}

main()
{
 int x;
    printf("ESCREVA UM NUMERO INTEIRO: ");
    scanf("%d", &x);

    printf("O numero %d %s numero de armstrong",x, armstrongRec(x)? "e" : "nao e");
}
