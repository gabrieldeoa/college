#include <stdio.h>
#include <stdlib.h>

typedef enum TTipoTelefone {
    residencial = 1,
    comercial,
    movel
} TipoTelefone;

typedef struct TTelefone {
    int ddd;
    int numero;
    TipoTelefone tipo;

} Telefone;

typedef struct TContato {
    char * nome;
    Telefone telefone;
} Contato;


char* TipoTelefoneParaTexto(TipoTelefone tipo) {
    switch(tipo) {
        case residencial: return "residencial";
        case comercial: return "comercial";
        case movel: return "movel";
    }
}

main() {
    int tipo;
    Contato contato;
    contato.nome = (char *)malloc(sizeof(char*));

    printf("Forneca o nome do contato: ");
    gets(contato.nome);

    printf("Forneca o ddd do telefone do contato: ");
    scanf("%d", &contato.telefone.ddd);

    printf("Forneca o numero do telefone do contato: ");
    scanf("%d", &contato.telefone.numero);

    printf("Forneca o tipo do telefone do contato: \n");
    printf("\t1 = residencial, 2 = comercial e 3 = movel \n:");
    scanf("%d", &tipo);

    contato.telefone.tipo = (TipoTelefone)tipo;

    printf(
        "O contato e %s (%d)%d do tipo %s",
        contato.nome,
        contato.telefone.ddd,
        contato.telefone.numero,
        TipoTelefoneParaTexto(contato.telefone.tipo)
    );

    free(contato.nome);
}
