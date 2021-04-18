/* 1 - [L1E1] Uma empresa classifica seus funcion�rios em 3 n�veis de acordo com um �ndice de produtividade. 
S�o eles: (1) Excelente, (2) Intermedi�rio e (3) Regular. Cada n�vel adiciona ou subtrai uma porcentagem do funcion�rio, 
de acordo com a tabela abaixo. Crie um programa que leia o sal�rio base e o �ndice de produtividade de um funcion�rio (um n�mero inteiro de 1 a 3).
 Em seguida, o programa deve calcular e imprimir o sal�rio com o abono, seguindo a tabela a seguir. Crie uma fun��o para calcular o sal�rio.

1 Excelente +65% do sal�rio base
2 Intermedi�rio +20% do sal�rio base
3 Regular -10% do sal�rio base */

#include<stdio.h>
#include<stdlib.h>

int main(void){

    double salario;
    int indiceProdutividade;

    printf("Digite o salário do funcionário: ");
    scanf("%lf", &salario);

    printf("Digite o índice de produtividade do funcionário: ");
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
        printf("Ýndice de produtividade inválido");
    }

    printf("Salário do funcionário = %.2lf \n", salario);
    return 0;
}