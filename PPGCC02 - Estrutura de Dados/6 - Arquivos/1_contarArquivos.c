#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int contarLetraA(FILE *file){
    char linha[100];
    char c;
    int char_a = 0;

    while (!feof(file)){
        c = fgetc(file);
        if (c == 65 || c == 97)
            char_a++;
    }

    fclose(file);
    return char_a;
}

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

int contarSubstring(FILE *file, char *str){
    char *texto = lerArquivo(file);
    int tamanhoBusca = strlen(str);
    int count = 0;
    char *ondeEncontrou = texto;

    if (tamanhoBusca > 0){
        while((ondeEncontrou = strstr(ondeEncontrou, str))){
            ondeEncontrou += tamanhoBusca;
            count++;
        }
    }

    return count;
}

int main() {  
    FILE *arq = fopen("exercicio1.txt", "r");
    printf("O arquivo exercicio1.txt possui %i letras A, desconsiderando maiúsculas e minúsculas\n", contarLetraA(arq));
    arq = fopen("exercicio1.txt", "r");
    printf("A palavra string aparece no arquivo exercício1.txt %i vezes.\n", contarSubstring(arq, "string"));


}