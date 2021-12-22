#include "arvore_binaria.h"


/**************************************
* DADOS
**************************************/

struct no{
  TipoElemento dado;
  struct no *esq, *dir;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/
No *filhoDaDireita(No **no){
    if((*no)->dir != NULL)
        return filhoDaDireita(&(*no)->dir);
    else{
        No *aux1 = *no;        
        if((*no)->esq != NULL)
            *no = (*no)->esq;
        else
            *no = NULL;
    return aux1;
    }
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/

void ab_destruir(No **enderecoRaiz){
    if (*enderecoRaiz != NULL){
        ab_destruir(&(*enderecoRaiz)->dir);
        ab_destruir(&(*enderecoRaiz)->esq);
        free(*enderecoRaiz);
    }
    return;
}

bool ab_inserir(No **enderecoRaiz, TipoElemento elemento){
     printf("inserindo: %d\n", elemento);
    while(*enderecoRaiz) {
        if ((*enderecoRaiz)->dado == elemento)
            return false;
        if ((*enderecoRaiz)->dado > elemento)
            enderecoRaiz = &((*enderecoRaiz)->esq);
        else
            enderecoRaiz = &((*enderecoRaiz)->dir);
    }
	if (!(*enderecoRaiz = (struct no*)malloc(sizeof(struct no))))
		return false;
	(*enderecoRaiz)->dado = elemento;
	(*enderecoRaiz)->esq = NULL;
	(*enderecoRaiz)->dir = NULL;
	return true;
}

bool ab_remover(No** enderecoRaiz, TipoElemento dado){
         if(*enderecoRaiz == NULL){
            printf("\nNumero nao existe na arvore.\n");
            return false;
        }                                                        
        if(dado < (*enderecoRaiz)->dado){
            ab_remover(&(*enderecoRaiz)->esq, dado);
        } else { 
            if(dado > (*enderecoRaiz)->dado){ 
                ab_remover(&(*enderecoRaiz)->dir, dado);
            } else {
                  No *aux2 = *enderecoRaiz;
                    if (((*enderecoRaiz)->esq == NULL) && ((*enderecoRaiz)->dir == NULL)){
                        free(aux2);
                        (*enderecoRaiz) = NULL;
                    }
                    else{
                        if ((*enderecoRaiz)->esq == NULL){
                            (*enderecoRaiz) = (*enderecoRaiz)->dir;
                            aux2->dir = NULL;
                            free(aux2);
                            aux2 = NULL;
                        }
                        else{
                            if ((*enderecoRaiz)->dir == NULL){
                                (*enderecoRaiz) = (*enderecoRaiz)->esq;
                                aux2->esq = NULL;
                                free(aux2);
                                aux2 = NULL;
                            }
                        else{
                            aux2 = filhoDaDireita(&(*enderecoRaiz)->esq);
                            aux2->esq = (*enderecoRaiz)->esq;
                            aux2->dir = (*enderecoRaiz)->dir;
                            (*enderecoRaiz)->esq = NULL;
                            (*enderecoRaiz)->dir = NULL;
                            free((*enderecoRaiz));
                            *enderecoRaiz = aux2;
                            aux2 = NULL;
                        }
                    }
                }
            }
        }
}

void ab_pre_ordem(No* raiz){
    if (raiz != NULL) {
        printf("%d\n", raiz->dado);
        ab_pre_ordem(raiz->esq);
        ab_pre_ordem(raiz->dir);
    }
    else
        return;
}

void ab_em_ordem(No* raiz){
    if(raiz != NULL) {
        ab_em_ordem(raiz->esq);
        printf("%d\n", raiz->dado);
        ab_em_ordem(raiz->dir);
    }
    else
        return;
}

void ab_pos_ordem(No* raiz){
    if(raiz != NULL) {
        ab_pos_ordem(raiz->esq);
        ab_pos_ordem(raiz->dir);
        printf("%d\n",raiz->dado);
    }
    else
        return;
}

int ab_altura(No *raiz){
    if (raiz == NULL)
        return -1;
    int he = ab_altura(raiz->esq);
    int hd = ab_altura(raiz->dir);
    return (he<hd) ? hd+1 : he+1;
}

int ab_total_vertices(No *raiz){
    int soma;
    if (raiz==NULL) 
        return 0;
    soma = 1;
	return soma + ab_total_vertices(raiz->dir) + ab_total_vertices(raiz->esq);
}

bool ab_consulta(No* raiz, TipoElemento dado){
		while (raiz) {
		printf("Procurando por %d, olhando em %d\n", dado, raiz->dado);
		if (raiz->dado == dado)
			return true;
		if (raiz->dado < dado)
			raiz = raiz->dir;
		else
			raiz = raiz->esq;
	}

	return false;
}