#include "stdio.h"
int main(){

int a = 10;
int b = 20;
int c = 30;
int d = 40;
int *v[] = {&a, &b, &c, &d};
int **p = v;

printf("p = %p \n",p);
printf("*p = %p \n",*p);
printf("**p = %i \n",**p);
printf("p[1] = %p \n",p[1]);
printf("*p[1] = %i \n",*p[1]);
printf("**(p+2) = %i \n",**(p+2));
printf("v = %p \n",v);
printf("v[3] = %p \n",v[3]);
printf("v+3 = %p \n",v+3);
printf("*(v+3) = %p \n",*(v+3));
printf("**(v+3) = %i \n",**(v+3));


}