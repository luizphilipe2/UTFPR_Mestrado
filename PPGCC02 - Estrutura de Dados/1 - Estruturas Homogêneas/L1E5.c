/*
5 - [L1E5] Faça um programa que:
Leia  um  inteiro n(2 ? n ? 3),  crie e  leia  uma  estrutura  que  é  uma  matriz quadrada  de  ordem n,  contendo  sua dimensão e seus elementos. 
Crie a matriz adjunta da matriz lida. A matriz adjunta é composta pelos cofatores da matriz geradora. 
O cofator do elemento Aij é o determinante da matriz que se obtém eliminando-se as linhas i e j da matriz original.  
Exemplo de cálculo do cofator do elemento 
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int cofator(int tamanho, int m[tamanho][tamanho], int x, int y){

    int principal = 1;
    int secundaria = 1;
    int auxLinhaPrincipal, auxColunaPrincipal = -1;
    int auxLinhaSecundaria, auxColunaSecundaria = -1;

    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++){
            if (tamanho == 2){
                if (x != i && y != j)
                    return m[i][j];
            } else { 
                if (x != i && y != j){
                    if (auxLinhaPrincipal != i && auxColunaPrincipal != j){
                        principal *= m[i][j];
                        auxLinhaPrincipal = i;
                        auxColunaPrincipal = j;
                    } else if (auxLinhaSecundaria != i && auxColunaSecundaria != j) {
                        secundaria *= m[i][j];
                        auxLinhaSecundaria = i;
                        auxColunaSecundaria = j;
                    }
                }
            }
        }

    return principal-secundaria;
}

int main(void){

    int tamanhoMatriz;
    printf("Digite o tamanho da matriz (valores aceitos: 2 ou 3)\n");
    scanf(" %i", &tamanhoMatriz);

    int matriz[tamanhoMatriz][tamanhoMatriz];
    int matrizAdjunta[tamanhoMatriz][tamanhoMatriz];

    if (tamanhoMatriz != 2 && tamanhoMatriz != 3){
        printf("Valor invÃ¡lido \n");
        return 0;
    }

    for (int i = 0; i < tamanhoMatriz; i++)
        for (int j = 0; j < tamanhoMatriz; j++){
             printf("Digite o elemento A%i%i: ", i, j);
             scanf(" %i", &matriz[i][j]);
        }

    printf("Matriz Adjunta: \n");
    for (int i = 0; i < tamanhoMatriz; i++){
        for (int j = 0; j < tamanhoMatriz; j++){
            matrizAdjunta[i][j] = cofator(tamanhoMatriz, matriz, i, j);

            printf(" %i", matrizAdjunta[i][j]);           
        }
        printf("\n");
    }


}