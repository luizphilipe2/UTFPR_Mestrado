/* Desenvolva uma função para transferir elementos de uma pilha P1 para uma pilha P2. 
Importante que P2 contenha os mesmos elementos na mesma ordem da P1. 
Esse exercício é diferente do exercício de  pilha_clone que você pode acessar os dados da pilha diretamente.
*/

#include <stdio.h>
#include "pilha.h"

Pilha* pilha_clone(Pilha* p){
    Pilha *auxiliar = pilha_criar();
    Pilha *retorno = pilha_criar();
    int aux = 0;

    while (!pilha_vazia(p)){
        pilha_desempilhar(p, &aux);
        pilha_empilhar(auxiliar, aux);
    }

    while (!pilha_vazia(auxiliar)){
        pilha_desempilhar(auxiliar, &aux);
        pilha_empilhar(retorno, aux);
        pilha_empilhar(p, aux);
    }

    pilha_destruir(auxiliar);
    return retorno;
}

void pilha_inverter(Pilha *p){
    Pilha *auxiliar = pilha_criar();
    Pilha *auxiliar2 = pilha_criar();
    int aux = 0;

    while (!pilha_vazia(p)){
        pilha_desempilhar(p, &aux);
        pilha_empilhar(auxiliar, aux);
    }

    while (!pilha_vazia(auxiliar)){
        pilha_desempilhar(auxiliar, &aux);
        pilha_empilhar(auxiliar2, aux);
    }
    
    while (!pilha_vazia(auxiliar2)){
        pilha_desempilhar(auxiliar2, &aux);
        pilha_empilhar(p, aux);
    }
}

bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor){
    for (int i = 0; i < tamVetor; i++){
        pilha_empilhar(p, vetor[i]);
    }
}

int main(){
    Pilha *p = pilha_criar();
    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);
    pilha_empilhar(p, 40);
    pilha_empilhar(p, 50);

    Pilha *p2 = pilha_clone(p);
    pilha_imprimir(p);
    printf("\n");
    pilha_imprimir(p2);
    printf("\n");

    pilha_inverter(p);
    pilha_imprimir(p);
    printf("\n");
    pilha_inverter(p2);
    pilha_imprimir(p2);
    printf("\n");

    int v8[8]={7,6,5,4,3,2,1,0};
    pilha_empilharTodos(p, v8, 8);
    pilha_imprimir(p);
    printf("\n");

    pilha_empilharTodos(p, v8, 8);
    pilha_imprimir(p);
    printf("\n");

}