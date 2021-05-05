#include "pilha.h"


/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *prox;
}No;

struct _pilha{
	No *topo;
	int qtdeElementos;
};



/**************************************
* FUNÇÕES AUXILIARES
**************************************/

bool pilha_ehValida(Pilha* p){
    return (p != NULL? true: false);    
}

No* criar_no(TipoElemento elemento, No* proximoNo){
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    no->prox = proximoNo;
    return no;
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/


Pilha* pilha_criar(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->qtdeElementos = 0;
    return p;
}


void pilha_destruir(Pilha* p){
    if(!pilha_ehValida(p)) return;

    No* aux;
    while(p->topo != NULL){
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
    
    free(p);
}

bool pilha_empilhar(Pilha* p, TipoElemento elemento){
    if(!pilha_ehValida(p)) return false;
    
    No* novo = criar_no(elemento, NULL);
    novo->prox = p->topo;
    p->topo = novo;
    p->qtdeElementos++;
    return true;


}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_ehValida(p)) return false;
    if(pilha_vazia(p)) return false;

    No* noRemovido = p->topo;
    p->topo = p->topo->prox;
    noRemovido->prox = NULL;
    p->qtdeElementos--;
    *saida = noRemovido->dado;
    free(noRemovido);

    return true;

}

bool pilha_topo(Pilha* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_ehValida(p)) return false;
    if(pilha_vazia(p)) return false;
    
    *saida = p->topo->dado;
    return true;

}

bool pilha_vazia(Pilha* p){
    return (p->qtdeElementos == 0? true: false);
}

void pilha_imprimir(Pilha* p, void (*printElemento)(void*)){
    if(!pilha_ehValida(p)) return;
    
    printf("Encadeada");
    printf("[");
    No* aux = p->topo;
    while(aux != NULL){
        printElemento(&aux->dado);
        if(aux->prox != NULL) printf(", ");
        aux = aux->prox;
    }
    printf("]");
}

int pilha_tamanho(Pilha* p){
    return p->qtdeElementos;
}

Pilha *pilha_clone(Pilha *p){
    Pilha *auxiliar = pilha_criar();
    Pilha *retorno = pilha_criar();
    char aux = 0;

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
    if (!pilha_ehValida(p)) return;
    if (pilha_vazia(p)) return;

    No *no_anterior = NULL;
    No *no_atual = p->topo;
    No *no_proximo = p->topo->prox;

    while (no_proximo != NULL){
        no_atual->prox = no_anterior;
        no_anterior = no_atual;
        no_atual = no_proximo;
        no_proximo = no_proximo->prox;
    }
    no_atual->prox = no_anterior;
    p->topo = no_atual;
}

bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor){
    if (!pilha_ehValida(p)) return false;
    if(tamVetor == 0) return false;

    for (int i = 0; i < tamVetor; i++){
        pilha_empilhar(p, vetor[i]);
    }

    return true;
}
