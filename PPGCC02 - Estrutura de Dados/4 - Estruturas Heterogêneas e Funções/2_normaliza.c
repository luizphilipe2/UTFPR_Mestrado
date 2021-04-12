#include "stdio.h"

void normaliza(float *v, int N){
    int maiorNumero = 0;

    for (int i = 0; i < N; i++){
        if (*(v+i) < 0)
            return;
        
        if (*(v+i) > maiorNumero)
            maiorNumero = *(v+i);
    }

    if (maiorNumero == 0)
        return;

    for (int i = 0; i < N; i++)
        *(v+i) /= maiorNumero;
}

int main(){

    float v[5]={0,0,1,2,2};
    normaliza(v, 5);
    for (int i = 0; i < 5; i++){
        printf("%.1f ", *(v+i));
    }


    float v4[10] = {5,5,5,10,15,20,25,40, 10, 10};
    normaliza(v4, 10);
    for (int i = 0; i < 10; i++){
        printf("%.1f ", *(v4+i));
    }

}