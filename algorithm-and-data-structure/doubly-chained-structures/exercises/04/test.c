#include "exercise-four.h"

int main () {
    lista listaVeiculos, listaPorMarca;

    char marca[10] = "ford";

    listaVeiculos = lista_ler();

    printf("\n--> VEICULOS <--\n");
    lista_exibir(listaVeiculos);
    printf("--> FIM VEICULOS <--\n");

    listaPorMarca = lista_obter_veiculo_por_marca(marca, listaVeiculos);

    printf("\n--> POR MARCA <--\n");
    lista_exibir(listaPorMarca);
    printf("--> FIM POR MARCA <--\n");
}