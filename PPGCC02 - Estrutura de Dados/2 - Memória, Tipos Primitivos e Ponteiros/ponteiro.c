#include<stdio.h>
#include<stdlib.h>

// int fib(int n) {                                          
//      int i, fib1 = 1, fib2 = 1, soma;         
//      for (i = 3; i <= n; i = i + 1)           
//      {                                        
//        soma = fib1 + fib2;                    
//        fib1 = fib2;                           
//        fib2 = soma;                           
//      }                                        
//      return fib2;                             
//    }  

//    int soma = 0;
//    int fibo = 0;

int main(void){
     
  //    for(int i = 1; i <= 213213; i++){
  //        fibo = fib(i);
  //        if (fibo % 2 == 0){
  //            soma += fibo;
  //        }

  //        if (fibo >= 4000000){
  //            break;
  //        }
  //    }

  //  printf("%i ", soma);



    // int i=3, j=5;
    // int *p=&i, *q=&j;

    // if (p==&i){
    //     printf("true");
    // } else {
    //     printf("false");
    // }
    // // printf("%B ", t);

    
//      int i=3, j=5;
//  int *p=&i, *q=&j;

// int luiz = *p-*q;

//    int x, y, *p;
// y = 0;
// p = &y;
// x = *p;
// x = 4;
// (*p)++;
// --x;
// (*p) += x;
// printf("x=%d y=%d *p=%d", x, y, *p);

// int vet[10];
// int *p;


// printf("%p \n", &vet[0]);

// p = vet;
// printf("%p \n", p);

// p = vet+3;
// printf("%p", p);

// int v[4] = {10, 20, 30, 40};
// int *w = &v[2];
// int *p = &v[0];
// int i = 30;
// int *x = &i;



// printf("%i \n", w[1]);
// printf("%p \n", v);


// printf("%i \n", V1+2);
// printf("%i \n", *(V1+2));
// // printf("%i \n", V1+3);
// printf("%i \n", *(V1+3));
// printf("%i \n", (*V1)+3);

// printf("%p \n", V1);
// printf("%p \n", V1+1);




int m[4][2] = 
{{1,2}, 
{3,4},
{5,6},
{7,8}} 
;

int *p = m[0];
int *w = m[3];

// int *v1[] = &m[0][0];
// int *v2[] = &m[1][0];


printf("%i \n", *(p+(3*2)+1));
printf("%p \n", m);
printf("%p \n", m+1);
printf("%p \n", &m[1][0]);
printf("%p \n", m[1]);
printf("%p \n", p);
printf("%p \n", p+3);

for(int i = 0; i < 4; i++){
  for(int j = 0; j < 2; j++){
    printf("i: %i, j: %i - ponteiro: %p \n", i, j, &m[i][j]);
  }
}

printf("%i \n", *(w+1));


}