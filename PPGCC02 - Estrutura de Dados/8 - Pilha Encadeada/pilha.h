#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int TipoElemento;

typedef struct _pilha Pilha;

Pilha* pilha_criar();
void pilha_destruir(Pilha* p);
void pilha_destruir_v2(Pilha** p);

bool pilha_empilhar(Pilha* p, TipoElemento elemento);
bool pilha_desempilhar(Pilha* p, TipoElemento* saida); 
bool pilha_topo(Pilha* p, TipoElemento* saida); 
bool pilha_vazia(Pilha* p);
void pilha_imprimir(Pilha* p, void (*printElemento)(void*));
int pilha_tamanho(Pilha* p);

//Implementar como exercicio.
Pilha* pilha_clone(Pilha* p);
void pilha_inverter(Pilha* p);
bool pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor);