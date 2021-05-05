#include <stdio.h>
#include <string.h>

#include "fila.h"

void printInt(void *n){
    int* p = n;
    printf("%i", *p);
}

int main(){

    TipoElemento elemento;
      /**************************************
    * Teste insercao e primeiro
    **************************************/
    Fila* f1 = fila_criar();
    fila_inserir(f1, 10);
    fila_inserir(f1, 20);
    fila_inserir(f1, 30);
    fila_primeiro(f1, &elemento);

    /**************************************
    * Teste remocao
    **************************************/
    fila_remover(f1, &elemento);
    fila_remover(f1, &elemento);  
    fila_remover(f1, &elemento); 
    bool resultado = fila_remover(f1, &elemento);
    fila_destruir(&f1);

       

    /**************************************
    * Teste inserir todos e clone
    **************************************/
    int vetor[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    f1 = fila_criar();
    fila_inserirTodos(f1, vetor, 12);
    fura_fila(f1, 54);
    fila_imprimir(f1, printInt);
    printf("\n");
}
