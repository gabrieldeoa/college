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

int armstrongRec(int x){
    return armstrongRecAux(x, 1);
}

int armstrongRecAux(int x, int pos){
    if (pos == qtdDeDigitos(x))
        return (int)pow(digito(x, pos), qtdDeDigitos(x));
    else
        return armstrongRecAux(x, pos+1) + (int)pow(digito(x, pos), qtdDeDigitos(x));
}

main()
{
 int x;
    printf("ESCREVA UM NUMERO INTEIRO: ");
    scanf("%d", &x);

    printf("O numero %d %d numero de armstrong",x, armstrongRec(x));
}
