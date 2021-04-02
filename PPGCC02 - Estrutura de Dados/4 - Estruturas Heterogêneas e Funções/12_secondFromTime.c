#include "stdio.h"

typedef struct{
   int hour, min, sec;
}Time; 

int secondsFromTime(Time *t){
   if(t == NULL || t->hour < 0 || t->min < 0 || t->sec < 0)
      return -1;

   return (t->hour * 3600) + (t->min * 60) + t->sec;
}

int main (){

Time t1 = {10, 20, 49};
printf("%d\n",secondsFromTime(&t1));

Time t2 = {0, 20, 0};
printf("%d\n",secondsFromTime(&t2));

printf("%d\n",secondsFromTime(NULL));

}