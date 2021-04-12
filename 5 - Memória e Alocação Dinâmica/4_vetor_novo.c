#include "stdio.h"
#include "stdlib.h"

int* vetor_novoA(int tamanho, int valor){
    int* vetor_retorno = (int*) calloc(tamanho, sizeof(int));

    for (int i = 0; i < tamanho; i++){
        vetor_retorno[i] = valor;
    }

    return vetor_retorno;
}

void vetor_novoB(int tamanho, int valor, int** finalVetor){
    *finalVetor = (int*) calloc(tamanho, sizeof(int));

    for (int i = 0; i < tamanho; i++){
        (*finalVetor)[i] = valor;
    }
}

int main(){
   int *v1, *v2;
   v1 = vetor_novoA(10, -1);
   vetor_novoB(5, 0, &v2);
}