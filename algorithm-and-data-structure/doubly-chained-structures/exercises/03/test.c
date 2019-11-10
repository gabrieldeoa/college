#include "exercise-three.h"

int main () {
    lista listaVeiculos;

    listaVeiculos = lista_ler();
    veiculo veiculo;

    printf("\n--> VEICULOS <--\n");
    lista_exibir(listaVeiculos);
    printf("--> FIM VEICULOS <--\n");

    printf("NUMERO DE ELEMENTOS: %d", lista_numero_elementos(listaVeiculos));


    printf("\n DIGITE A PLACA DO VEICULO A SER REMOVIDO: ");
    scanf("\n");
    gets(veiculo.placa);

    lista_remover(veiculo, &listaVeiculos);

    printf("\n--> VEICULOS <--\n");
    lista_exibir(listaVeiculos);
    printf("--> FIM VEICULOS <--\n");



}