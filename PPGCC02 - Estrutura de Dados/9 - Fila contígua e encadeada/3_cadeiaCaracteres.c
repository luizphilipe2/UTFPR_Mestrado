#include "fila.h"
#include "pilha.h"
#include<string.h>
#include<ctype.h>

char* letrasSequenciaNumerosInversos(char *string){
    Pilha *p = pilha_criar();
    Fila *f = fila_criar();

    for (int i = 0; i < strlen(string); i++){
        if (isalpha(string[i]))
            fila_inserir(f, string[i]);
        
        if (isdigit(string[i]))
            pilha_empilhar(p, string[i]);
    }

    int posicao_atual = 0;
    char dado;
    while (!fila_vazia(f)){
        if(fila_tamanho(f) > 0){
            fila_primeiro(f, &dado);
            fila_remover(f, &dado);
            string[posicao_atual] = dado;
            posicao_atual++;
        }
    }

    while (!pilha_vazia(p)){
        pilha_desempilhar(p, &dado);
        string[posicao_atual] = dado;
        posicao_atual++;
    }
    
    return string;
}


int main(){
    char texto[] = "M1E5T7R8A8D80";
    printf("%s", letrasSequenciaNumerosInversos(texto));
    printf("\n");

    char texto2[] = "C9H4Q6";
    printf("%s", letrasSequenciaNumerosInversos(texto2));
    printf("\n");   
    
}