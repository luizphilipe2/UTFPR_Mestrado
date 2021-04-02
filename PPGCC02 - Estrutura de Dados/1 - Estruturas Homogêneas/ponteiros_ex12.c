#include "stdio.h"
int main(){

int v1[] = {1,2,3};
int v2[] = {4,5,6};
int *p1 = v1;
int *p2 = v2;
int *m[] = {v1, v2};
int **pm = m;

printf("p1=%p \n",p1);
printf("v1=%p \n",v1);
printf("p1+2=%p \n",p1+2);
printf("v1+2=%p \n",v1+2);
printf("p2[1]=%i \n",p2[1]);
printf("*(v2+1)=%i \n",*(v2+1));
printf("m=%p \n",m);
printf("*m=%p \n",*m);
printf("pm=%p \n",pm);
printf("*pm=%p \n",*pm);
printf("m[0]=%p \n",m[0]);
printf("*(m+1)=%p \n",*(m+1));
printf("*pm[1]=%i \n",*pm[1]);
printf("**(m+1)=%i \n",**(m+1));
printf("m[0][2]=%i \n",m[0][2]);
printf("pm=%p \n",pm);
printf("pm+1=%p \n",pm+1);
printf("*(pm+1)=%p \n",*(pm+1));
printf("*(pm+1) + 2=%p \n",*(pm+1) + 2);
printf("*(*(pm+1) + 2)=%i \n",*(*(pm+1) + 2));

}