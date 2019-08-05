#include <stdio.h>
#include <stdlib.h>

typedef struct TAluno {
    int matricula;
    char nome[80];
    float cr;
} Aluno;

void pegaRegistroBin(FILE **a, int numeroRegistro) {
    Aluno aluno;
    rewind(*a);
    fseek(*a, (numeroRegistro-1) * sizeof(Aluno), 0);
    fread(&aluno, sizeof(Aluno), 1, *a);
    printf("nome: %s matricula: %d CR: %.2f\n", aluno.nome, aluno.matricula, aluno.cr);
}

void pegaRegistroTxt(FILE **a, int numeroRegistro) {
    rewind(*a);
    int i = 1;
    Aluno al;

    while(1) {
        fscanf(*a, "nome: %s matricula: %d CR: %.2f\n", &al.nome, &al.matricula, &al.cr);
        if(feof(*a) || i == numeroRegistro) break;
        i++;
    }
    printf("nome: %s matricula: %d CR: %.2f\n", al.nome, al.matricula, al.cr);
}

int main() {
    const char dir_bin[20] = "student.dat";
    const char dir_txt[20] = "student.txt";

    FILE * ab, *at;
    ab = fopen(dir_bin, "ab+");
    at = fopen(dir_txt, "a+");

    Aluno a;
    char opcao;

    while(1) {

        printf("Nome: ");
        scanf("\n");
        gets(a.nome);

        printf("Matricula: ");
        scanf("\n");
        scanf("%d", &a.matricula);

        printf("CR: ");
        scanf("%f", &a.cr);

        fwrite(&a, sizeof(Aluno), 1, ab);
        fprintf(at, "nome: %s matricula: %d CR: %.2f\n", a.nome, a.matricula, a.cr);

        printf("continuar ? s ou n");
        scanf("\n%c", &opcao);

        if(opcao != 's') break;
    }
    rewind(ab);

    pegaRegistroBin(&ab, 2);
    printf("\n--------------------------\n");
    pegaRegistroTxt(&at, 2);


    fclose(ab);
    fclose(at);
}
