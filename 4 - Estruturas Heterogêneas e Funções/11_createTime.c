#include "stdio.h"

typedef struct{
   int hour, min, sec;
}Time; 

int createTime(int sec, Time *t){
   if(sec < 0 || t == NULL)
      return 1;

   t->hour = 0;
   t->min = 0;

   if (sec > 60){
      if (sec > 3600){
         t->hour = sec / 3600;
         sec = sec % 3600;
      }
      t->min = sec / 60;
      sec = sec % 60;
   }

   t->sec = sec;

   return 0;
}

int main (){

   Time t1;
   int resp1 = createTime(70000, NULL);
   printf("%d ", resp1);
   if (resp1 == 0)
      printf("%d:%d:%d\n",t1.hour, t1.min, t1.sec);

   Time t2;
   int resp2 = createTime(550, &t2);
   printf("%d ", resp2);
   if (resp2 == 0)
      printf("%d:%d:%d\n",t2.hour, t2.min, t2.sec);

   Time t3;
   int resp3 = createTime(-1, &t3);
   printf("%d ", resp3);

}