#include "stdio.h"
typedef struct{ 
   int x;  
   int y;
} T; /*Definição de um tipo complexo T, composto dos elementos x e y que são inteiros*/

void f1(T*a); /*Declaração da função f1, que recebe um ponteiro de um tipo complexo T como parâmetro*/

void f2(int*b); /*Declaração da função f2, que recebe um ponteiro de inteiro como parâmetro*/


int main(){
   T a, b,*c,*d;
   c = &a; /*Atribuindo ao ponteiro c do tipo complexo T, a posição de memória da variável a*/
   a.x = 2; /*Atribuindo o valor 2 dentro do atributo x, de dentro do tipo complexo T da variável a*/
   a.y = 4; /*Atribuindo o valor 4 dentro do atributo y, de dentro do tipo complexo T da variável a*/
   b.x = 2; /*Atribuindo o valor 2 dentro do atributo x, de dentro do tipo complexo T da variável b*/
   b.y = 2; /*Atribuindo o valor 2 dentro do atributo y, de dentro do tipo complexo T da variável b*/
   d = c; /* */
   f1(d); /* */
   b =*d; /* */
   printf("x: %d --- y: %d\n",b.x,b.y); /* */
}

void f1(T *a){ /* */
   f2(&(a->x)); /* */
   f2(&(a->y)); /* */
}

void f2(int*b){ /* */
   *b = 2*(*b); /* */
} 