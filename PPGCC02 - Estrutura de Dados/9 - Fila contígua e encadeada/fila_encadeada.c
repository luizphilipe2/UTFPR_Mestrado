#include "fila.h"
#include "string.h"

#define TAM_INICIAL 5

/**************************************
* DADOS
**************************************/
typedef struct no{
    int dado;
    struct no* prox;
}No;

struct _fila {
    No* inicio;
    No* fim;
    int qtde;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/

bool fila_ehValida(Fila* f){
    return (f != NULL? true: false);   
}

No* novoNo(int valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/
Fila* fila_criar(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qtde = 0;
    return fila;
}

void fila_destruir(Fila** enderecoFila){
    if (enderecoFila == NULL) return;
    if(!fila_ehValida(*enderecoFila)) return;

    Fila* f = *enderecoFila;
    No* aux;
    while(f->inicio != NULL){
        aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);
    }
    free(f);
    *enderecoFila = NULL;
}

bool fila_inserir(Fila* f, TipoElemento elemento){
    if(!fila_ehValida(f)) return false;

    No* novo = novoNo(elemento);

    if(f->inicio == NULL){
        f->inicio = novo;        
    }else{
        f->fim->prox = novo;
    }
    f->fim = novo;    
    f->qtde++;

    return true;
}

bool fila_remover(Fila* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    No* aux = f->inicio;        
    f->inicio = f->inicio->prox;
    f->qtde--;
    *saida = aux->dado;
    free(aux);
    
    if(f->inicio == NULL){        
        f->fim = NULL;
    }
    
    return true;
}

bool fila_primeiro(Fila* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    *saida = f->inicio->dado;
    return true;
}

bool fila_vazia(Fila* f){
    if(!fila_ehValida(f)) return true;

    return (f->qtde == 0 ? true : false);
}

int fila_tamanho(Fila* f){
    if(!fila_ehValida(f)) return 0;

    return f->qtde;
}

void fila_imprimir(Fila* f, void (*printElemento)(void*)){
    if(!fila_ehValida(f)) return;
    
    printf("Fila Encadeada");
    printf("[");
    No* aux = f->inicio;
    while(aux != NULL){
        printElemento(&aux->dado);
        if(aux->prox != NULL) printf(", ");
        aux = aux->prox;
    }
    printf("]");
}

Fila *fila_clone(Fila *f){
    No *atual = NULL;
    Fila *f1 = fila_criar();
    
    if (!fila_vazia(f)){
        atual = f->inicio;
        fila_inserir(f1,atual->dado);
        printf("Inserindo dado %i: ", atual->dado);
    }    

    while (atual->prox != NULL){
        atual = atual->prox;
        fila_inserir(f1, atual->dado);
        printf("Inserindo dado %i: ", atual->dado);
    }

    return f1;
}

void fila_inverter(Fila* f){
    if (!fila_ehValida(f)) return;
    if (fila_vazia(f)) return;

    No *no_anterior = NULL;
    No *no_atual = f->inicio;
    No *no_proximo = f->inicio->prox;

    while (no_proximo != NULL){
        no_atual->prox = no_anterior;
        no_anterior = no_atual;
        no_atual = no_proximo;
        no_proximo = no_proximo->prox;
    }
    no_atual->prox = no_anterior;
    f->inicio = no_atual;
}

bool fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor){
    if (!fila_ehValida(f)) return false;
    if(tamVetor == 0) return false;

    for (int i = 0; i < tamVetor; i++){
        fila_inserir(f, vetor[i]);
    }

    return true;
}
