#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getArrayFromFile(FILE *file, int** vet){

}

void troca(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int sort_array(int *vet, int tam){
    int i, j, min;
    for (i = 0; i < tam - 1; i++) {
        min = i;
        for (j = i + 1; j < tam; j++)
            if (vet[j] < vet[min])
                min = j;
 
        troca(&vet[min], &vet[i]);
    }
}

void escreve_array(int *vet, int tam, FILE *file){
    
}