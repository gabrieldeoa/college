#include "exercise-five.h"

int main () {
    lista listaVeiculos;

    char marca[10] = "ford";

    listaVeiculos = lista_ler();

    printf("\n--> VEICULOS <--\n");
    lista_exibir(listaVeiculos);
    printf("--> FIM VEICULOS <--\n");

    lista_remover_veiculo_mais_antigo(&listaVeiculos);
    printf("\n--> VEICULOS SEM O MAIS ANTIGO <--\n");
    lista_exibir(listaVeiculos);
    printf("--> FIM VEICULOS SEM O MAIS ANTIGO <--\n");
}