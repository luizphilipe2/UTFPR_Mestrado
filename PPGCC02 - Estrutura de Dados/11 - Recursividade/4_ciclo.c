#include "stdio.h"
#include "stdlib.h"

int ciclo(int n){
    if (n < 1) return 0;
    int comp = 1;

    while (n > 1){
        printf("%d ", n);
        if (n % 2 == 0)
            n = n/2;
        else 
            n = (n*3)+1;
        comp++;
    }
    printf("%d ", n);
    return comp;
}

int cicloR(int n){
    printf("%d ", n);
    if (n < 1) return 0;
    if (n == 1) return 1;
    int comp = 1; 

    if (n % 2 == 0)
        n = n/2;
    else 
        n = (n*3)+1;
    
    return comp + cicloR(n);
}

int main(){

    printf("%d \n", cicloR(22));
    printf("%d \n", ciclo(22));
}