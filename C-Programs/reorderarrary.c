// record 1 dimension array ,integer array from smaller to larger
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 100

void recorder(int n, int x[]);

void main(){
    system("cls");
    int i,n,x[SIZE];
    printf("Numbers to enter ? \n");
    scanf("%d",&n);

    // read in the list of numbers
    for (i=0;i < n; ++i ){
        printf("i = %d x = ",i+1 );
        scanf("%d",&x[i]);
    }

    // record all array elements
    recorder(n,x);
    //display the recorded list of numbers
    printf("\n\n Recorded List of Numbers : \n\n");
    for ( i = 0; i < n; i++)
    {
        printf("i = %d x = %d \n",i+1,x[i]);
    }
}
// rearrange the list of numbers
void recorder(int n, int x[]){
    int i, item, temp;
    for (item=0; item <n-1;item++ ){
        //find the smallest number
        for (i=item+1;i<n;i++){
        if (x[i] < x[item]){
            //interchange 2 elements
            temp = x[item];
            x[item]=x[i];
            x[i]=temp;
        }
    }
    }
    return;
}