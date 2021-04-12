#include "stdio.h"

int negativos(float *vet, int n){
    int negativos = 0;
    
    for(int i = 0; i < n; i++)
        if ( *(vet+i) < 0)
            negativos++;

    return negativos;
}

int main(){

float f[] = {3,4}; 
printf("%d", negativos(f, 2));

float f1[] = {-1, 0.8, -1.1 , 3.3333}; 
printf("%d", negativos(f1, 4));
}