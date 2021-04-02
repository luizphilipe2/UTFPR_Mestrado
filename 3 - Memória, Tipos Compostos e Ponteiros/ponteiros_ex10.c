#include "stdio.h"
int main(){

int v[4] = {1,2,3,4};
int *p = v;
int *w = &v[2];
int i = 30;
int *x = &i;

printf("p	=%p \n" ,p	);
printf("v	=%p \n" ,v	);
printf("&v[0]=%p \n" ,&v[0]);
printf("v+1=%p \n" ,v+1);
printf("*(v+2)=%i \n" ,*(v+2));
printf("w=%p \n" ,w);
printf("*w=%i \n" ,*w);
printf("w[1]=%i \n" ,w[1]);
printf("x=%p \n" ,x);
printf("&x=%p \n" ,&x);
printf("*x=%i \n" ,*x);
printf("x[0]=%i \n" ,x[0]);
printf("p + 3=%p \n" ,p + 3);
printf("&p[3]=%p \n" ,&p[3]);
printf("*(p+3)=%i \n" ,*(p+3));
printf("p[3]=%i \n" ,p[3]);


}