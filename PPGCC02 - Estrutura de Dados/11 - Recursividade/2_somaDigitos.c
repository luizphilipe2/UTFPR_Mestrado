#include "stdio.h"
#include "stdlib.h"

int soma_digitos(int n){
    if (n == 0) return 0;

    return (n % 10) + soma_digitos(n/10);
}

int main(){

    printf("%d \n", soma_digitos(500));
    printf("%d \n", soma_digitos(123));
    printf("%d \n", soma_digitos(123456789));
    printf("%d \n", soma_digitos(159732846));
    printf("%d \n", soma_digitos(916238475));
    printf("%d \n", soma_digitos(951));

}