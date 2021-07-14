#include "stdio.h"
#include "stdlib.h"

int fib(int i){
    if (i <= 1)
        return i;
    else 
        return fib(i-1) + fib(i-2);
}

int main(){

    printf("%d \n", fib(1));
    printf("%d \n", fib(2));
    printf("%d \n", fib(3));
    printf("%d \n", fib(4));
    printf("%d \n", fib(5));
    printf("%d \n", fib(32));

}