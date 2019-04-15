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


int armstrong (int a){
    int qtdD = qtdDeDigitos(a);
    int res = 0, i;

    for(i = 1; i <= qtdD;i++)
        res = res + (int)pow(digito(a,i) ,qtdD);
    return res == a;
}


main()
{
 int x;
    printf("ESCREVA UM NUMERO INTEIRO: ");
    scanf("%d", &x);

    printf("O numero %d %s numero de armstrong",x, armstrong(x)? "e" : "nao e");
}
