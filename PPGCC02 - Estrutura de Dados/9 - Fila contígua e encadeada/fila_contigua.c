#include "fila.h"
#include "string.h"

#define TAM_INICIAL 5

/**************************************
* DADOS
**************************************/
struct _fila {
	TipoElemento* vetor;
	int tamVetor;
	int inicio;
	int fim;
	int qtdeElementos;
};


/**************************************
* FUNÃ‡Ã•ES AUXILIARES
**************************************/

bool fila_ehValida(Fila* f){
    return (f != NULL? true: false);
    
}

void realoca(Fila* f, int novoTamanho){
    TipoElemento* vetorAuxiliar = (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    int pos = f->inicio;

    for(i = 0; i < f->qtdeElementos; i++){
        vetorAuxiliar[i] = f->vetor[pos];
        pos = (pos+1) % f->tamVetor;
    }
    free(f->vetor);
    f->vetor = vetorAuxiliar;
    f->inicio = 0;
    f->fim = f->qtdeElementos;
    f->tamVetor = novoTamanho;
}

void verifica_aumenta(Fila* f){
    if(f->qtdeElementos == f->tamVetor - 1){ // precisamos deixar 1 posicao vazia entre o fim e o inicio
        realoca(f, f->tamVetor*2);
    }
}

void verifica_diminui(Fila* f){
    if (f->qtdeElementos <= f->tamVetor / 4 && f->tamVetor > TAM_INICIAL){
        realoca(f, f->tamVetor/2);
    }
}

int fila_tamVetor(Fila* f){
    return f->tamVetor;
}

/**************************************
* IMPLEMENTAÃ‡ÃƒO
**************************************/
Fila* fila_criar(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->vetor = (TipoElemento*) calloc(TAM_INICIAL, sizeof(TipoElemento));
    f->tamVetor = TAM_INICIAL;
    f->qtdeElementos = 0;
    f->inicio = f->fim = 0;
}

void fila_destruir(Fila** enderecoFila){
    if (enderecoFila == NULL) return;
    if(!fila_ehValida(*enderecoFila)) return;

    Fila* f = *enderecoFila;
    free(f->vetor);
    free(f);
    *enderecoFila = NULL;
}

bool fila_inserir(Fila* f, TipoElemento elemento){
    if(!fila_ehValida(f)) return false;

    verifica_aumenta(f);
    f->vetor[f->fim] = elemento;
    f->fim = (f->fim + 1) % f->tamVetor;
    f->qtdeElementos++;

    return true;
}

bool fila_remover(Fila* f, TipoElemento* saida){ // estratÃ©gia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    TipoElemento elemento = f->vetor[f->inicio];
    f->inicio = (f->inicio+1) % f->tamVetor;
    *saida = elemento;
    f->qtdeElementos--;
    verifica_diminui(f);
    
    return true;
}

bool fila_primeiro(Fila* f, TipoElemento* saida){ // estratÃ©gia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    *saida = f->vetor[f->inicio];
    return true;
}

bool fila_vazia(Fila* f){
    if(!fila_ehValida(f)) return true;

    return (f->qtdeElementos == 0 ? true : false);
}

int fila_tamanho(Fila* f){
    if(!fila_ehValida(f)) return 0;

    return f->qtdeElementos;
}

void fila_imprimir(Fila* f, void (*printElemento)(void*)){
    if(!fila_ehValida(f)) return;
    
    printf("Fila Contigua");
    printf("[");
    for (int i = f->inicio; i < f->fim; i++){
        printElemento(&f->vetor[i]);
        if(f->qtdeElementos-1 != i) printf(", ");
    }
    printf("]");
}

Fila *fila_clone(Fila *f){
    if (!fila_ehValida(f)) return NULL;
    Fila *f1 = fila_criar();
    
    for(int i = 0; i < f->qtdeElementos; i++){
        fila_inserir(f1, f->vetor[i]);
    }

    return f1;
}

void fila_inverter(Fila* f){
    if (!fila_ehValida(f)) return;
    if (fila_vazia(f)) return;

    int auxPosicao = f->fim-1;
    int auxDado = 0;

    for(int i = 0; i < auxPosicao; i++){
        auxDado = f->vetor[auxPosicao];
        f->vetor[auxPosicao] = f->vetor[i];
        f->vetor[i] = auxDado;
        auxPosicao--;
    }
}

bool fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor){
    if (!fila_ehValida(f)) return false;
    if(tamVetor == 0) return false;

    for (int i = 0; i < tamVetor; i++){
        fila_inserir(f, vetor[i]);
    }

    return true;
}

void fura_fila(Fila *f, TipoElemento elemento){
    if (!fila_ehValida(f)) return;

    if (f->qtdeElementos == f->tamVetor)
        verifica_aumenta(f);

    printf("Meu inicio é %i \n",f->inicio);    
    printf("Meu fim é %i \n",f->fim);
    f->inicio--;
    printf("Agora meu inicio é %i \n",f->inicio);
    f->fim--;

	if (f->inicio < 0)
		f->inicio = f->tamVetor-1;
	
    f->vetor[f->inicio] = elemento;
    f->qtdeElementos++;
}

