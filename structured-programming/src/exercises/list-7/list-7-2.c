/*
Um endereço compõe-se de tipo (Rua, Avenida, Largo, Jardim, Estrada etc.),
logradouro, número,complemento, bairro, cidade, estado e CEP.
Escreva uma definição para um tipo de dado capaz de representar um endereço.
*/
#include <stdio.h>
#include <stdlib.h>

typedef enum TTipoEndereco {
    Rua,
    Avenida,
    Largo,
    Jardim,
    Estrada
} TipoEndereco;

typedef struct TEndereco {
    TipoEndereco tipo;
    char * logradouro, * cidade;
    char estado[2];
    int numero, cep;
} Endereco;

char * TTipoEnderecoParaTexto(TipoEndereco tipo) {
    switch(tipo) {
        case Rua: return "Rua";
        case Avenida: return "Avenida";
        case Largo: return "Largo";
        case Jardim: return "Jardim";
        case Estrada: return "Estrada";
        default: "Tipo de endereco inválido";
    }
}

main() {
    int te;
    Endereco * endereco = (Endereco *)malloc(sizeof(Endereco));
    endereco->cidade = (char*)malloc(sizeof(char));
    endereco->logradouro = (char*)malloc(sizeof(char));

    printf("\nLogradouro: ");
    gets(endereco->logradouro);

    printf("\nCidade: ");
    gets(endereco->cidade);

    printf("\nEstado-UF: ");
    gets(endereco->estado);

    printf("\nTipo: ");
    printf("\n0 - Rua\n1 - Avenida\n2 - Largo\n3 - Jardim\n4 - Estrada\nForneca o numero do tipo de endereco:");
    scanf("%d", &te);
    endereco->tipo = (TipoEndereco)te;

    printf("\nCEP: ");
    scanf("%d", &endereco->cep);

    printf("\nNumero: ");
    scanf("%d", &endereco->numero);

    printf("\n\nSeu endereco e: %s %s nº %d, %d %s - %s",
        TTipoEnderecoParaTexto(endereco->tipo),
        endereco->logradouro,
        endereco->numero,
        endereco->cep,
        endereco->cidade,
        endereco->estado
    );

    free(endereco->logradouro);
    free(endereco->cidade);
    free(endereco);
}
