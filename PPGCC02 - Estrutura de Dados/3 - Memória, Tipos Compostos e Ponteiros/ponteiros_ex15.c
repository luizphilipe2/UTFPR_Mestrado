#include "stdio.h"

void inversa(int vet[], int size){
    int *p = vet + (size-1);

    for(int i = 0; i < size; i++){
        printf("%i ",*(p--));
    }
}


int main(){

int vet[3] = {4,5,6};
inversa(vet, 3);

printf("\n");

int vet1[1] = {4};
inversa(vet1, 1);

printf("\n");

int vet2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
inversa(vet2, 10);

printf("\n");

int vet3[0];
inversa(vet3,0);

int m[4][2] = {{1,2},
               {3,4},
               {5,6},
               {7,8}};
inversa(m, 8);

}