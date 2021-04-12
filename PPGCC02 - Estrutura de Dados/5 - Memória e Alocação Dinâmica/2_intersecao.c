#include "stdio.h"
#include "stdlib.h"

int* intersecao(int *v1, int *v2, int n1, int n2, int* qtde){
    if (v1 == NULL || v2 == NULL || n1 < 0 || n2 < 0)
        return NULL;

    *qtde = 0;

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            if (v1[i] == v2[j])
                *qtde++;

    int* v_intersecao = (int*) malloc((*qtde)*sizeof(int));
    int count = 0;

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            if (v1[i] == v2[j]){
                v_intersecao[count] = v1[i];
                count++;
            }
                
    return v_intersecao;
}

int main(){

    printf("\nTeste 1 \n");
    int v1[5]={1,2,3,4,5};
    int v2[5]={2,3,7,8,9};
    int p = 1;
    int *v3 = intersecao(v1, v2, 5, 5, &p);

    for (int i = 0; i < 2; i++){
        printf("%d ", *(v3+i));
    }
    //0 0 1 2 2

    printf("\nTeste 2 \n");
    int v4[8]={7,6,5,4,3,2,1,0};
    int v5[8]={7,6,5,4,3,2,1,0};
    int *v6 = intersecao(v4, v5, 8, 8, &p);

    for (int i = 0; i < 8; i++){
        printf("%d ", *(v6+i));
    }
    //7 6 5 4 3 2 1 0
    
    printf("\nTeste 3 \n");
    int *v7 = intersecao(NULL, NULL, 1, 1, &p);
    printf("%d", v7 == NULL);
    //1
    
    printf("\nTeste 4 \n");
    int v8[8]={7,6,5,4,3,2,1,0};
    int v9[8]={7,6,5,4,3,2,1,0};
    int *v10 = intersecao(v8, v9, -2, 3, &p);

    printf("%d\n", v10 == NULL);
    //1

}