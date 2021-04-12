#include "stdio.h"

void troca (int *x, int *y){ 
   int temp = *x; 
   *x = *y; 
   *y = temp; 
}

void permuta(int *a, int *b, int *c){
    if(*b > *c)
        troca(b, c);    
    
    if(*a > *b)
        troca(a, b);

    if (*a > *b || *b > *c)
        permuta(a, b, c);

}

int main(){

    int a = 10, b = 5, c = 0;

    permuta(&a, &b, &c);

    printf("a: %i, b: %i, c: %i", a, b, c);



}