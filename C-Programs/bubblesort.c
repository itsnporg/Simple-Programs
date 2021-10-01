#include <stdio.h>

int main(){
    //declations
const int n = 10;
int temp,i=0,j=0,m=0;
int A[10] ={4,5,2,77,34,64,90,45,65,101};
    //before sorting display
printf("Before Sorting : ");
for(i=0;i<n;i++){
printf("%d ",A[i]);
}
printf("\n");
    //sorting process
for( i=0; i<(n-1); i++){
printf("pass %d : ",i+1);
for( j=0; j<(n-1-i);j++){
if ( A[j] > A[j+1]){
temp = A[j];
A[j] = A[j+1];
A[j+1]= temp;
}
}
    //printing pass while sorting
for(m=0; m<n; m++){
printf("%d ",A[m]);
}
printf("\n");
}
    //after sorting display 
printf("\nSorted array is : ");
for(i=0;i<n;i++){
printf("%d ",A[i]);
}
return 0;
}
