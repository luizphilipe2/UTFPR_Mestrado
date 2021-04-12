#include "stdio.h"
#include<stdlib.h>
#include<string.h>

typedef struct{ 
    int numero;
    char modelo[100];
    char cor[100];
    float preco;
    int ano;
} Carro;


void adicionaCarro(Carro carro){
	FILE *arq = fopen("carroBD.txt", "a");

	if(arq != NULL){
		fwrite(&carro, sizeof(carro), 1, arq);
		fclose(arq); 
	} else	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
	}
}

Carro* pesquisa2014(){
    FILE *arq = fopen("carroBD.txt", "r");
    Carro carro;
    int tamanho = 1;
    Carro *carros = (Carro*) malloc(sizeof(Carro) * tamanho);

    while (fread(&carro, sizeof(Carro), 1, arq) == 1){
        if (carro.ano == 2014){
            carros[tamanho-1] = carro;
            tamanho++;
            carros = (Carro*) realloc(carros, sizeof(Carro) * tamanho);
        }
    }

    return carros;
}

Carro pesquisaNumero(int numero){
    FILE *arq = fopen("carroBD.txt", "r");
    Carro carro;

    while (fread(&carro, sizeof(Carro), 1, arq) == 1){
        if (carro.numero == numero){
            return carro;
        }
    }
}

int main(){
    Carro c = {10,"Fiat 147", "Branco", 1.990, 1985};
    //adicionaCarro(c);

    Carro d = {11,"Uno", "Branco", 1.990, 2014};
    //adicionaCarro(d);

    Carro e = {12,"Belina", "Branco", 1.990, 2014};
    //adicionaCarro(e);

    Carro f = pesquisaNumero(10);
    printf("Resultado da pesquisa por 10: %s \n", f.modelo);

    Carro *a = pesquisa2014();
    printf("Resultado da pesquisa por 2014: %s \n", a[0].modelo);
    printf("Resultado da pesquisa por 2014: %s \n", a[1].modelo);
}