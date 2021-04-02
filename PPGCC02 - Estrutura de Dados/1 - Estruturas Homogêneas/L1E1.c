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
        printf("Índice de produtividade inválido");
    }

    printf("Salário do funcionário = %.2lf \n", salario);
    return 0;
}