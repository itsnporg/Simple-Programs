#include <stdio.h>

int main(){
    //declations
    // const red=2,white=4,blue=6;

int temp,i=0,j=0,m=0;
const int n = 13;
int A[13] ={4,6,2,4,2,6,4,2,6,4,4,2,4};

   //sorting process
for( i=0; i<(n-1); i++){
for( j=0; j<(n-1-i);j++){
if ( A[j] > A[j+1]){
temp = A[j];
A[j] = A[j+1];
A[j+1]= temp;
}
}
}
    //after sorting display 
printf("\nSorted array is : ");
for(i=0;i<n;i++){
printf("%d ",A[i]);
}
return 0;
}
