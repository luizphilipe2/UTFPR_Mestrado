#include <stdio.h>

#include "pilha.h"


/**
 * EMPILHAR
 * RESULTADO ESPERADO (Topo -> Base) 
 * [30,20,10]
*/
void teste_empilhar(){
    printf(">>> TESTE EMPILHAR\n");
    Pilha* p = pilha_criar();
    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);
    pilha_imprimir(p);
    printf("\n");
    pilha_destruir(p);
}

/**
 * DESEMPILHAR
 * RESULTADO ESPERADO
 * Removido: 30
 * Removido: 20
 * Removido: 10
 * Pilha vazia
*/
void teste_desempilhar(){
    printf(">>> TESTE DESEMPILHAR\n");
    Pilha* p = pilha_criar();
    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);

    int elemento;
    pilha_desempilhar(p, &elemento);
    printf("Removido: %d\n", elemento);
    pilha_desempilhar(p, &elemento);
    printf("Removido: %d\n", elemento);
    pilha_desempilhar(p, &elemento);
    printf("Removido: %d\n", elemento);

    int resultado = pilha_desempilhar(p, &elemento);
    if (!resultado) printf("Pilha vazia\n");

    pilha_destruir(p);
}

/**
 * TOPO
 * RESULTADO ESPERADO
 * Pilha vazia
 * Topo: 10
 * Topo: 20
 * Topo: 30
*/
void teste_topo(){
    printf(">>> TESTE TOPO\n");
    int elemento = 0;

    Pilha* p = pilha_criar();
    int resultado = pilha_topo(p, &elemento);
    if(!resultado) printf("Pilha vazia\n");

    pilha_empilhar(p, 10);
    pilha_topo(p, &elemento);
    printf("Topo: %d\n", elemento);
    
    pilha_empilhar(p, 20);
    pilha_topo(p, &elemento);
    printf("Topo: %d\n", elemento);

    pilha_empilhar(p, 30);
    pilha_topo(p, &elemento);
    printf("Topo: %d\n", elemento);

    
    pilha_destruir(p);
}

/**
 * TOPO
 * RESULTADO ESPERADO
 * [50,40,30,20,10]
 * [50,40,30,20,10]
*/
void teste_inverter(){
    printf(">>> TESTE INVERTER\n");
    Pilha* p = pilha_criar();
    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);
    pilha_empilhar(p, 40);
    pilha_empilhar(p, 50);
    pilha_imprimir(p);
    printf("\n");
    //pilha_inverter(p);
    pilha_imprimir(p);

    
    pilha_destruir(p);
}

int main(){
    teste_empilhar();
    printf("\n");

    teste_desempilhar();
    printf("\n");

    teste_topo();
    printf("\n");

    teste_inverter();
    printf("\n");

}