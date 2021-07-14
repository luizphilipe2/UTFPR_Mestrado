#include "stdio.h"
#include "stdlib.h"

float soma(int n, float *v){
    if (n < 0) return 0;

    return v[n] + soma(n-1, v);
}

int main(){

    printf("\nTeste 1 \n");
    float v1[5]={1,2,3,4,5};
    float v2[5]={0,0,1,2,2};
    

    printf("%f", soma(5, v1));

}