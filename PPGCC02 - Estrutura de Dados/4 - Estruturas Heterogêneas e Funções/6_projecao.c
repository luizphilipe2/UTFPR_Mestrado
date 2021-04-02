#include "stdio.h"
#include "string.h"

void projecao(int *x, int *y, int *z){
    if (*z == 0)
        return;

    *x = *x / *z;
    *y = *y / *z;
    *z = 1;
}

int main(){
   int x = 9, y = 8, z = 0;
   projecao(&x, &y, &z);
   printf("%d %d %d", x, y, z); //4 4 1

   x = 10, y = 5, z = 10;
   projecao(&x, &y, &z);
   printf("%d %d %d", x, y, z); // 1 0 1
}