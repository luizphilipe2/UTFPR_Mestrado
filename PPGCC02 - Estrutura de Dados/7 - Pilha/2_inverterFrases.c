/* Escreva um algoritmo, usando a implementação da pilha contígua, que inverte as letras de cada palavra de um texto terminado por ponto (.) 
preservando a ordem das palavras. Por exemplo, dado o texto: 

MESTRADO EM CIENCIA DA COMPUTACAO. 

 A saÍda deve ser: 

ODARTSEM ME AICNEIC AD OACATUPMOC.
*/

#include <stdio.h>
#include "pilha.h"

void pilha_desempilha_todos(Pilha *p){
    char c;
    while (!pilha_vazia(p)){
        pilha_desempilhar(p, &c);
        printf("%c", c);
    }
}

void inveterPalavrasEmFrases(char *string){
    Pilha *p = pilha_criar();

    for (int i = 0; string[i] != '\0'; i++){        
        if (string[i] == ' ' || string[i] == '.'){
            pilha_desempilha_todos(p);
            printf("%c", string[i]);
        } else {
            pilha_empilhar(p, string[i]);
        }
    }
}

int main(){
    char string[100] = {"MESTRADO EM CIENCIA DA COMPUTACAO."};
    inveterPalavrasEmFrases(string);
}