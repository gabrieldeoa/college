/*
Uma empresa necessita cadastrar seus funcionários, considerando o seguinte:
a) o nome do funcionário;
b) sua data de nascimento (divida a data de nascimento em três dados individuais: dia, mês e ano);
c) seu salário; e
d) uma informação que informa se o funcionário é chefe dentro da empresa (‘S’ para sim; ‘N’ para não).
Escreva um módulo exclusivamente para receber estes dados e escrever uma frase na tela que contempla estes dados.
Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>

void printarFuncionarioInfo( char* nome, int dia, int mes, int ano, float salario, char chefia) {
    printf("Dados do Funcionário: \n");
    printf("Nome: %s\n Nascimento: %i/%i/%i\n Salário: %.2f\n Possui cargo de Chefe: %c", nome, dia, mes, ano, salario, chefia);
}

main() {
    char* nome;
    int dia = 0, mes = 0, ano = 0;
    float salario = 0.0;
    char chefia;

    // Alocando memória
    nome = (char*)malloc(sizeof(char));

    printf("Forneça o Nome: ");
    gets(nome);

    printf("\nDia:");
    scanf("%i", &dia);

    printf("\nMês: ");
    scanf("%i", &mes);

    printf("\nAno: ");
    scanf("%i", &ano);

    printf("\nForneça o salário: ");
    scanf("%f", &salario);

    printf("\nPossui cargo de chefia: [S] ou [N]: ");
    scanf("%c", &chefia);
    chefia = getchar();

    printarFuncionarioInfo( nome, dia, mes, ano, salario, chefia);

    // Liberando memória
    free(nome);
}
