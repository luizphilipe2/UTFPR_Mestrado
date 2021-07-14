#include "stdio.h"
#include "stdlib.h"

int potencia(int x, int n){
    if (n == 0)
        return 1;
    else 
        return (x * potencia(x, n-1));
}

int main(){

    printf("%d \n", potencia(2,8));
    printf("%d \n", potencia(3,3));
}