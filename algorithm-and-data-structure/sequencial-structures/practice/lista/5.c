/*
Escreva uma rotina que receba uma lista de alunos e calcule a média das médias das
notas dos alunos presentes nela.
*/

#include "4.h"

float aluno_calcular_media_geral(aluno **lista, int tam) {
    int i, numero_alunos;
    float somatorio, media_aluno;
    aluno aluno;

    somatorio = media_aluno = 0;
    numero_alunos = lista_numero_elementos(lista, tam);

    for(i = 0; i < numero_alunos; i++) {
        aluno = lista_obter_elemento(i, lista);
        media_aluno = (aluno.p1 + aluno.p2)/2;
        somatorio = somatorio + media_aluno;
    }

    return somatorio/numero_alunos;
}
