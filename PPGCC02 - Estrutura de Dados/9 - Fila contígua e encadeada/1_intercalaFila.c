#include "fila.h"

void printInt(void *n){
    int* p = n;
    printf("%i", *p);
}

Fila* intercalaFila(Fila *f1, Fila *f2){
    Fila *f3 = fila_criar();

    while (!fila_vazia(f1) || !fila_vazia(f2)){
        
        if(fila_tamanho(f1) > 0){
            int dado;
            fila_primeiro(f1, &dado);
            fila_inserir(f3,dado);
            fila_remover(f1, &dado);
        }

        if(fila_tamanho(f2) > 0){
            int dado2;
            fila_primeiro(f2, &dado2);
            fila_inserir(f3,dado2);
            fila_remover(f2, &dado2);
        } 
    }

    return f3;
}




int main(){

    Fila* f1 = fila_criar();
    fila_inserir(f1, 10);
    fila_inserir(f1, 20);
    fila_inserir(f1, 30);
    fila_inserir(f1, 40);
    fila_inserir(f1, 50);
    fila_inserir(f1, 60);
    fila_inserir(f1, 70);
    fila_inserir(f1, 80);
    fila_inserir(f1, 90);
    fila_imprimir(f1, printInt);
    printf("\n");


    Fila* f2 = fila_criar();
    fila_inserir(f2, 5);
    fila_inserir(f2, 6);
    fila_inserir(f2, 7);
    fila_imprimir(f2, printInt);
    printf("\n");

    // Fila *f3 = intercalaFila(f1,f2);
    // fila_imprimir(f3, printInt);
    // printf("\n");

    Fila* f4 = fila_clone(f2);
    fila_imprimir(f4, printInt);
    printf("\n");

    fila_inverter(f1);
    fila_imprimir(f1, printInt);
    printf("\n");



}
