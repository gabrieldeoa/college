/*
Considerando os estados civis solteiro, casado, viúvo, separado e des­quitado,
escreva definições de tipos de dados para:
a. sexo;
b. estado civil.
*/

#include <stdio.h>

enum TSexo {masculino, feminino};

enum TEstadoCivil {
    solteiro,
    casado,
    viuvo,
    separado,
    desquitado
};

typedef enum TSexo Sexo;
typedef enum TEstadoCivil EstadoCivil;

char * TSexoParaTexto(Sexo sexo) {
    switch(sexo) {
        case masculino: return "masculino";
        case feminino: return "feminino";
        default: "sexo invalido";
    }
}

char * TEstadoCivilParaTexto(EstadoCivil estadoCivil) {
    switch(estadoCivil) {
        case solteiro: return "solteiro";
        case casado: return "casado";
        case viuvo: return "viuvo";
        case separado: return "separado";
        case desquitado: return "desquitado";
        default: "estado civil inválido";
    }
}

main() {
    int s, es;
    Sexo sexo;
    EstadoCivil estadoCivil;

    printf("Forneca o seu sexo [0-masculino ou 1-feminino]: ");
    scanf("%d", &sexo);
    //sexo = (Sexo)s;

    printf("Forneca o seu sexo [0-solteiro, 1-casado, 2-viuvo, 3-separdo, 4-desquitado]: ");
    scanf("%d", &estadoCivil);
    //estadoCivil = (EstadoCivil)es;

    printf("Voce e do sexo %s e seu estado civil e %s",
        TSexoParaTexto(sexo),
        TEstadoCivilParaTexto(estadoCivil)
    );
}
