#include "lista.h"



/**
 * INSERIR
 * Teste das funções anexar e inserir
*/
void teste_inserir(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE INSERIR \n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_imprimir(l);         // [10,20,30]
    printf("\n");

    // inicio
    lista_inserir(l, 5, 0);
    lista_inserir(l, 3, 0);
    lista_imprimir(l);         // [3,5,10,20,30]
    printf("\n");

    // fim
    lista_inserir(l, 40, 5);
    lista_inserir(l, 50, 6);
    
    // meio
    lista_inserir(l, 15, 3);
    lista_inserir(l, 45, 7);
    
    lista_imprimir(l);        // [3,5,10,15,20,30,40,45,50]
    printf("\n");
    
}

/**
 * REMOVER
 * Teste da função remover por posição
*/
void teste_removerPosicao(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE REMOVER POR POSICAO\n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);

    TipoElemento item;
  
    lista_imprimir(l);                    // [10,20,30,40,50]
    lista_removerPosicao(l, 0, &item);
    printf("\n");
    lista_imprimir(l);                    // [20,30,40,50]
    printf("\nRemovido: %d\n\n", item);   // Removido: 10

    lista_imprimir(l);                    //[20,30,40,50]
    lista_removerPosicao(l, 3, &item);
    printf("\n");
    lista_imprimir(l);                    // [20,30,40]
    printf("\nRemovido: %d\n\n", item);   // Removido: 50
    
    lista_imprimir(l);                    // [20,30,40]
    lista_removerPosicao(l, 1, &item);
    printf("\n");
    lista_imprimir(l);                    // [20,40]
    printf("\nRemovido: %d\n\n", item);   // Removido: 30

    lista_imprimir(l);                    // [20,40]
    lista_removerPosicao(l, -1, &item);
    printf("\n");
    lista_imprimir(l);                    // [20]
    printf("\nRemovido: %d\n\n", item);   // Removido: 40

    lista_imprimir(l);                    // [20]
    lista_removerPosicao(l, -1, &item);
    printf("\n");
    lista_imprimir(l);                    // []
    printf("\nRemovido: %d\n", item);     // Removido: 20
}

/**
 * REMOVER POR ELEMENTO
 * Teste da função remover por elemento
*/
void teste_removerElemento(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE REMOVER POR ELEMENTO\n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);

    int posicao;


    lista_imprimir(l);                             // [10,20,30,40,50]
    printf("\n");
    posicao = lista_removerElemento(l, 100);
    lista_imprimir(l);                             // [10,20,30,40,50]
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: -1


    lista_imprimir(l);                             // [10,20,30,40,50]
    printf("\n");
    posicao = lista_removerElemento(l, 10);
    lista_imprimir(l);                             // [20,30,40,50]
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: 0

    lista_imprimir(l);                             // [20,30,40,50]
    printf("\n");
    posicao = lista_removerElemento(l, 50);
    lista_imprimir(l);                             // [20,30,40]
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: 3

    lista_imprimir(l);                             // [20,30,40]
    printf("\n");
    posicao = lista_removerElemento(l, 30);
    lista_imprimir(l);                             // [20,40]
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: 1

    lista_imprimir(l);                             // [20,40]
    printf("\n");
    posicao = lista_removerElemento(l, 40);
    lista_imprimir(l);                             // [20]
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: 1

    lista_imprimir(l);                             // [20]
    printf("\n");
    posicao = lista_removerElemento(l, 20);
    lista_imprimir(l);                             // []
    printf("\nRemovido posicao: %d\n\n", posicao); // Removido posicao: 0

    lista_imprimir(l);                             // []
    printf("\n");
    posicao = lista_removerElemento(l, 40);
    lista_imprimir(l);                             // []
    printf("\nRemovido posicao: %d\n", posicao);   // Removido posicao: -1
}

void teste_toString(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE TO STRING\n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);

    char str[500];
    lista_toString(l, str); 
    printf("%s\n", str); // [10,20,30,40,50]
    
}

void teste_intercala(){
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);

    Lista* l2 = lista_criar();
    lista_anexar(l2, 10);
    lista_anexar(l2, 20);
    lista_anexar(l2, 30);
    lista_anexar(l2, 40);
    lista_anexar(l2, 50);

    Lista* l3 = intercala_lista(l, l2);
    char str[500];
    lista_toString(l3, str); 
    printf("%s\n", str); 
}

void teste_ehOrdenada(){
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);
    printf("%d \n", lista_ehOrdenada(l));

    Lista* l2 = lista_criar();
    lista_anexar(l2, 50);
    lista_anexar(l2, 40);
    lista_anexar(l2, 30);
    lista_anexar(l2, 20);
    lista_anexar(l2, 10);
    printf("%d \n", lista_ehOrdenada(l2));

    Lista* l3 = lista_criar();
    lista_anexar(l3, -50);
    lista_anexar(l3, -40);
    lista_anexar(l3, -30);
    lista_anexar(l3, -20);
    lista_anexar(l3, -10);
    printf("%d \n", lista_ehOrdenada(l3));

    Lista* l4 = lista_criar();
    lista_anexar(l4, -10);
    lista_anexar(l4, -20);
    lista_anexar(l4, -30);
    lista_anexar(l4, -40);
    lista_anexar(l4, -50);
    printf("%d \n", lista_ehOrdenada(l4));
}


int main(){

    printf("TESTES\n");

    // teste_inserir();
    // teste_removerPosicao();
    // teste_removerElemento();
    // teste_toString();
    teste_intercala();
    teste_ehOrdenada();

    

 

}