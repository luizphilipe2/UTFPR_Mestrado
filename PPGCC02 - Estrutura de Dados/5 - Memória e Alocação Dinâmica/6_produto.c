#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
    unsigned int codigo;
    char nome[50];
    float preco;
} produto;

produto* adicionaProduto(int codigo, char* nome, float preco){
    produto* p = (produto*) malloc (sizeof(produto));

    p->codigo = codigo;
    strcpy(p->nome, nome);
    p->preco = preco;

    return p;
}

void imprimeProduto(produto *p){
    printf("Imprimindo o produto\n");
    printf("Código: %d\n", p->codigo);
    printf("Nome: %s\n", p->nome);
    printf("Preço: %.2lf\n", p->preco);
}

int main(){

    produto* p = adicionaProduto(1, "Nome 1", 9.90);
    imprimeProduto(p);

}