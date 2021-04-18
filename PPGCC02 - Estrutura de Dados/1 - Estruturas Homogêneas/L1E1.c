/* 1 - [L1E1] Uma empresa classifica seus funcion·rios em 3 nÌveis de acordo com um Ìndice de produtividade. 
S„o eles: (1) Excelente, (2) Intermedi·rio e (3) Regular. Cada nÌvel adiciona ou subtrai uma porcentagem do funcion·rio, 
de acordo com a tabela abaixo. Crie um programa que leia o sal·rio base e o Ìndice de produtividade de um funcion·rio (um n˙mero inteiro de 1 a 3).
 Em seguida, o programa deve calcular e imprimir o sal·rio com o abono, seguindo a tabela a seguir. Crie uma funÁ„o para calcular o sal·rio.

1 Excelente +65% do sal·rio base
2 Intermedi·rio +20% do sal·rio base
3 Regular -10% do sal·rio base */

#include<stdio.h>
#include<stdlib.h>

int main(void){

    double salario;
    int indiceProdutividade;

    printf("Digite o sal√°rio do funcion√°rio: ");
    scanf("%lf", &salario);

    printf("Digite o √≠ndice de produtividade do funcion√°rio: ");
    scanf("%i", &indiceProdutividade);

    switch(indiceProdutividade){
        case 1: 
        salario = salario + (salario*65)/100;
        break;

        case 2:
        salario = salario + (salario*20)/100;
        break;

        case 3:
        salario = salario + (salario*-10)/100;
        break;

        default: 
        printf("√ùndice de produtividade inv√°lido");
    }

    printf("Sal√°rio do funcion√°rio = %.2lf \n", salario);
    return 0;
}