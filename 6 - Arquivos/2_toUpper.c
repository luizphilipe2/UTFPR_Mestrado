#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    FILE *arquivo;
    int c;
    int erro=0;
   
    arquivo = fopen("entrada.txt","r+");
    if(arquivo == NULL){
        printf("\nNão foi possível abrir o arquivo de entrada!");
        erro=1;
    }

    if (!erro){
        c = fgetc(arquivo);
        while(!feof(arquivo)){
            fseek(arquivo, -1, SEEK_CUR);
            fputc(toupper(c),arquivo);
            c = fgetc(arquivo);
        }
    }
   
    fclose(arquivo);    
    return 0;
}
