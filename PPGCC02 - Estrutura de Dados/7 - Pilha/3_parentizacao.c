/* Escreva um programa que utilize uma pilha para verificar se expressões aritméticas estão com a parentização correta. 
O programa deve verificar expressões para ver se cada "abre parênteses" tem um "fecha parênteses" correspondente.  
Assuma que a entrada será lida de um arquivo texto. Além de parênteses, são aceitos chaves {} e colchetes []. Veja os exemplos:

 Correto: ((12+12)*13) - ( (13/2 )*(9-8)+2) - (10+9)*(2^3)
 Correto: [(12+12)*13] - {[13/2]*(9-8)+2} - [10+9]*{2^3}
 Incorreto: [a+b]*(8*6}
 Incorreto: {a+b}*(8*6}
 Correto: {{{{{([9-9])}}}}}
 Incorreto: 3)(3 - (3*(3+0)+(3-3)+0)*9(0+9(-4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "pilha.h"

char* lerArquivo(FILE *file){
    char *conteudo;
    int tam = 0;
    char c = fgetc(file);
    while( (!feof(file))){
        if (tam == 0){
            tam = 1;
            conteudo = (char*)calloc(tam, sizeof(char));
        } else {
            tam++;
            conteudo = realloc(conteudo, tam*sizeof(char));
        }
        conteudo[tam-1] = c;
        c = fgetc(file);
    }
    fclose(file);
    return conteudo;
}

bool parentizacao_certa(char *string){
Pilha *p = pilha_criar();
char c;

    for (int i = 0; string[i] != '\0'; i++){        
        if (string[i] == '(' || string[i] == '[' || string[i] == '{'){
            pilha_empilhar(p, string[i]);
            printf("%c", string[i]);
        } else if (string[i] == ')' || string[i] == ']' || string[i] == '}') {
            if (pilha_vazia(p))
                return false;
            
            pilha_desempilhar(p, &c);
            printf("%c", string[i]);

            if (!((c == '(' && string[i] == ')') || 
                 (c == '[' && string[i] == ']') || 
                 (c == '{' && string[i] == '}')) )
                 return false;
        }
    }

    return pilha_vazia(p);
}

int main(){

char string[100] = {"((12+12)*13) - ( (13/2 )*(9-8)+2) - (10+9)*(2^3)"};
printf("%s \n", string);
printf("%s \n", parentizacao_certa(string) ? "true" : "false");

char string2[100] = {"[(12+12)*13] - {[13/2]*(9-8)+2} - [10+9]*{2^3}"};
printf("%s \n", string2);
printf("%s \n", parentizacao_certa(string2) ? "true" : "false");

char string3[100] = {"[a+b]*(8*6}"};
printf("%s \n", string3);
printf("%s \n", parentizacao_certa(string3) ? "true" : "false");

char string4[100] = {"{a+b}*(8*6}"};
printf("%s \n", string4);
printf("%s \n", parentizacao_certa(string4) ? "true" : "false");

char string5[100] = {"{{{{{([9-9])}}}}}"};
printf("%s \n", string5);
printf("%s \n", parentizacao_certa(string5) ? "true" : "false");

char string6[100] = {"3)(3 - (3*(3+0)+(3-3)+0)*9(0+9(-4"};
printf("%s \n", string6);
printf("%s \n", parentizacao_certa(string6) ? "true" : "false");

printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");

FILE *arq = fopen("exercicio3_parenteses.txt", "r");
char *texto = lerArquivo(arq);
printf("%s \n", parentizacao_certa(texto) ? "true" : "false");

}