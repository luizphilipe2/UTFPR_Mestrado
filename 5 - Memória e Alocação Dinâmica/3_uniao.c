#include "stdio.h"
#include "stdlib.h"

int* uniao(int *v1, int *v2, int n1, int n2, int* qtde){
    if (v1 == NULL || v2 == NULL || n1 < 0 || n2 < 0)
        return NULL;

    *qtde = n1+n2;
    int* v_uniao = (int*) malloc((*qtde)*sizeof(int));

    for (int i = 0; i < n1; i++)
        v_uniao[i] = v1[i];

    *qtde = n1;

    for (int i = 0; i < n2; i++){
        int existe = 0;
        for (int j = 0; j < *qtde; j++){
            if (v2[i] == v_uniao[j]){
                existe = 1;
            }
        }
        if (existe == 0){
            v_uniao[*qtde] = v2[i];
            (*qtde)++;
        }
    }

    int* v_uniao_return = (int*) malloc((*qtde)*sizeof(int));
    for (int i = 0; i < *qtde; i++){
        v_uniao_return[i] = v_uniao[i];
    }

    free(v_uniao);
    v_uniao = NULL;

    return v_uniao_return;
}

int main(){

    printf("\nTeste 1 \n");
    int v1[5]={1,2,3,4,5};
    int v2[5]={2,3,7,8,9};
    int p = 1;
    int *v3 = uniao(v1, v2, 5, 5, &p);

    for (int i = 0; i < p; i++){
        printf("%d ", *(v3+i));
    }
    //0 0 1 2 2

    printf("\nTeste 2 \n");
    int v4[8]={7,6,5,4,3,2,1,0};
    int v5[8]={7,6,5,4,3,2,1,9};
    int *v6 = uniao(v4, v5, 8, 8, &p);

    for (int i = 0; i < p; i++){
        printf("%d ", *(v6+i));
    }
    //7 6 5 4 3 2 1 0
    
    printf("\nTeste 3 \n");
    int *v7 = uniao(NULL, NULL, 1, 1, &p);
    printf("%d", v7 == NULL);
    //1
    
    printf("\nTeste 4 \n");
    int v8[8]={7,6,5,4,3,2,1,0};
    int v9[8]={7,6,5,4,3,2,1,0};
    int *v10 = uniao(v8, v9, -2, 3, &p);

    printf("%d\n", v10 == NULL);
    //1

}