/*
4 - [L1E4] Faça um programa que contenha um menu com as seguintes opções: 
A - Ler uma string S1 (tamanho máximo 20 caracteres); 
B - Imprimir o tamanho da string S1; 
C - Comparar a string S1 com uma nova string S2 fornecida pelo usuário e imprimir o resultado da comparação; 
D - Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da concatenação;
E - Imprimir a string S1 de forma reversa; 
F - Contar quantas vezes um dado caractere aparece na string S1. Esse caractere desse ser informado pelo usuário; 
G - Substituir a primeira ocorrência do caractere C1 da string S1 pelo caractere C2. Os caracteres C1 e C2 serão digitados pelo usuário; 
H - Verificar se uma string S2 e substring de S1. A string S2 deve ser informada pelo usuário; 
I - Retornar uma substring da string S1. Para isso o usuário deve informar a partir de qual posição deve ser criada a substring e qual é o tamanho da substring.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int contains(char* string1, char* string2){

    int tamanho = strlen(string1);
    int tamanhoNova = strlen(string2);
    int found = 0;

    if ( tamanho >= tamanhoNova ) {
            for(int s=0, t=0; s<tamanho; s++){
                do {

                    if(string1[s] == string2[t] ){
                        if( ++found == tamanhoNova ){
                            return 1;
                        }
                        s++;
                        t++;
                    } else { 
                        s -= found; 
                        found=0; 
                        t=0; 
                    }

                } while(found);
            }
            return 0;
        } else 
            return -1;
}

int main(void){

    char opcao, charCount, subst;
    char s1[20];
    int tamanho, tamanhoE, inicio, fim, contadorDeCaracteres, tamanhoNova, found, posicao;
    int i = 0;
    char nova[20], reversa[20];
    int result;
    char novaD[20];
    char concat[40];
    
    printf("A - Ler uma string S1 (tamanho mÃ¡ximo 20 caracteres);\n");
    printf("Insira uma string atÃ© 20 caracteres \n");
    scanf(" %s", s1);
    
    printf("\nInsira uma opÃ§Ã£o: \n");
    printf("B - Imprimir o tamanho da string S1;\n");
    printf("C - Comparar a string S1 com uma nova string S2 fornecida pelo usuÃ¡rio e imprimir o resultado da comparaÃ§Ã£o;\n");
    printf("D - Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da concatenaÃ§Ã£o;\n");
    printf("E - Imprimir a string S1 de forma reversa;\n");
    printf("F - Contar quantas vezes um dado caractere aparece na string S1. Esse caractere desse ser informado pelo usuÃ¡rio;\n");
    printf("G - Substituir a primeira ocorrÃªncia do caractere C1 da string S1 pelo caractere C2. Os caracteres C1 e C2 serÃ£o digitados pelo usuÃ¡rio;\n");
    printf("H - Verificar se uma string S2 e substring de S1. A string S2 deve ser informada pelo usuÃ¡rio;\n");
    printf("I - Retornar uma substring da string S1. Para isso o usuÃ¡rio deve informar a partir de qual posiÃ§Ã£o deve ser criada a substring e qual Ã© o tamanho da substring.\n");

    scanf(" %c", &opcao);

    switch(opcao){
        case 'B':
        for (tamanho = 0; s1[tamanho] != '\0'; tamanho++);
        printf("O tamanho Ã© %i\n", tamanho);
        break;

        case 'C':
        printf("Insira uma nova string atÃ© 20 caracteres para comparar com a anterior \n");
        scanf(" %s", nova);
        result = strcmp(s1, nova);
        if (result == 0){
            printf("As strings sÃ£o iguais. \n");
        } else if (result < 0){
            printf("A string %s Ã© menor que a string %s \n", s1, nova);
        } else if (result > 0){ 
            printf("A string %s Ã© maior que a string %s \n", s1, nova);
        }         
        break;

        case 'D':
        printf("Insira uma nova string atÃ© 20 caracteres para concatenar com a anterior \n");
        scanf(" %s", novaD);
        strcat(concat, s1);
        strcat(concat, novaD);
        printf("String concatenada: %s\n",concat);
        break;

        case 'E':
        for (tamanhoE = 0; s1[tamanhoE] != '\0'; tamanhoE++);

        fim = tamanhoE - 1;

        for (inicio = 0; inicio < tamanhoE; inicio++) {
            reversa[inicio] = s1[fim];
            fim--;
        }

        reversa[inicio] = '\0';

        printf("String reversa: %s\n",reversa);
        break;

        case 'F':
        contadorDeCaracteres = 0;
        printf("Insira uma letra para buscar \n");
        scanf(" %c", &charCount);
        for (tamanho = 0; s1[tamanho] != '\0'; tamanho++)
            if (s1[tamanho] == charCount)
                contadorDeCaracteres++;

        printf("O caractere %c aparece %i vezes\n", charCount, contadorDeCaracteres);
        break;

        case 'G':
        contadorDeCaracteres = 0;
        printf("Insira uma letra para substituir \n");
        scanf(" %c", &charCount);

        printf("Insira por qual letra ela deve ser substituÃ­da \n");
        scanf(" %c", &subst);

        for (tamanho = 0; s1[tamanho] != '\0'; tamanho++)
            if(s1[tamanho] == charCount){
                s1[tamanho] = subst;
                break;
            }

        printf("A string ficou %s\n", s1);
        break;

        case 'H':
        printf("Insira uma nova string atÃ© 20 caracteres para verificar se Ã© substring \n");
        scanf(" %s", nova);

        result = contains(s1, nova);        
        
        if (result == 0){
            printf("A string %s nÃ£o foi encontrada na string %s\n", nova, s1);
        } else if (result == 1) { 
            printf("A string %s existe dentro da string %s\n", nova, s1);
        } else if (result == -1) { 
            printf("A string %s Ã© maior que a string %s\n", nova, s1);
        }


        break;

        case 'I':
        printf("Entre com a posiÃ§Ã£o da substring\n");
        scanf(" %d", &posicao);
        printf("Entre com o tamanho da substring\n");
        scanf(" %d", &tamanho);
        
        while (i < tamanho) {
            nova[i] = s1[posicao+i-1];
            i++;
        }
        nova[i] = '\0';
        
        printf("A substring Ã© \"%s\"\n", nova);
        break;

        default:
        printf("OpÃ§Ã£o invÃ¡lida. Encerrando programa.\n");
        break;
    }
    
    return 0;
}