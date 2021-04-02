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
    
    printf("A - Ler uma string S1 (tamanho máximo 20 caracteres);\n");
    printf("Insira uma string até 20 caracteres \n");
    scanf(" %s", s1);
    
    printf("\nInsira uma opção: \n");
    printf("B - Imprimir o tamanho da string S1;\n");
    printf("C - Comparar a string S1 com uma nova string S2 fornecida pelo usuário e imprimir o resultado da comparação;\n");
    printf("D - Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da concatenação;\n");
    printf("E - Imprimir a string S1 de forma reversa;\n");
    printf("F - Contar quantas vezes um dado caractere aparece na string S1. Esse caractere desse ser informado pelo usuário;\n");
    printf("G - Substituir a primeira ocorrência do caractere C1 da string S1 pelo caractere C2. Os caracteres C1 e C2 serão digitados pelo usuário;\n");
    printf("H - Verificar se uma string S2 e substring de S1. A string S2 deve ser informada pelo usuário;\n");
    printf("I - Retornar uma substring da string S1. Para isso o usuário deve informar a partir de qual posição deve ser criada a substring e qual é o tamanho da substring.\n");

    scanf(" %c", &opcao);

    switch(opcao){
        case 'B':
        for (tamanho = 0; s1[tamanho] != '\0'; tamanho++);
        printf("O tamanho é %i\n", tamanho);
        break;

        case 'C':
        printf("Insira uma nova string até 20 caracteres para comparar com a anterior \n");
        scanf(" %s", nova);
        result = strcmp(s1, nova);
        if (result == 0){
            printf("As strings são iguais. \n");
        } else if (result < 0){
            printf("A string %s é menor que a string %s \n", s1, nova);
        } else if (result > 0){ 
            printf("A string %s é maior que a string %s \n", s1, nova);
        }         
        break;

        case 'D':
        printf("Insira uma nova string até 20 caracteres para concatenar com a anterior \n");
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

        printf("Insira por qual letra ela deve ser substituída \n");
        scanf(" %c", &subst);

        for (tamanho = 0; s1[tamanho] != '\0'; tamanho++)
            if(s1[tamanho] == charCount){
                s1[tamanho] = subst;
                break;
            }

        printf("A string ficou %s\n", s1);
        break;

        case 'H':
        printf("Insira uma nova string até 20 caracteres para verificar se é substring \n");
        scanf(" %s", nova);

        result = contains(s1, nova);        
        
        if (result == 0){
            printf("A string %s não foi encontrada na string %s\n", nova, s1);
        } else if (result == 1) { 
            printf("A string %s existe dentro da string %s\n", nova, s1);
        } else if (result == -1) { 
            printf("A string %s é maior que a string %s\n", nova, s1);
        }


        break;

        case 'I':
        printf("Entre com a posição da substring\n");
        scanf(" %d", &posicao);
        printf("Entre com o tamanho da substring\n");
        scanf(" %d", &tamanho);
        
        while (i < tamanho) {
            nova[i] = s1[posicao+i-1];
            i++;
        }
        nova[i] = '\0';
        
        printf("A substring é \"%s\"\n", nova);
        break;

        default:
        printf("Opção inválida. Encerrando programa.\n");
        break;
    }
    
    return 0;
}