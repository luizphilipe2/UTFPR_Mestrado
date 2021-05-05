#include "fila.h"
#include "pilha.h"

void inverteFila(Fila *f1){
    Pilha *p = pilha_criar();

    while (!fila_vazia(f1)){
        if(fila_tamanho(f1) > 0){
            TipoElemento dado;
            fila_primeiro(f1, &dado);
            pilha_empilhar(p, dado);
            fila_remover(f1, &dado);
        }
    }

    while (!pilha_vazia(p)){
        TipoElemento dado; 
        pilha_desempilhar(p, &dado);
        fila_inserir(f1, dado);
    }
}

void printInt(void *n){
    int* p = n;
    printf("%i", *p);
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

    inverteFila(f1);
    fila_imprimir(f1, printInt);
}