#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
    unsigned int codigo;
    char nome[50];
    double *notas;
} Aluno;

Aluno* criaAluno(int quantidadeNotas){
    Aluno *a = (Aluno*) malloc(sizeof(Aluno));
    a->notas = (double*) calloc(quantidadeNotas, sizeof(double));

    return a;
}

void imprimeAluno(Aluno *a, int qtdNotas){
    printf("Imprimindo o aluno\n");
    printf("Código: %d\n", a->codigo);
    printf("Nome: %s\n", a->nome);
    
    for (int i = 0; i < qtdNotas; i++)
        printf("Nota %d: %.2lf\n", i+1, a->notas[i]);
}

int main(){
    Aluno *aluno = criaAluno(2);
    aluno->codigo = 1;
    strcpy(aluno->nome, "João");
    aluno->notas[0] = 9.9;
    aluno->notas[1] = 8.0;
    imprimeAluno(aluno, 2);
}