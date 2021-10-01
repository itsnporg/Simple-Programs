#include <stdio.h>               //6 using DMA
#include <stdlib.h>
void main(){
    //declations
    //assumptions const red=2,white=4,blue=6;

int temp,i=0,j=0,m=0;
const int n = 13;
int A[13] ={4,6,2,4,2,6,4,2,6,4,4,2,4};

int *ptr = malloc(sizeof(int)*n);
ptr = &A[0];
   //sorting process
for( i=0; i<(n-1); i++){
for( j=0; j<(n-1-i);j++){
if ((*(ptr+j)) > (*(ptr+1+j))){  
temp = (*(ptr+j));
(*(ptr+j)) = (*(ptr+j+1));
(*(ptr+j+1))= temp;
}
}
}

    //after sorting display 
printf("\nSorted array is : ");
for(i=0;i<n;i++){
printf("%d ",*(ptr+i));
}
free(ptr);
}
