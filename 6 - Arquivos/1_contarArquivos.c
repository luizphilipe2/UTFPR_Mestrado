#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int contarLetraA(FILE *file){

char linha[100];
char c;
int char_a = 0;

  while (!feof(file)){
      c = fgetc(file);

      if (c == 65 || c == 97)
        char_a++;
  }
  fclose(file);

return char_a;

}

int contarSubstring(FILE *file, char *str){

}

int main() {  

}