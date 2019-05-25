/*
 Termina a função idade adicionando o que falta depois de //o que falta

 lembrando que o codigo abaixo esta pegando a data do sistema operacional.
*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int idade (int d, int m, int a) {
  time_t horaDoSO;
  struct tm *tempo;

  int dia, mes, ano;

  tempo = (struct tm *)malloc(sizeof(struct tm));
  time(&horaDoSO);
  tempo = localtime(&horaDoSO);
  dia   = tempo->tm_mday;
  mes   = tempo->tm_mon  + 1;
  ano   = tempo->tm_year + 1900;
  free(tempo);

  // o que falta

  return (m > mes || (m == mes && d > dia)) ? ano-a-1 : ano-a;
}

int faixaEtaria(int d, int m, int a) {

    int faixaEtaria = idade(d,m,a)/10;

    if(faixaEtaria == 0)
        return 0;
    else if(faixaEtaria == 1)
        return 1;
    else if(faixaEtaria >=2 && faixaEtaria <=6)
        return 2;
    else return 3;
}

int faixaEtariaComSwitch(int d, int m, int a) {

    int faixaEtaria = idade(d,m,a)/10;

    switch(faixaEtaria) {
        case 0: return 0;
        case 1: return 1;
        case 2:
        case 3:
        case 4:
        case 5: return 2;
        default: return 3;
    }
}

main() {
    int d, m, a;

    printf("Forneca o dia do seu nascimento [1-31]: ");
    scanf("%d", &d);

    printf("\nForneca o mes de seu nascimento [1-12]: ");
    scanf("%d", &m);

    printf("\nForneca o ano de seu nascimento [ex:1985]: ");
    scanf("%d", &a);

    printf("\nPelo sua data de nascimento voce tem %d anos e e", idade(d,m,a));

    switch(faixaEtaria(d,m,a)) {
        case 0: printf(" Crianca.");
            break;
        case 1: printf(" Adolescente.");
            break;
        case 2: printf(" Adulto.");
            break;
        case 3: printf(" Idoso.");
            break;
    }
}
