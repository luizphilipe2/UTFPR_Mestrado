#include "stdio.h"
int main(){

int m[4][2] = {{1,2},
               {3,4},
               {5,6},
               {7,8}};
int *p = m[0];
int *w = m[3];

printf("m = %p \n", m);
printf("m[0] = %p \n", m[0]);
printf("p = %p \n", p);
printf("m+1 = %p \n", m+1);
printf("m[1] = %p \n", m[1]);
printf("p + 3 = %p \n", p + 3);
printf("m[0][0] = %i \n", m[0][0]);
printf("*m[0] = %i \n", *m[0]);
printf("*p = %i \n", *p);
printf("p[0] = %i \n", p[0]);
printf("m[3][1] = %i \n", m[3][1]);
printf("*(m[3] + 1) = %i \n", *(m[3] + 1));
printf("*(p+(3*2)+1) = %i \n", *(p+(3*2)+1));
printf("w[1] = %i \n", w[1]);
printf("*(w+1) = %i \n", *(w+1));

}