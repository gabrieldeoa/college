#include <stdio.h>
#include <stdlib.h>
#include "list-1-4.h"

main() {
    Aluno** alunos;
    int tam = 2;

    alunos = lista_aluno_ler(tam, tam);
    lista_aluno_exibir(alunos, tam);

    printf("\nMedia das medias %.2f", lista_aluno_media_das_medias(alunos, tam)); 
}