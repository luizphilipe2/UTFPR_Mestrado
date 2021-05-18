#include "lista.h"
#include "string.h"

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *ant;
	struct no    *prox;
}No;

struct lista{
	No *sentinela;
	int qtde;
};


/**************************************
* FUNÇÕES AUXILIARES
**************************************/
No* criar_no(TipoElemento elemento){
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    return no;
}

No* criar_noSentinela(){
    No* no = (No*) malloc(sizeof(No));
    no->ant = no;
    no->prox = no;
    return no;
}

bool lista_ehValida(Lista* l){
    return (l != NULL? true: false);    
}

bool posicao_ehValida(Lista* l, int pos){
    if(pos < 0) return false;
    if(pos > l->qtde) return false;

    return true;
}

bool posicao_ehPreenchida(Lista* l, int pos){
    if(pos < 0) return false;
    if(pos >= l->qtde) return false;

    return true;
}

int converte_posicao(Lista* l, int pos){
    return (pos < 0? l->qtde + pos : pos);
}

No* devolve_enderecoNo(Lista* l, int pos){
    No* aux = l->sentinela;
    int i;
    for(i=0; i <= pos; i++) 
        aux = aux->prox;
    return aux;
}

void insere_direita(No* referencia, No* novo){
    novo->ant = referencia;
    novo->prox = referencia->prox;

    referencia->prox->ant = novo;
    referencia->prox = novo;
}

void desconecta_no(No* no){
    no->prox->ant = no->ant;
    no->ant->prox = no->prox;
    no->ant = no->prox = NULL;
}


/**************************************
* IMPLEMENTAÇÃO
**************************************/

Lista* lista_criar(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->sentinela = criar_noSentinela();
    lista->qtde = 0;
    return lista;
}

void lista_destruir(Lista** endLista){
    Lista* l = *endLista;
    No* aux;
    while(l->sentinela->prox != l->sentinela){
        aux = l->sentinela->prox;
        l->sentinela = l->sentinela->prox;
        free(aux);
    }
    free(l->sentinela);
    free(l);
    *endLista = NULL;
}

bool lista_anexar(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    lista_inserir(l, elemento, l->qtde);

    return true;
}

bool lista_inserir(Lista* l, TipoElemento elemento, int posicao){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehValida(l, posicao)) return false;
    
    No* novo = criar_no(elemento);
    No* aux = devolve_enderecoNo(l, posicao-1);

    insere_direita(aux, novo);

    l->qtde++;
    return true;

}

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehPreenchida(l, posicao)) return false;
    

    No* aux = devolve_enderecoNo(l, posicao);
    desconecta_no(aux);
    *endereco = aux->dado;
    free(aux);
    l->qtde--;
    return true;
}

int lista_removerElemento(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    int posicao = lista_posicao(l, elemento);
    if(posicao == -1) return -1;
    
    TipoElemento item;
    lista_removerPosicao(l, posicao, &item);
    return posicao;
}

bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehPreenchida(l, posicao)) return false;

    No* no = devolve_enderecoNo(l, posicao);
    no->dado = novoElemento;
    return true;
}

bool lista_vazia(Lista* l){
    if(!lista_ehValida(l)) return true;

    return (l->qtde == 0 ? true : false);
}

int lista_posicao(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return -1;

    int i = 0;
    No* aux = l->sentinela->prox;
    while(aux != l->sentinela){
        if(elemento == aux->dado) return i;
        aux = aux->prox;
        i++;
    }
    return -1;

}

bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehPreenchida(l, posicao)) return false;

    No* no = devolve_enderecoNo(l, posicao);
    *endereco = no->dado;
    return true;

    
}
bool lista_contem(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    int posicao = lista_posicao(l, elemento);
    return (posicao != -1? true : false);

}
int lista_tamanho(Lista* l){
    if(!lista_ehValida(l)) return -1;

    return l->qtde;
}

bool lista_toString(Lista* l, char* str){
    if(!lista_ehValida(l)) return false;

    int qtde = 0;
    char elemento[20];

    str[0] = '\0';
    strcat(str, "[");
    No* aux = l->sentinela->prox;
    while(aux != l->sentinela){
        sprintf(elemento, FORMATO, aux->dado);
        strcat(str, elemento);
        
        if(aux->prox != l->sentinela) strcat(str, ",");
            
        aux = aux->prox;
    }
    strcat(str, "]");
    return true;
}

void lista_imprimir(Lista* l){
    if(!lista_ehValida(l)) return;

    printf("[");
    No* aux = l->sentinela->prox;
    while(aux != l->sentinela){
        printf(FORMATO, aux->dado);
        if(aux->prox != l->sentinela) printf(", ");
        aux = aux->prox;
    }
    printf("]");
}

Lista* intercala_lista(Lista* l1, Lista* l2){
    if(!lista_ehValida(l1) || !lista_ehValida(l2)) return NULL;
    Lista *l3 = lista_criar();

    while (!lista_vazia(l1) || !lista_vazia(l2)){
        int dado;
        if(lista_tamanho(l1) > 0){
            lista_removerPosicao(l1, 0, &dado);
            lista_anexar(l3, dado);
        }

        if(lista_tamanho(l2) > 0){
            lista_removerPosicao(l2, 0, &dado);
            lista_anexar(l3, dado);
        }
    }
    return l3;
}

bool lista_ehOrdenada(Lista* l){
    if(!lista_ehValida(l)) return false;
    if(l->qtde<=0) return false;

    No* aux = l->sentinela->prox;
    int count = 0;
    int dado_inicial = 0; 

    while(aux != l->sentinela){
        if (dado_inicial != 0){
            if (dado_inicial > aux->dado)
                count++;
            else if (dado_inicial < aux->dado)
                count--;
        }
        
        dado_inicial = aux->dado;
        aux = aux->prox;
    }

    if (((lista_tamanho(l)-1) == count) || ((lista_tamanho(l)-1) == count*-1))
        return true;

    return false;
}
