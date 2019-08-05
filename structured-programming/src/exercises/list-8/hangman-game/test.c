#include <stdio.h>

typedef struct TPessoa {
    char nome[80];
    int idade;
} Pessoa;

typedef struct TEndereco {
    char rua[80];
    int numero;
} Endereco;

typedef struct TDadosPessoa {
    Pessoa p;
    Endereco e;
} DadosPessoa;

main() {
    DadosPessoa dp;
    FILE * f;

    printf("Forneca o nome: ");
    gets(dp.p.nome);

    printf("Forneca a rua: ");
    gets(dp.e.rua);

    printf("Forneca a idade: ");
    scanf("\n%d", &dp.p.idade);


    printf("Forneca o numero: ");
    scanf("\n%d", &dp.e.numero);

    // Abrir o arq (se nao existir cria), paramentros(caminho mais nome, modo) => modos r, w, a
    f = fopen("person.dat", "ab+");

    fwrite(&dp, sizeof(Pessoa), 1, f);
    rewind(f);

    while(1) {
        fread(&dp, sizeof(Pessoa), 1, f);
        if(feof(f)) break;

        printf("\nNome:%s \nIdade: %d \nRua: %s \nNumero: %d\n\n", dp.p.nome, dp.p.idade, dp.e.rua, dp.e.numero);
    }

    fclose(f);

}
