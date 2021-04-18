#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<ctype.h>

int getArrayFromFile(FILE *file, int** vet){
    char caractere = fgetc(file);
    int tamanho = 0;
    int temp = atoi(&caractere);
    
    while(!feof(file) && (caractere != ' ') && (caractere != '\n')){
        tamanho = (tamanho*10) + temp;
        caractere = fgetc(file);
        temp = atoi(&caractere);
    }

    *vet = (int*)calloc(tamanho, sizeof(int));

    caractere = fgetc(file);
    for(int i = 0; i < tamanho; i++){
        temp = atoi(&caractere);
        while(!feof(file) && (caractere != ' ') && (caractere != '\n')){
            int aux = *(*vet+i);
            *(*vet+i) = (aux * 10) + temp;
            caractere = fgetc(file);
            temp = atoi(&caractere);
        }
        caractere = fgetc(file);
    }
    return tamanho;
}

void troca(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int sort_array(int *vet, int tam){
    int i, j, min;
    for (i = 0; i < tam - 1; i++) {
        min = i;
        for (j = i + 1; j < tam; j++)
            if (vet[j] < vet[min])
                min = j;
 
        troca(&vet[min], &vet[i]);
    }
}

void escreve_array(int *vet, int tam, FILE *file){
    char *numero = calloc(tam, sizeof(tam));
    sprintf(numero, "%d", tam);
    fputs(numero, file);
    fputs("\n", file);

    for (int i = 0; i < tam; i++){
        sprintf(numero, "%d", vet[i]);
        fputs(numero, file);
        fputs(" ", file);
    }
}

void main(){
   FILE* source = fopen("exercicio3_entrada.txt","r");
   
    if(source == NULL) {
        printf("Error number: %d\n", errno);    
        printf("Msg: %s\n", strerror(errno ));    
    }
    
    int *v;
    int tam = getArrayFromFile(source, &v);

    fclose(source);

    sort_array(v, tam);

    FILE* target = fopen("exercicio3_saida.txt","w");
    escreve_array(v, tam, target);
    fclose(target);
}