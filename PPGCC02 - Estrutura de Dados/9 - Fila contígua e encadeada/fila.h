#ifndef _FILA_H_
#define _FILA_H_

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct _fila Fila;

/**************************************
* PROTÓTIPOS
**************************************/
Fila* fila_criar();
void fila_destruir(Fila** enderecoFila);
bool fila_inserir(Fila* f, TipoElemento elemento);
bool fila_remover(Fila* f, TipoElemento* saida); // estratégia do scanf
bool fila_primeiro(Fila* f, TipoElemento* saida); // estratégia do scanf
bool fila_vazia(Fila* f);
int fila_tamanho(Fila* f);
void fila_inverter(Fila* f);
void fila_imprimir(Fila* f, void (*printElemento)(void*));
Fila* fila_clone(Fila* f);
bool fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor);
void fura_fila(Fila *f, TipoElemento elemento);

#endif
