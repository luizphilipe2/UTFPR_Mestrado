#include "stdio.h"
#include "string.h"

void inversa(char vet[], int size){
    char *p = &vet[size-1];

    printf("length: %i \n", size);

    for(int i = (size-1); i >= 0; i--){
        printf("%i ",*(p+i));
    }

    
}


int K_esimoDigito(int n, int k){
    int retorno = -1;

    while(k > 0){
        if (n == 0){
            retorno = -1;
            break;
        }

        retorno = n%10;
        n = n/10;
        k--;
    }



    return retorno;    
}

int main(){

    printf("Resultado: %i \n", K_esimoDigito(1800, 3));
    printf("Resultado: %i \n", K_esimoDigito(-100, 4));
    printf("Resultado: %i \n", K_esimoDigito(2, 3));
    printf("Resultado: %i \n", K_esimoDigito(189902, 3));


    

}