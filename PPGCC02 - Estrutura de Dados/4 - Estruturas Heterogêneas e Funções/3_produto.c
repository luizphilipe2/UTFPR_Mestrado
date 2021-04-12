#include "stdio.h"

void produto(int *v1, int*v2, int *v3, int N){
     for (int i = 0; i < N; i++){
        *(v3+i) = *(v2+i) * *(v1+i);
    }
}

int main(){



    int v1[5]={1,2,3,4,5};
    int v2[5]={5,4,3,2,1};
    int v3[5];
    produto(v1, v2, v3, 5);
    for (int i = 0; i < 5; i++){
        printf("%i ", *(v3+i));
    }

}