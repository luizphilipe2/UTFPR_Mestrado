#include<stdio.h>
#include<stdlib.h>

int main(void){

    int numero = 47; 
    int primo = 1;

    for (int i = 2; i < numero; i++){
        if (numero % i == 0){
            primo = 0;
            break;
        }
    }
//teste

    if (primo == 1){
        printf("numero é primo");
    } else { 
        printf("numero não é primo");
    }
}
