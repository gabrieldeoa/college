#include "../03/exercise-three.h"

int lista_remover_veiculo_mais_antigo(lista *listaVeiculos) {
    no_dup_enc *no = *listaVeiculos;
    veiculo veiculoMaisAntigo;

    if(*listaVeiculos == NULL)
        return LISTA_VAZIA;

    //assume o primeiro como mais antigo
    veiculoMaisAntigo = no->elemento;

    // se existir mais de um no
    if(no->proximo != NULL) {
        //passa para o segundo
        no = no->proximo;

        while(no != NULL) {
            // se o ano do elemento atual do loop for menor que o do veiculoMaisAntigo
            // atualiza o mais antigo 
            if( no->elemento.ano < veiculoMaisAntigo.ano) {
                veiculoMaisAntigo = no->elemento;
            }
            //avanca pro proximo no
            no = no->proximo;
        }
    }

    // Finalmente remove
    lista_remover(veiculoMaisAntigo, listaVeiculos);

    return SUCESSO;
}