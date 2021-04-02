#include "stdio.h"


int swapLines(int *m, int lines, int columns, int i1, int i2){
    if (m == NULL || i1 >= lines || i2 >= lines)
        return 1;

    int temp;
    for (int i = 0; i < columns; i++){
        temp = *(m + (i1 * columns) + i);
        *(m+(i1*columns)+i) = *(m+(i2 *columns)+i);
        *(m+(i2*columns)+i) = temp;
    }
}


int main(){

int m[10][10] = {{0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1},
	 	{2,2,2,2,2,2,2,2,2,2},
	 	{3,3,3,3,3,3,3,3,3,3},
	 	{4,4,4,4,4,4,4,4,4,4},
	 	{5,5,5,5,5,5,5,5,5,5},
	 	{6,6,6,6,6,6,6,6,6,6},
	 	{7,7,7,7,7,7,7,7,7,7},
	 	{8,8,8,8,8,8,8,8,8,8},
	 	{9,9,9,9,9,9,9,9,9,9}};

swapLines((int*)m, 10, 10, 2, 3);

for (int i=0; i< 10; i++){
  for (int j=0; j<10; j++){
   printf("%d ", m[i][j]);
  }
}
    

}