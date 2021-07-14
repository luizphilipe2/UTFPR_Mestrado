#include "stdio.h"
#include "stdlib.h"

int busca(int *v, int inicio, int fim, int item){
    if (inicio > fim) return -1;
    int meio = (inicio + fim)/2;

    if (item == v[meio])
        return meio;
    else if (item > v[meio])
        return busca(v, meio+1, fim, item);
    else 
        return busca(v, inicio, meio-1, item);    
}


int main(){

    int v[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    printf("%d \n", busca(v, 0, 19, 1));
    printf("%d \n", busca(v, 0, 19, 5));
    printf("%d \n", busca(v, 0, 19, 8));
    printf("%d \n", busca(v, 0, 19, 10));
    printf("%d \n", busca(v, 0, 19, 12));
    printf("%d \n", busca(v, 0, 19, 13));
    printf("%d \n", busca(v, 0, 19, 15));
    printf("%d \n", busca(v, 0, 19, 19));
    printf("%d \n", busca(v, 0, 19, 20));
}