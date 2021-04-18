/*
2 - [L1E2] Escrever um programa que leia dois vetores de mesma dimensão (n). Para isso, o programa lê a dimensão dos vetores e seus elementos,
uma a um. O programa gera um terceiro vetor de dimensão 2n, cujos elementos são resultantes da intercalação dos vetores originais. 
O programa imprime todos os vetores. Por exemplo, considerando V1 e V2, obtemos V3:
v1: 1 3 5 7 9 11
v2: 2 4 6 8 10 12
v3: 1 2 3 4 5 6 7 8 9 10 11 12
*/

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