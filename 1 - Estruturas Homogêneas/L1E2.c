#include<stdio.h>
#include<stdlib.h>

int main(void){

    int qtdElementos;
    
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &qtdElementos);

    int vetor1[qtdElementos];
    int vetor2[qtdElementos];

    printf("Digite os numeros do vetor 1: ");

    for (int i = 0; i < qtdElementos; i++)
        scanf("%d", &vetor1[i]);

    printf("Digite os numeros do vetor 2: ");

    for (int i = 0; i < qtdElementos; i++)
        scanf("%d", &vetor2[i]);


    printf("\nv1: ");
    for (int i = 0; i < qtdElementos; i++)
        printf("%d ", vetor1[i]);

    printf("\nv2: ");
    for (int i = 0; i < qtdElementos; i++)
        printf("%d ", vetor2[i]);
    
    printf("\nv3: ");
    int vetor3[qtdElementos*2];
    for (int i = 0; i < qtdElementos; i++){
        vetor3[i] = vetor1[i];
        vetor3[i+1] = vetor2[i];
        printf("%d ", vetor3[i]);
        printf("%d ", vetor3[i+1]);
    }

    printf("\n");
    return 0;
}