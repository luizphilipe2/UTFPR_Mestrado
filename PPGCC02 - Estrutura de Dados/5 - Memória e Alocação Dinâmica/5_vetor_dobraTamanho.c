#include "stdio.h"
#include "stdlib.h"

int vetor_dobraTamanho(int** vetor, int tamanho){
    int novo_tamanho = tamanho*2;
    int* vetor_retorno = (int*) calloc(novo_tamanho, sizeof(int));

    for (int i = 0; i < novo_tamanho; i++){
        if (i < tamanho)
            vetor_retorno[i] = (*(vetor))[i];
    }
    
    free(*vetor);
    *vetor = NULL;
    *vetor = vetor_retorno;

    return novo_tamanho;
}


int main(){
    int* v = (int*) calloc(3, sizeof(int));
    v[0] = 2;
    v[1] = 4;
    v[2] = 6;
    
    int novoTamanho = vetor_dobraTamanho(&v,3); 

    for (int i = 0; i < novoTamanho; i++){
        printf("%d ", *(v+i));
    }
    //Resultado esperado
    // [2,4,6,0,0,0]


    int* v2 = (int*) calloc(4, sizeof(int));
    v2[0] = 2;
    v2[1] = 2;
    v2[2] = 1;
    v2[3] = 3;
    
    printf("\n");
    int novoTamanho2 = vetor_dobraTamanho(&v2,4); 

    for (int i = 0; i < novoTamanho2; i++){
        printf("%d ", *(v2+i));
    }
    //Resultado esperado
    // [2,2,1,3,0,0,0,0]
}