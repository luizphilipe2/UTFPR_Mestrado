#include<stdio.h>
#include<stdlib.h>

int main(void){

    int meses = 12;
    int semanas = 4;
    double matriz[meses][semanas];
    double totalDoAno = 0;
    double totalMensal = 0;


    printf("Insira os dados das vendas \n");
    for (int i = 0; i < meses; i++){
        printf("Vendas do mes %d: \n", i+1);
        for (int j = 0; j < semanas; j++){
            printf("Semana %d: ", j+1);
            scanf(" %lf", &matriz[i][j]);
        }
    }

    printf("Total vendido em cada mes do ano: \n");
    for (int i = 0; i < meses; i++){

        for (int j = 0; j < semanas; j++){
            totalMensal += matriz[i][j];
        }

        printf("Mes %d: %.2lf \n", i+1, totalMensal);
        totalDoAno += totalMensal;
        totalMensal = 0;
    }

    printf("Total vendido em cada semana do ano: \n");
    for (int i = 0; i < semanas; i++){
        double total;
        for (int j = 0; j < meses; j++){
            total += matriz[j][i];
        }

        printf("Semana %d: %.2lf \n", i+1, total);
        total = 0;
    }

    printf("Total vendido no ano: %.2lf \n", totalDoAno);

    return 0;
}