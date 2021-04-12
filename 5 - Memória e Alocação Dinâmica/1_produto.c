#include "stdio.h"
#include "stdlib.h"

int* produto(int *v1, int *v2, int N){
    int* v_produto = (int*) malloc(N*sizeof(int));

    if (v1 == NULL || v2 == NULL || N < 0)
        return NULL;

    for (int i = 0; i < N; i++)
        v_produto[i] = v1[i] * v2[i];

    return v_produto;
}

int main(){

    printf("\nTeste 1 \n");
    int v1[5]={0,0,1,2,2};
    int v2[5]={0,0,1,2,2};
    int *v3 = produto(v1, v2, 5);

    for (int i = 0; i < 5; i++){
        printf("%d ", *(v3+i));
    }
    //0 0 1 4 4

    printf("\nTeste 2 \n");
    int v4[8]={7,6,5,4,3,2,1,0};
    int v5[8]={7,6,5,4,3,2,1,0};
    int *v6 = produto(v4, v5, 8);

    for (int i = 0; i < 8; i++){
        printf("%d ", *(v6+i));
    }
    //49 36 25 16 9 4 1 0
    
    printf("\nTeste 3 \n");
    int *v7 = produto(NULL, NULL, 8);
    printf("%d", v7 == NULL);
    //1
    
    printf("\nTeste 4 \n");
    int v8[8]={7,6,5,4,3,2,1,0};
    int v9[8]={7,6,5,4,3,2,1,0};
    int *v10 = produto(v8, v9, -1);

    printf("%d\n", v10 == NULL);
    //1
}